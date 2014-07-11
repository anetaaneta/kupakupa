#include <iostream>
#include <string>

#include <string>
#include <sstream>
#include <map>
#include "generate-html-file.h"
#include "tinyxml.h"

typedef std::map<std::string,std::string> MessageMap;
using namespace std;

int main () {
TiXmlDocument readdoc("inputDCE.xml");
	bool loadOkay = readdoc.LoadFile();
	if(!loadOkay)
	{
		cerr << readdoc.ErrorDesc() << endl;
	}
	TiXmlElement* readroot = readdoc.FirstChildElement();
	if(readroot == NULL)
	{
		cerr << "Failed to load file: No root element."
			 << endl;
		readdoc.Clear();
	}
	int ErrorModel;
	string typeOfConection,tcp_cc,udp_bw,delay,httpSize;
	string tcp_rmem_min,tcp_rmem_def,tcp_rmem_max, tcp_wmem_min,tcp_wmem_def,tcp_wmem_max;
	for(TiXmlElement* elem = readroot->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
	{
    string elemName = elem->Value();
		if (elemName=="TypeOfConnection")
		{
			TiXmlNode* e = elem->FirstChild();
			TiXmlText* text = e->ToText();
			typeOfConection = text->Value();
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
		if (elemName=="ErrorModel")
		{
			TiXmlNode* e = elem->FirstChild();
			TiXmlText* text = e->ToText();
			string errorModelS=text->Value();
			ErrorModel=atoi(errorModelS.c_str());
		}
		if (elemName=="SizeOfHttpFile")
		{
			TiXmlNode* e = elem->FirstChild();
			TiXmlText* text = e->ToText();
			httpSize = text->Value();
		}
		if (elemName=="ReadMemory")
		{
			tcp_rmem_min = elem->Attribute("min");
			tcp_rmem_def = elem->Attribute("default");
			tcp_rmem_max = elem->Attribute("max");
		}
		if (elemName=="WriteMemory")
		{
			tcp_wmem_min = elem->Attribute("min");
			tcp_wmem_def = elem->Attribute("default");
			tcp_wmem_max = elem->Attribute("max");
		}

	}
}
