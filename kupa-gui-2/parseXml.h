#include <string>
namespace std {
class ParseInput
{

public :


void
parseInputXml(string fileName,char& TypeOfConnection, string& tcp_cc, string& udp_bw, double& SimuTime,bool& downloadMode, double& errRate, double& errRate2, int& jitter,double& k, double& pdv, double& avg_delay,int& ErrorModel,int& ErrorModel2,string& user_bw, string& server_bw, int& htmlSize,string& tcp_mem_user, string& tcp_mem_user_wmem, string& tcp_mem_user_rmem, string& tcp_mem_server, string& tcp_mem_server_wmem, string& tcp_mem_server_rmem);

string
GetLowerCase(string stringName);

};
}
