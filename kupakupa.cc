#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/dce-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/csma-module.h"
#include "ns3/wifi-module.h"
#include "ns3/mobility-module.h"
#include "ns3/internet-module.h"
//#include "point-to-point-channel.h"

using namespace ns3;
NS_LOG_COMPONENT_DEFINE ("kupakupa");


static void RunIp (Ptr<Node> node, Time at, std::string str)
{
  DceApplicationHelper process;
  ApplicationContainer apps;
  process.SetBinary ("ip");
  process.SetStackSize (1 << 16);
  process.ResetArguments ();
  process.ParseArguments (str.c_str ());
  apps = process.Install (node);
  apps.Start (at);
}

void
PrintTcpFlags (std::string key, std::string value)
{
  NS_LOG_INFO (key << "=" << value);
}

int main (int argc, char *argv[])
{
	CommandLine cmd;
	char TypeOfConnection = 'p'; // iperf tcp connection
	bool ModeOperation = true;
    //int ServerBW = 10;
	cmd.AddValue ("TypeOfConnection", "Link type: p for iperf-tcp, u for iperf-udp and w for wget-thttpd, default to iperf-tcp", TypeOfConnection);
    cmd.AddValue ("ModeOperation", "If true it's download mode for UE, else will do upload. http will always do download", ModeOperation);

	/*just in case if user use uppercase*/
	TypeOfConnection = tolower (TypeOfConnection);
  switch (TypeOfConnection)
    {
    case 'u': //iperf udp connection
    case 'w': //thttpd - wget connection, always in download mode
      break;
    default:
      std::cout << "Unknown link type : " << TypeOfConnection << " ?" << std::endl;
      //return 1;
    }
	
	double errRate = 0.01;

    //cmd.AddValue ("tcpcc", "TCP congestion control algorith.", tcp_cc);
    //cmd.AddValue ("linkDelay", "Link delay of the right link (p2p from BS to server).", rlink_delay);
	
	std::string minBufSize = "4096";
	std::string defBufSize = "4096";
	std::string maxBufSize = "8388608";
	std::string delay = "2ms";
    int SimuTime = 20;
	
	cmd.AddValue ("mibbuffer", "Buffer Size.", minBufSize);
	cmd.AddValue ("defbuffer", "Buffer Size.", defBufSize);
	cmd.AddValue ("maxbuffer", "Buffer Size.", maxBufSize);
	cmd.AddValue ("delay", "Delay.", delay);
	cmd.AddValue ("errRate", "Error rate.", errRate);
    cmd.AddValue ("SimuTime", "Error rate.", SimuTime);
	cmd.Parse (argc, argv);

// topologies
    std::cout << "building topologies.." << std::endl;
	NS_LOG_INFO ("Create nodes.");
	NodeContainer c;
	c.Create (3);
	NodeContainer n0n1 = NodeContainer (c.Get (0), c.Get (1));
	NodeContainer n1n2 = NodeContainer (c.Get (1), c.Get (2));
	
	DceManagerHelper dceManager;

    std::cout << "setting memory size.." << std::endl;
#ifdef KERNEL_STACK
    dceManager.SetNetworkStack ("ns3::LinuxSocketFdFactory", "Library", StringValue ("liblinux.so"));
    LinuxStackHelper stack;
    stack.Install (c);
    dceManager.Install (c);
    stack.SysctlSet (c, ".net.ipv4.tcp_rmem", minBufSize+" "+defBufSize+" "+maxBufSize);
    stack.SysctlSet (c, ".net.ipv4.tcp_wmem", minBufSize+" "+defBufSize+" "+maxBufSize);
    stack.SysctlSet (c, ".net.core.rmem_max", defBufSize);
    stack.SysctlSet (c, ".net.core.wmem_max", defBufSize);
      
#else
    NS_LOG_ERROR ("Linux kernel stack for DCE is not available. build with dce-linux module.");
    //silently exit
    return 0;
#endif
   
    std::cout << "setting link.." << std::endl;
// channel
	NS_LOG_INFO ("Create channels.");
	PointToPointHelper p2p;
	p2p.SetDeviceAttribute ("DataRate", StringValue ("150Mbps"));
	p2p.SetChannelAttribute ("Delay", StringValue ("0ms"));
	NetDeviceContainer d0d1 = p2p.Install (n0n1);
	Ptr<RateErrorModel> em = CreateObjectWithAttributes<RateErrorModel> (
   							 "RanVar", StringValue ("ns3::UniformRandomVariable[Min=0.0,Max=1.0]"),
                                                         "ErrorRate", DoubleValue (errRate),
                                                         "ErrorUnit", EnumValue (RateErrorModel::ERROR_UNIT_PACKET)
                                                         );
	d0d1.Get (1)->SetAttribute ("ReceiveErrorModel", PointerValue (em));


	p2p.SetDeviceAttribute ("DataRate", StringValue ("1Gbps"));
	p2p.SetChannelAttribute ("Delay", StringValue (delay));
	NetDeviceContainer d1d2 = p2p.Install (n1n2);
	d0d1.Get (1)->SetAttribute ("ReceiveErrorModel", PointerValue (em));
	
// IP Address
	NS_LOG_INFO ("Assign IP Addresses.");
    std::cout << "setting Ip addresses" << std::endl;
	Ipv4AddressHelper ipv4;
	ipv4.SetBase ("10.1.1.0", "255.255.255.0");
	Ipv4InterfaceContainer i0i1 = ipv4.Assign (d0d1);
	
	ipv4.SetBase ("10.1.2.0", "255.255.255.0");
	Ipv4InterfaceContainer i1i2 = ipv4.Assign (d1d2);

// Create router nodes, initialize routing database and set up the routing
// tables in the nodes.
    std::cout << "creating simple routing table" << std::endl;
	Ipv4GlobalRoutingHelper::PopulateRoutingTables ();
#ifdef KERNEL_STACK
	LinuxStackHelper::PopulateRoutingTables ();
#endif


// Application
	NS_LOG_INFO ("Create Applications.");
    std::cout << "creating applications.." << std::endl;
	DceApplicationHelper dce;
	
	dce.SetStackSize (1 << 20);
		

  switch (TypeOfConnection)
    {
    case 'p':
      {
		if (ModeOperation)
		{
            // Launch iperf server on node 0
            dce.SetBinary ("iperf");
            dce.ResetArguments ();
            dce.ResetEnvironment ();
            dce.AddArgument ("-s");
            dce.AddArgument ("-P");
            dce.AddArgument ("1");
            ApplicationContainer SerApps0 = dce.Install (c.Get (0));
            SerApps0.Start (Seconds (1));
            SerApps0.Stop (Seconds (SimuTime));

            // Launch iperf client on node 2
            dce.SetBinary ("iperf");
            dce.ResetArguments ();
            dce.ResetEnvironment ();
            dce.AddArgument ("-c");
            dce.AddArgument ("10.1.1.1");
            dce.AddArgument ("-i");
            dce.AddArgument ("1");
            dce.AddArgument ("--time");
            dce.AddArgument ("10");
            ApplicationContainer ClientApps0 = dce.Install (c.Get (2));
            ClientApps0.Start (Seconds (1));
            ClientApps0.Stop (Seconds (SimuTime));
        }
		else
			{
                // Launch iperf server on node 2
                dce.SetBinary ("iperf");
                dce.ResetArguments ();
                dce.ResetEnvironment ();
                dce.AddArgument ("-s");
                dce.AddArgument ("-P");
                dce.AddArgument ("1");
                ApplicationContainer SerApps0 = dce.Install (c.Get (2));
                SerApps0.Start (Seconds (1));
                SerApps0.Stop (Seconds (SimuTime));

                // Launch iperf client on node 0
                dce.SetBinary ("iperf");
                dce.ResetArguments ();
                dce.ResetEnvironment ();
                dce.AddArgument ("-c");
                dce.AddArgument ("10.1.2.2");
                dce.AddArgument ("-i");
                dce.AddArgument ("1");
                dce.AddArgument ("--time");
                dce.AddArgument ("10");
                ApplicationContainer ClientApps0 = dce.Install (c.Get (0));
                ClientApps0.Start (Seconds (1));
                ClientApps0.Stop (Seconds (SimuTime));
			}
        }
      break;

    case 'u':
      {
		if (ModeOperation)
		{
            // Launch iperf udp server on node 0
            dce.SetBinary ("iperf");
            dce.ResetArguments ();
            dce.ResetEnvironment ();
            dce.AddArgument ("-s");
            dce.AddArgument ("-u");
            dce.AddArgument ("-P");
            dce.AddArgument ("1");
            ApplicationContainer SerApps0 = dce.Install (c.Get (0));
            SerApps0.Start (Seconds (1));
            SerApps0.Stop (Seconds (SimuTime));

            // Launch iperf client on node 2
            dce.SetBinary ("iperf");
            dce.ResetArguments ();
            dce.ResetEnvironment ();
            dce.AddArgument ("-c");
            dce.AddArgument ("-u");
            dce.AddArgument ("10.1.1.1");
            dce.AddArgument ("-i");
            dce.AddArgument ("1");
            dce.AddArgument ("--time");
            dce.AddArgument ("10");
            ApplicationContainer ClientApps0 = dce.Install (c.Get (2));
            ClientApps0.Start (Seconds (1));
            ClientApps0.Stop (Seconds (SimuTime));
        }
		else
			{
            // Launch iperf udp server on node 0
            dce.SetBinary ("iperf");
            dce.ResetArguments ();
            dce.ResetEnvironment ();
            dce.AddArgument ("-s");
            dce.AddArgument ("-u");
            dce.AddArgument ("-P");
            dce.AddArgument ("1");
            ApplicationContainer SerApps0 = dce.Install (c.Get (2));
            SerApps0.Start (Seconds (1));
            SerApps0.Stop (Seconds (SimuTime));

            // Launch iperf client on node 2
            dce.SetBinary ("iperf");
            dce.ResetArguments ();
            dce.ResetEnvironment ();
            dce.AddArgument ("-c");
            dce.AddArgument ("-u");
            dce.AddArgument ("10.1.2.2");
            dce.AddArgument ("-i");
            dce.AddArgument ("1");
            dce.AddArgument ("--time");
            dce.AddArgument ("10");
            ApplicationContainer ClientApps0 = dce.Install (c.Get (0));
            ClientApps0.Start (Seconds (1));
            ClientApps0.Stop (Seconds (SimuTime));
			}
		}
      break;

    case 'w':
      {
      ModeOperation=true;

            dce.SetBinary ("iperf");
            dce.ResetArguments ();
            dce.ResetEnvironment ();
            dce.AddArgument ("-s");
            dce.AddArgument ("-P");
            dce.AddArgument ("1");
            ApplicationContainer SerApps2 = dce.Install (c.Get (2));
            SerApps2.Start (Seconds (1));
            SerApps2.Stop (Seconds (SimuTime));
            dce.SetBinary ("thttpd");
            dce.ResetArguments ();
            dce.ResetEnvironment ();
             //  dce.AddArgument ("-D");
            dce.SetUid (1);
            dce.SetEuid (1);
            ApplicationContainer serHttp = dce.Install (c.Get (2));
            serHttp.Start (Seconds (1));


            dce.SetBinary ("wget");
            dce.ResetArguments ();
            dce.ResetEnvironment ();
            dce.AddArgument ("-r");
            dce.AddArgument ("http://10.1.2.2/index.html");
            ApplicationContainer clientHttp = dce.Install (c.Get (0));
            clientHttp.Start (Seconds (1));
        }
      break;

    default:
        {
                // Launch iperf server on node 0
                dce.SetBinary ("iperf");
                dce.ResetArguments ();
                dce.ResetEnvironment ();
                dce.AddArgument ("-s");
                dce.AddArgument ("-P");
                dce.AddArgument ("1");
                ApplicationContainer SerApps0 = dce.Install (c.Get (0));
                SerApps0.Start (Seconds (1));
                SerApps0.Stop (Seconds (SimuTime));

                // Launch iperf client on node 2
                dce.SetBinary ("iperf");
                dce.ResetArguments ();
                dce.ResetEnvironment ();
                dce.AddArgument ("-c");
                dce.AddArgument ("10.1.1.1");
                dce.AddArgument ("-i");
                dce.AddArgument ("1");
                dce.AddArgument ("--time");
                dce.AddArgument ("10");
                ApplicationContainer ClientApps0 = dce.Install (c.Get (2));
                ClientApps0.Start (Seconds (1));
                ClientApps0.Stop (Seconds (SimuTime));
         }
      break;
    }

    for (int n = 0; n < 3; n++)
    {
      RunIp (c.Get (n), Seconds (0.2), "link show");
      RunIp (c.Get (n), Seconds (0.3), "route show table all");
      RunIp (c.Get (n), Seconds (0.4), "addr list");
    }

  // print tcp sysctl value
    LinuxStackHelper::SysctlGet (c.Get (0), Seconds (1.0),
								".net.ipv4.tcp_available_congestion_control", &PrintTcpFlags);
    //LinuxStackHelper::SysctlGet (c.Get (0), NanoSeconds (0),
	//							".net.core.netdev_max_backlog", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (0), Seconds (1),
								".net.ipv4.tcp_congestion_control", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (0), Seconds (1),
								".net.ipv4.tcp_rmem", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (0), Seconds (1),
								".net.ipv4.tcp_wmem", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (0), Seconds (1),
								".net.core.rmem_max", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (0), Seconds (1),
								".net.core.wmem_max", &PrintTcpFlags);


    AsciiTraceHelper ascii;
    p2p.EnableAsciiAll (ascii.CreateFileStream ("Kupakupa.tr"));
    p2p.EnablePcapAll ("kupakupa");
    NS_LOG_INFO ("Run Simulation.");

  Simulator::Stop (Seconds (100.0));
  Simulator::Run ();
  Simulator::Destroy ();
  NS_LOG_INFO ("Done.");

  return 0;
}
