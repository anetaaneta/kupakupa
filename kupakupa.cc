
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/dce-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/internet-module.h"
#include <string>
#include <sstream>

using namespace ns3;
using namespace std;
NS_LOG_COMPONENT_DEFINE ("kupakupa");

string IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}

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
	std::string tcp_cc = "reno";
	std::string tcp_rmem_user_min = "4096";
	std::string tcp_rmem_user_def = "8192";
	std::string tcp_rmem_user_max = "8388608";
	std::string tcp_rmem_server_min = "4096";
	std::string tcp_rmem_server_def = "8192";
	std::string tcp_rmem_server_max = "8388608";

	std::string tcp_wmem_user_min = "4096";
	std::string tcp_wmem_user_def = "8192";
	std::string tcp_wmem_user_max = "8388608";
	std::string tcp_wmem_server_min = "4096";
	std::string tcp_wmem_server_def = "8192";
	std::string tcp_wmem_server_max = "8388608";
	std::string udp_bw="1m";
	std::string delay = "2ms";
	//char ErrorModel = 'r';
	int SimuTime = 20;

	cmd.AddValue ("tcp_cc", "TCP congestion control algorithm. Default is reno. Other options: bic, cubic, diag, highspeed, htcp, hybla, illinois, lp, probe scalable vegas, veno, westwood, yeah", tcp_cc);
	cmd.AddValue ("tcp_rmem_user_min", "put minimal values for tcp_rmem in user, range 4096-8388608", tcp_rmem_user_min);
	cmd.AddValue ("tcp_rmem_user_def", "put default values for tcp_rmem in user, range 4096-8388608", tcp_rmem_user_def);
	cmd.AddValue ("tcp_rmem_user_max", "put maximum values for tcp_rmem in user, range 4096-8388608", tcp_rmem_user_max);
	cmd.AddValue ("tcp_rmem_server_min", "put minimal values for tcp_rmem in server, range 4096-8388608", tcp_rmem_server_min);
	cmd.AddValue ("tcp_rmem_server_def", "put default values for tcp_rmem in server, range 4096-8388608", tcp_rmem_server_def);
	cmd.AddValue ("tcp_rmem_server_max", "put maximum values for tcp_rmem in server, range 4096-8388608", tcp_rmem_server_max);

	cmd.AddValue ("tcp_wmem_user_min", "put minimal values for tcp_wmem in user, range 4096-8388608", tcp_wmem_user_min);
	cmd.AddValue ("tcp_wmem_user_def", "put default values for tcp_wmem in user, range 4096-8388608", tcp_wmem_user_def);
	cmd.AddValue ("tcp_wmem_user_max", "put maximum values for tcp_wmem in user, range 4096-8388608", tcp_wmem_user_max);
	cmd.AddValue ("tcp_wmem_server_min", "put minimal values for tcp_wmem in server, range 4096-8388608", tcp_wmem_server_min);
	cmd.AddValue ("tcp_wmem_server_def", "put default values for tcp_wmem in server, range 4096-8388608", tcp_wmem_server_def);
	cmd.AddValue ("tcp_wmem_server_max", "put maximum values for tcp_wmem in server, range 4096-8388608", tcp_wmem_server_max);

	cmd.AddValue ("delay", "Delay.", delay);
	cmd.AddValue ("errRate", "Error rate.", errRate);
	//cmd.AddValue ("error_model", "Choose error model you want to use. options: r -rate error model-default, b -burst error model and l -list error model", ErrorModel);
	cmd.AddValue ("udp_bw","banwidth set for UDP, default is 1M", udp_bw);
    cmd.AddValue ("SimuTime", "time to do the simulaton, in second", SimuTime);
        std::string IperfTime = IntToString(SimuTime);
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
    stack.SysctlSet (c.Get(0), ".net.ipv4.tcp_rmem", tcp_rmem_user_min+" "+tcp_rmem_user_def+" "+tcp_rmem_user_max);
        stack.SysctlSet (c.Get(2), ".net.ipv4.tcp_rmem", tcp_rmem_server_min+" "+tcp_rmem_server_def+" "+tcp_rmem_server_max);

	stack.SysctlSet (c.Get(0), ".net.ipv4.tcp_wmem", tcp_wmem_user_min+" "+tcp_wmem_user_def+" "+tcp_wmem_user_max);
	stack.SysctlSet (c.Get(2), ".net.ipv4.tcp_wmem", tcp_wmem_server_min+" "+tcp_wmem_server_def+" "+tcp_wmem_server_max);

    stack.SysctlSet (c.Get(0), ".net.core.rmem_max", tcp_rmem_user_max);
    stack.SysctlSet (c.Get(0), ".net.core.wmem_max", tcp_wmem_user_max);

        stack.SysctlSet (c.Get(2), ".net.core.rmem_max", tcp_rmem_server_max);
    stack.SysctlSet (c.Get(2), ".net.core.wmem_max", tcp_wmem_server_max);

        stack.SysctlSet (c, ".net.ipv4.tcp_congestion_control", tcp_cc);
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

//error model options
        /*switch (ErrorModel)
    {
    case 'r':
    case 'b':
    case 'l':
      break;
    default:
      std::cout << "Unknown error_model : " << ErrorModel << " ?" << std::endl;
      return (ErrorModel);
    }*/

        Ptr<RateErrorModel> err = CreateObjectWithAttributes<RateErrorModel> (
                                                        "RanVar", StringValue ("ns3::UniformRandomVariable[Min=0.0,Max=1.0]"),
                                                        "ErrorRate", DoubleValue (errRate),
                            "ErrorUnit", EnumValue (RateErrorModel::ERROR_UNIT_PACKET)
                            );

        /*switch (ErrorModel)
    {
    case 'r':
                {
                Ptr<RateErrorModel> err = CreateObjectWithAttributes<RateErrorModel> (
                                                        "RanVar", StringValue ("ns3::UniformRandomVariable[Min=0.0,Max=1.0]"),
                                                        "ErrorRate", DoubleValue (errRate),
                            "ErrorUnit", EnumValue (RateErrorModel::ERROR_UNIT_PACKET)
                            );
                }
        break;
    case 'b':
                {
                Ptr<BurstErrorModel> err = CreateObjectWithAttributes<BurstErrorModel> (
                                                        "BurstSize", StringValue ("ns3::UniformRandomVariable[Min=1,Max=4]"),
                                                        "BurstStart", StringValue ("ns3::UniformRandomVariable[Min=0.0|Max=1.0]"),
                            "ErrorRate", DoubleValue (errRate)
                            );
                }
        break;
        case 'l':
                {
                std::list<uint32_t> sampleList;
                sampleList.push_back (10);
                sampleList.push_back (17);
                sampleList.push_back (19);
                sampleList.push_back (80);
                // This time, we'll explicitly create the error model we want
                Ptr<ListErrorModel> err = CreateObject<ListErrorModel> ();
                err->SetList (sampleList);
                }
        break;
    }*/


	//d0d1.Get (1)->SetAttribute ("ReceiveErrorModel", PointerValue (em));

	p2p.SetDeviceAttribute ("DataRate", StringValue ("1Gbps"));
	p2p.SetChannelAttribute ("Delay", StringValue (delay));
	NetDeviceContainer d1d2 = p2p.Install (n1n2);
	//d0d1.Get (1)->SetAttribute ("ReceiveErrorModel", PointerValue (em));

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
	int EndTime = SimuTime+10;

  switch (TypeOfConnection)
    {
    case 'p':
      {
                if (ModeOperation)
                {
                        d1d2.Get(0)-> SetAttribute ("ReceiveErrorModel", PointerValue (err));
            // Launch iperf server on node 0
            dce.SetBinary ("iperf");
            dce.ResetArguments ();
            dce.ResetEnvironment ();
            dce.AddArgument ("-s");
            dce.AddArgument ("-P");
            dce.AddArgument ("1");
            ApplicationContainer SerApps0 = dce.Install (c.Get (0));
            SerApps0.Start (Seconds (1));
            SerApps0.Stop (Seconds (EndTime));

            // Launch iperf client on node 2
            dce.SetBinary ("iperf");
            dce.ResetArguments ();
            dce.ResetEnvironment ();
            dce.AddArgument ("-c");
            dce.AddArgument ("10.1.1.1");
            dce.AddArgument ("-i");
            dce.AddArgument ("1");
            dce.AddArgument ("--time");
            dce.AddArgument (IperfTime);
            ApplicationContainer ClientApps0 = dce.Install (c.Get (2));
            ClientApps0.Start (Seconds (1));
            ClientApps0.Stop (Seconds (EndTime));
        }
                else
                        {
                                d1d2.Get(1)-> SetAttribute ("ReceiveErrorModel", PointerValue (err));
                // Launch iperf server on node 2
                dce.SetBinary ("iperf");
                dce.ResetArguments ();
                dce.ResetEnvironment ();
                dce.AddArgument ("-s");
                dce.AddArgument ("-P");
                dce.AddArgument ("1");
                ApplicationContainer SerApps0 = dce.Install (c.Get (2));
                SerApps0.Start (Seconds (1));
                SerApps0.Stop (Seconds (EndTime));

                // Launch iperf client on node 0
                dce.SetBinary ("iperf");
                dce.ResetArguments ();
                dce.ResetEnvironment ();
                dce.AddArgument ("-c");
                dce.AddArgument ("10.1.2.2");
                dce.AddArgument ("-i");
                dce.AddArgument ("1");
                dce.AddArgument ("--time");
                dce.AddArgument (IperfTime);
                ApplicationContainer ClientApps0 = dce.Install (c.Get (0));
                ClientApps0.Start (Seconds (1));
                ClientApps0.Stop (Seconds (EndTime));
                        }
        }
      break;

    case 'u':
      {
                if (ModeOperation)
                {
                        d1d2.Get(0)-> SetAttribute ("ReceiveErrorModel", PointerValue (err));
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
            SerApps0.Stop (Seconds (EndTime));

            // Launch iperf client on node 2
            dce.SetBinary ("iperf");
            dce.ResetArguments ();
            dce.ResetEnvironment ();
            dce.AddArgument ("-c");
            dce.AddArgument ("-u");
            dce.AddArgument ("10.1.1.1");
            dce.AddArgument ("-i");
            dce.AddArgument ("1");
                        dce.AddArgument ("-b");
                        dce.AddArgument (udp_bw);
            dce.AddArgument ("--time");
            dce.AddArgument (IperfTime);
            ApplicationContainer ClientApps0 = dce.Install (c.Get (2));
            ClientApps0.Start (Seconds (1));
            ClientApps0.Stop (Seconds (EndTime));
        }
                else
                        {
                        d1d2.Get(1)-> SetAttribute ("ReceiveErrorModel", PointerValue (err));
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
            SerApps0.Stop (Seconds (EndTime));

            // Launch iperf client on node 2
            dce.SetBinary ("iperf");
            dce.ResetArguments ();
            dce.ResetEnvironment ();
            dce.AddArgument ("-c");
            dce.AddArgument ("-u");
            dce.AddArgument ("10.1.2.2");
            dce.AddArgument ("-i");
            dce.AddArgument ("1");
                        dce.AddArgument ("-b");
                        dce.AddArgument (udp_bw);
            dce.AddArgument ("--time");
            dce.AddArgument (IperfTime);
            ApplicationContainer ClientApps0 = dce.Install (c.Get (0));
            ClientApps0.Start (Seconds (1));
            ClientApps0.Stop (Seconds (EndTime));
                        }
                }
      break;

    case 'w':
      {
      ModeOperation=true;
                        d1d2.Get(0)-> SetAttribute ("ReceiveErrorModel", PointerValue (err));
            ApplicationContainer SerApps2 = dce.Install (c.Get (2));
            SerApps2.Start (Seconds (1));
            SerApps2.Stop (Seconds (SimuTime));
            dce.SetBinary ("thttpd");
            dce.ResetArguments ();
            dce.ResetEnvironment ();
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
            dce.AddArgument (IperfTime);
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

	LinuxStackHelper::SysctlGet (c.Get (2), Seconds (1),
								".net.ipv4.tcp_available_congestion_control", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (2), Seconds (1),
                                                                ".net.ipv4.tcp_congestion_control", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (2), Seconds (1),
                                                                ".net.ipv4.tcp_rmem", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (2), Seconds (1),
                                                                ".net.ipv4.tcp_wmem", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (2), Seconds (1),
                                                                ".net.core.rmem_max", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (2), Seconds (1),
                                                                ".net.core.wmem_max", &PrintTcpFlags);


    AsciiTraceHelper ascii;
    p2p.EnableAsciiAll (ascii.CreateFileStream ("Kupakupa.tr"));
    p2p.EnablePcapAll ("kupakupa");
    NS_LOG_INFO ("Run Simulation.");
    std::cout << "simulation will take about "<< (SimuTime) <<"seconds." << std::endl;


    Simulator::Stop (Seconds (EndTime));
    Simulator::Run ();
    Simulator::Destroy ();
    NS_LOG_INFO ("Done.");

  return 0;
}
