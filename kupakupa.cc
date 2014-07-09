
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

//function to turn interger to string for iperf input
string IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}

//fungtion to get the last value in tcp_mem for tcp_mem_max
string SplitLastValue (const std::string& str)
{
  std::cout << "Splitting: " << str << '\n';
  unsigned found = str.find_last_of(" ");
  ostringstream temp;
  temp << str.substr(found+1);
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
	std::string tcp_mem_user = "4096 8192 8388608";
	std::string tcp_mem_server = "4096 8192 8388608";

	std::string udp_bw="1m";
	std::string delay = "2ms";
	std::string user_bw = "150Mbps";
	std::string server_bw = "10Gbps";

        int ErrorModel = 1;
        int SimuTime = 20;

	cmd.AddValue ("tcp_cc", "TCP congestion control algorithm. Default is reno. Other options: bic, cubic, diag, highspeed, htcp, hybla, illinois, lp, probe, scalable, vegas, veno, westwood, yeah", tcp_cc);
	cmd.AddValue ("tcp_mem_user", "put 3 values (min, default, max) separaed by comma for tcp_mem in user, range 4096-16000000", tcp_mem_user);
	cmd.AddValue ("tcp_mem_server", "put 3 values (min, default, max) separaed by comma for tcp_mem in server, range 4096-54000000", tcp_mem_server);
	cmd.AddValue ("user_bw", "bandwidth between user and BS, in Mbps. Default is 150", user_bw);
	cmd.AddValue ("server_bw", "bandwidth between server and BS, in Gbps. Default is 10", server_bw);

	cmd.AddValue ("delay", "Delay.", delay);
	cmd.AddValue ("errRate", "Error rate.", errRate);
	cmd.AddValue ("ErrorModel", "Choose error model you want to use. options: 1 -rate error model-default, 2 - burst error model", ErrorModel);
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
        //setting memory size for user and server
#ifdef KERNEL_STACK
    dceManager.SetNetworkStack ("ns3::LinuxSocketFdFactory", "Library", StringValue ("liblinux.so"));
    LinuxStackHelper stack;
    stack.Install (c);
    dceManager.Install (c);

	//assume coma has been removed
	std::string tcp_mem_user_max = SplitLastValue(tcp_mem_user);
	std::string tcp_mem_server_max = SplitLastValue(tcp_mem_server);

        stack.SysctlSet (c.Get(0), ".net.ipv4.tcp_wmem", tcp_mem_user);
    stack.SysctlSet (c.Get(0), ".net.ipv4.tcp_rmem", tcp_mem_user);
    stack.SysctlSet (c.Get(2), ".net.ipv4.tcp_wmem", tcp_mem_server);
        stack.SysctlSet (c.Get(2), ".net.ipv4.tcp_rmem", tcp_mem_server);

    stack.SysctlSet (c.Get(0), ".net.core.rmem_max", tcp_mem_user_max);
    stack.SysctlSet (c.Get(0), ".net.core.wmem_max", tcp_mem_user_max);

    stack.SysctlSet (c.Get(2), ".net.core.rmem_max", tcp_mem_server_max);
    stack.SysctlSet (c.Get(2), ".net.core.wmem_max", tcp_mem_server_max);

    stack.SysctlSet (c, ".net.ipv4.tcp_congestion_control", tcp_cc);
#else
    NS_LOG_ERROR ("Linux kernel stack for DCE is not available. build with dce-linux module.");
    //silently exit
    return 0;
#endif

    std::cout << "setting link.." << std::endl;
// channel for user to BS
	NS_LOG_INFO ("Create channels.");
	PointToPointHelper p2p;
	p2p.SetDeviceAttribute ("DataRate", StringValue (user_bw));
	p2p.SetChannelAttribute ("Delay", StringValue ("0ms"));
	NetDeviceContainer d0d1 = p2p.Install (n0n1);
//channel for server to BS
	p2p.SetDeviceAttribute ("DataRate", StringValue (server_bw));
	p2p.SetChannelAttribute ("Delay", StringValue (delay));
	NetDeviceContainer d1d2 = p2p.Install (n1n2);

//error model options

	/*strangely, if em is not set at the begining, it doesn't want to compile.
	therefore, i just put it here as a default object and to make sure it can
	be build properly*/
	std::cout << "the error model is "<< ErrorModel <<std::endl;
	Ptr<RateErrorModel> em = CreateObjectWithAttributes<RateErrorModel> (
			    "RanVar", StringValue ("ns3::UniformRandomVariable[Min=0.0,Max=1.0]"),
			    "ErrorRate", DoubleValue (errRate),
			    "ErrorUnit", EnumValue (RateErrorModel::ERROR_UNIT_PACKET)
			    );
	std::cout << "building error model..." <<std::endl;

	if (ErrorModel == 1)
	{
		std::cout << "the error model is Rate Error Model"<<std::endl;
		Ptr<RateErrorModel> em = CreateObjectWithAttributes<RateErrorModel> (
			    "RanVar", StringValue ("ns3::UniformRandomVariable[Min=0.0,Max=1.0]"),
			    "ErrorRate", DoubleValue (errRate),
			    "ErrorUnit", EnumValue (RateErrorModel::ERROR_UNIT_PACKET)
			    );
		std::cout << "building error model completed" <<std::endl;
	}
	else if (ErrorModel==2)
	{
		std::cout << "the error model is Burst Error Model" <<std::endl;
		Ptr<BurstErrorModel> em = CreateObjectWithAttributes<BurstErrorModel> (
			    "BurstSize", StringValue ("ns3::UniformRandomVariable[Min=1,Max=4]"),
			    "BurstStart", StringValue ("ns3::UniformRandomVariable[Min=0.0|Max=1.0]"),
			    "ErrorRate", DoubleValue (errRate)
			    );
		std::cout << "building error model completed" <<std::endl;
	}
	else
	{
		//this will not change the error model
		std::cout << "Unknown error model. Restore to default: rate error model" <<std::endl;
	}



// IP Address
    NS_LOG_INFO ("Assign IP Addresses.");
    std::cout << "setting Ip addresses" << std::endl;
    Ipv4AddressHelper ipv4;
    //for client and BS net devices
        ipv4.SetBase ("10.1.1.0", "255.255.255.0");
    Ipv4InterfaceContainer i0i1 = ipv4.Assign (d0d1);
        //for server and BS devices
        ipv4.SetBase ("10.1.2.0", "255.255.255.0");
        Ipv4InterfaceContainer i1i2 = ipv4.Assign (d1d2);

// Create router nodes, initialize routing database and set up the routing tables in the nodes.
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
            d1d2.Get(0)-> SetAttribute ("ReceiveErrorModel", PointerValue (em));
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
                        dce.AddArgument (">");
                        dce.AddArgument ("/temp/iperf-download-result");
            ApplicationContainer ClientApps0 = dce.Install (c.Get (2));
            ClientApps0.Start (Seconds (1));
            ClientApps0.Stop (Seconds (EndTime));
        }
            else
            {
                                d1d2.Get(1)-> SetAttribute ("ReceiveErrorModel", PointerValue (em));
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
        d1d2.Get(0)-> SetAttribute ("ReceiveErrorModel", PointerValue (em));
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
             d1d2.Get(1)-> SetAttribute ("ReceiveErrorModel", PointerValue (em));
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
        d1d2.Get(0)-> SetAttribute ("ReceiveErrorModel", PointerValue (em));
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
            d1d2.Get(0)-> SetAttribute ("ReceiveErrorModel", PointerValue (em));
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
    //LinuxStackHelper::SysctlGet (c.Get (0), Seconds (1.0),".net.ipv4.tcp_available_congestion_control", &PrintTcpFlags);
        LinuxStackHelper::SysctlGet (c.Get (0), Seconds (1),".net.ipv4.tcp_congestion_control", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (0), Seconds (1),".net.ipv4.tcp_congestion_control", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (0), Seconds (1),".net.ipv4.tcp_rmem", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (0), Seconds (1),".net.ipv4.tcp_wmem", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (0), Seconds (1),".net.core.rmem_max", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (0), Seconds (1),".net.core.wmem_max", &PrintTcpFlags);

        //LinuxStackHelper::SysctlGet (c.Get (2), Seconds (1),".net.ipv4.tcp_available_congestion_control", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (2), Seconds (1),".net.ipv4.tcp_congestion_control", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (2), Seconds (1),".net.ipv4.tcp_rmem", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (2), Seconds (1),".net.ipv4.tcp_wmem", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (2), Seconds (1),".net.core.rmem_max", &PrintTcpFlags);
    LinuxStackHelper::SysctlGet (c.Get (2), Seconds (1),".net.core.wmem_max", &PrintTcpFlags);


    AsciiTraceHelper ascii;
    p2p.EnableAsciiAll (ascii.CreateFileStream ("Kupakupa.tr"));
    p2p.EnablePcapAll ("kupakupa");
    NS_LOG_INFO ("Run Simulation.");
    std::cout << "simulation will take about "<< (SimuTime) <<"seconds." << std::endl;


    Simulator::Stop (Seconds (EndTime));
    
    FlowMonitorHelper flowmon;
    Ptr<FlowMonitor> monitor = flowmon.InstallAll();
    
    Simulator::Run ();
    monitor->CheckForLostPackets ();
    Ptr<Ipv4FlowClassifier> classifier = DynamicCast<Ipv4FlowClassifier> (flowmon.GetClassifier ());
    std::map<FlowId, FlowMonitor::FlowStats> stats = monitor->GetFlowStats ();
    
    Time firstSend1,firstSend2;
    Time lastReceived1,lastReceived2;
    int64_t avJitter1,avJitter2;
    
    for (std::map<FlowId, FlowMonitor::FlowStats>::const_iterator iter = stats.begin (); iter != stats.end (); ++iter)
    {
    	Ipv4FlowClassifier::FiveTuple t = classifier->FindFlow (iter->first);
    	
    	// 1 direction flow
    	if (t.sourceAddress == Ipv4Address("10.1.1.1") && t.destinationAddress == Ipv4Address("10.1.2.2"))
    	{
    	  int64_t no=iter->second.rxPackets;
	  Time sumJitter1=iter->second.jitterSum;
	  avJitter1= sumJitter1.GetInteger()/no;
	  firstSend1= iter->second.timeFirstTxPacket;
	  lastReceived1=iter->second.timeLastRxPacket;
	  
    		if (TypeOfConnection=='u')
    		{
    			int64_t no=iter->second.rxPackets;
    			Time sumJitter1=iter->second.jitterSum;
    			int64_t avJitter1= sumJitter1.GetInteger()/no;
    		}
    		if (TypeOfConnection=='w') // calculate download time
    		{
    			
    		}
    	}
    	// second direction flow
    	if (t.sourceAddress == Ipv4Address("10.1.2.2") && t.destinationAddress == Ipv4Address("10.1.1.1"))
    	{
          int64_t no=iter->second.rxPackets;
	  Time sumJitter2=iter->second.jitterSum;
	  avJitter2= sumJitter2.GetInteger()/no;
	  firstSend2= iter->second.timeFirstTxPacket;
	  lastReceived2=iter->second.timeLastRxPacket;
    	}
    	
    }
    
    if (TypeOfConnection=='u')
    {
    	// calculate average jitter;
  	Time avJitter = Time((avJitter2+avJitter1)/2);
  	avJitter.GetMilliSeconds();
    }
    if (TypeOfConnection=='w')
    {
    	// calucalte elapseTime
  	Time firstSend = (firstSend1 < firstSend2 ? firstSend1:firstSend2);
  	Time lastReceived = (lastReceived1 > lastReceived2 ? lastReceived1:lastReceived2);
  	Time elapseTime = lastReceived-firstSend;
  	elapseTime.GetSeconds();
    }
    monitor->SerializeToXmlFile ("results.xml",true,true);
    Simulator::Destroy ();
    NS_LOG_INFO ("Done.");

	//get the iperf result

  return 0;
}
