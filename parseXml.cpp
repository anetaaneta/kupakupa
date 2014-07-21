#include "tinyxml.h"
#include "parseXml.h"
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <algorithm>

namespace std {

string
ParseInput::GetLowerCase(string stringName) {
std::transform(stringName.begin(), stringName.end(), stringName.begin(), ::tolower);
return stringName;

}

void
ParseInput::parseInputXml(string fileName,char& TypeOfConnection, string& tcp_cc, string& udp_bw, string& delay,int& SimuTime,bool& ModeOperation, double& errRate, int& jitter, double& alpha,double& k,double& tetha,int& ErrorModel,string& user_bw, string& server_bw, int& htmlSize,string& tcp_mem_user, string& tcp_mem_server){
   

TiXmlDocument readdoc(fileName.c_str());
bool loadOkay = readdoc.LoadFile();
if(!loadOkay)
{
cerr << readdoc.ErrorDesc() << endl;
}
TiXmlElement* readroot = readdoc.FirstChildElement();
if(readroot == NULL)
{
cerr << "Failed to load file: No root element."<< endl;
readdoc.Clear();
}

       string typeOfConectionTmp,httpSizeTmp,modeOperTmp,simuTimeTmp;
string tcp_mem_user_min,tcp_mem_user_def,tcp_mem_user_max, tcp_mem_server_min,tcp_mem_server_def,tcp_mem_server_max;
for(TiXmlElement* elem = readroot->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
{
string elemName = elem->Value();
if (elemName=="TypeOfConnection")
{
TiXmlNode* e = elem->FirstChild();
TiXmlText* text = e->ToText();
typeOfConectionTmp = text->Value();

if (GetLowerCase(typeOfConectionTmp)=="http")
{
TypeOfConnection ='w';
}

if (GetLowerCase(typeOfConectionTmp)=="iperf-udp")
{
TypeOfConnection ='u';
}

if (GetLowerCase(typeOfConectionTmp)=="iperf-tcp")
{

TypeOfConnection ='p';
}
}
if (elemName=="congestionControl")
{
TiXmlNode* e = elem->FirstChild();
TiXmlText* text = e->ToText();
tcp_cc = text->Value();
}
if (elemName=="UDPBandwidth")
{
TiXmlNode* e = elem->FirstChild();
TiXmlText* text = e->ToText();
udp_bw = text->Value();

}

if (elemName=="Delay")
{
TiXmlNode* e = elem->FirstChild();
TiXmlText* text = e->ToText();
delay = text->Value();
}

if (elemName=="SimulationTime")
{
TiXmlNode* e = elem->FirstChild();
TiXmlText* text = e->ToText();
simuTimeTmp = text->Value();
SimuTime=atoi(simuTimeTmp.c_str());
}

       if (elemName=="ModeOperation")
{
TiXmlNode* e = elem->FirstChild();
TiXmlText* text = e->ToText();
modeOperTmp = text->Value();
if (GetLowerCase(modeOperTmp)=="download") {
ModeOperation = true;
}
if (GetLowerCase(modeOperTmp)=="upload") {
ModeOperation = false;
}
}



if (elemName=="ErrorRate")
{
TiXmlNode* e = elem->FirstChild();
TiXmlText* text = e->ToText();
string errRateTmp = text->Value();
errRate = atof(errRateTmp.c_str());
}
if (elemName=="JitterParam")
{
string jitterTmp = elem->Attribute("jitter");
if (GetLowerCase(jitterTmp)=="false"){
  jitter=0;
}
else{
  jitter=1;
}
string alphaTmp = elem->Attribute("alpha");
alpha=atof(alphaTmp.c_str());
string kTmp= elem->Attribute("k");
k=atof(kTmp.c_str());
string tethaTmp = elem->Attribute("tetha");
tetha=atof(tethaTmp.c_str());
}

if (elemName=="UserBandwidth")
{
TiXmlNode* e = elem->FirstChild();
TiXmlText* text = e->ToText();
user_bw = text->Value();
}
if (elemName=="ServerBandwidth")
{
TiXmlNode* e = elem->FirstChild();
TiXmlText* text = e->ToText();
server_bw = text->Value();
}
if (elemName=="ErrorModel")
{
TiXmlNode* e = elem->FirstChild();
TiXmlText* text = e->ToText();
string ErrorModelTmp=text->Value();
ErrorModel = atoi(ErrorModelTmp.c_str());
}
if (elemName=="SizeOfHttpFile")
{
TiXmlNode* e = elem->FirstChild();
TiXmlText* text = e->ToText();
httpSizeTmp = text->Value();
htmlSize=atoi(httpSizeTmp.c_str());
}
if (elemName=="UserMemory")
{
tcp_mem_user_min = elem->Attribute("min");
tcp_mem_user_def = elem->Attribute("default");
tcp_mem_user_max = elem->Attribute("max");
}
if (elemName=="ServerMemory")
{
tcp_mem_server_min = elem->Attribute("min");
tcp_mem_server_def = elem->Attribute("default");
tcp_mem_server_max = elem->Attribute("max");
}


}
tcp_mem_user = tcp_mem_user_min + ","+tcp_mem_user_def+","+tcp_mem_user_max;
tcp_mem_server = tcp_mem_server_min + ","+tcp_mem_server_def+","+tcp_mem_server_max;

     
     
}
}
