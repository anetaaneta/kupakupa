#include "kupagui.h"
#include "ui_kupagui.h"
#include "tinyxml.h"

#include <QFileDialog>
#include <QSaveFile>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <QMessageBox>

#include <QCoreApplication>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QXmlStreamReader>
#include <QDesktopServices>

QString TypeOfConnection = "";
QString ModeOperation = " --ModeOperation=true";
string theCommand;
int resultNumber;
QString tcp_mem_user ="";
QString tcp_mem_server = "";
QString tcp_cc = "";
QString SimuTime="";
QString udp_bw="";
QString file_size="";
QString error_model="";
QString user_bw="";
QString server_bw="";
QString error_rate="";
QString chan_jitter="";


using namespace std;

kupagui::kupagui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::kupagui)
{

    ui->setupUi(this);
    //loadTextFile();
}

kupagui::~kupagui()
{
    delete ui;
}

double kupagui::findDataHttp(string s){
    int a = s.find('[');
    string c = s.substr(a);
    int d = c.find('/')-1;
    c= c.substr(1,d);
    double data = atof(c.c_str());
    return data;
}
double kupagui::findSpeedHttp(string s){
    string o="";
    int a = s.find('(');
    int b = s.find(')');
    for (int i=a+1; i<b; i++){
       o += s[i];
    }
    double speed = atof(o.c_str());
    return speed;
}

double kupagui::findTime (string s){
    string o="";
    int a = s.find('-');
    int b = s.find("sec");
    for (int i=a+1; i<b; i++){
       o += s[i];
    }
    double time = atof(o.c_str());
    return time;
}
double kupagui::findData (string s){
  string o ="";
      int a = s.find("sec");
      int b = s.find("Bytes");
      for (int i=a+3; i<b; i++){
         o += s[i];
      }
      double k = atof(o.c_str());
      return k;
}
double kupagui::findDataUdp(string s){
     string o ="";
     unsigned a = s.rfind("sec");
     int b = s.find("ms");
     for (int i=a+3; i<b; i++){
        o += s[i];
     }
     double k = atof(o.c_str());
     return k;
 }


void kupagui::on_button_generate_command_clicked()
{
    QString FinalCommand = "";
    //QString TypeOfConnection = "";
    /*QString ModeOperation = " --ModeOperation=true";
    QString tcp_mem_user ="";
    QString tcp_mem_server = "";
    QString tcp_cc = "";
    QString SimuTime="";
    QString udp_bw="";
    QString file_size="";*/
    user_bw=" --user_bw="+ui->user_bw->text()+"Mbps";
    server_bw=" --server_bw="+ui->server_bw->text()+"Gbps";
    error_rate=" --errRate="+ui->error_rate->text();

    if (ui->jitter_check->isChecked ()==true){
        chan_jitter=" --chan_jitter=1";
      }else{
        chan_jitter=" --chan_jitter=0";
      }

    QString chan_alpha=" --chan_alpha="+ui->alpha_value->text();
    QString chan_tetha=" --chan_tetha="+ui->tetha_value->text ();
    QString chan_k=" --k="+ui->k_value->text ();
    //QString error_model="";
    if (ui->error_model->currentIndex()==0){
        error_model=" --ErrorModel=1"; //rate error model
    }else{
        error_model=" --ErrorModel=2"; //burst error model
    }
/* -----------------------for iperf tcp--------------------------- */
    if (ui->tabWidget->currentIndex()==0){
        TypeOfConnection =" --TypeOfConnection=p";
        if (ui->tcp_upload->isChecked()==true){
            ModeOperation = " --ModeOperation=false";
        }
        if (ui->tcp_mem_user->displayText().isEmpty() == false){
        tcp_mem_user = " --tcp_mem_user="+ui->tcp_mem_user->text();
            }
        if (ui->tcp_mem_server->displayText().isEmpty() == false){
        tcp_mem_server = " --tcp_mem_server="+ui->tcp_mem_server->text();
            }
        tcp_cc = " --tcp_cc="+ui->tcp_cc->currentText().toLower();
        SimuTime =" --SimuTime="+ui->iperf_time->text();
        FinalCommand = TypeOfConnection + ModeOperation +tcp_mem_user + tcp_mem_server + tcp_cc + SimuTime;
        resultNumber=1;
    }
/* -----------------------for iperf udp--------------------------- */
    else if (ui->tabWidget->currentIndex()==1){
        TypeOfConnection =" --TypeOfConnection=u";
        if (ui->tcp_upload_2->isChecked()==true){
            ModeOperation = " --ModeOperation=false";
        }
        udp_bw=" --udp_bw="+ui->udp_bw->text();
        FinalCommand = TypeOfConnection + ModeOperation + udp_bw;
        resultNumber=2;
    }

/* -----------------------for wget-thttpd--------------------------- */
    else if(ui->tabWidget->currentIndex()==2){
        TypeOfConnection =" --TypeOfConnection=w";
        if (ui->tcp_mem_user->displayText().isEmpty() == false){
        tcp_mem_user = " --tcp_mem_user="+ui->tcp_mem_user_2->text();
            }
        if (ui->tcp_mem_server->displayText().isEmpty() == false){
        tcp_mem_server = " --tcp_mem_server="+ui->tcp_mem_server_2->text();
            }
        tcp_cc = " --tcp_cc="+ui->tcp_cc_2->currentText().toLower();
        file_size = " --htmlSize="+ui->wget_file_size->text();
        FinalCommand = TypeOfConnection + ModeOperation +tcp_mem_user + tcp_mem_server + tcp_cc + file_size;
        resultNumber=3;
    }
//concatenates all commands
    FinalCommand = FinalCommand + user_bw + server_bw + error_model + error_rate + chan_alpha + chan_k + chan_tetha + chan_jitter;
    ui->final_command->setText(FinalCommand);
//create new shell file
    FILE * pFile;
    pFile = fopen ("shell-kupakupa.sh", "w");
       if (pFile != NULL){
            std::fstream myfile;
            myfile.open ("shell-kupakupa.sh");
            myfile << "#!/bin/bash \n";
            myfile <<"#"<<resultNumber<<"\n";
            myfile << "export KUPA_HOME=`pwd` \n";

            myfile << "cd /home/aneta/aneta-kupa/source/ns-3-dce/ \n";
            //myfile << "./waf shell \n";
            //myfile << "/home/aneta/aneta-kupa/source/ns-3-dce/build/myscripts/kupakupa/bin/kupakupa ";
            theCommand = FinalCommand.toUtf8 ().constData ();
            myfile <<"./waf --run \"kupakupa "<< theCommand <<"\"\n";
            //back to current folder
            myfile << "cd $KUPA_HOME";
            myfile.close();
            fclose (pFile);
            system("chmod +x shell-kupakupa.sh");
            }
}

string kupagui::GetStdoutFromCommand(string cmd) {

    string data;
    FILE * stream;
    const int max_buffer = 50000;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream) {
    while (!feof(stream))
    if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
    pclose(stream);
    }
    return data;
}

void kupagui::on_button_run_clicked()
{

    string ls = GetStdoutFromCommand("./shell-kupakupa.sh");
    QString qstr = QString::fromStdString(ls);
    ui->output_result->setText (qstr);
    string n = GetStdoutFromCommand ("head -n 2 shell-kupakupa.sh | tail -n 1");
    qstr = QString::fromStdString (n);
    //remove previous output
    system("rm -f ./stdout-kupa.txt");
    if (n[1]=='1' or n[1]=='2'){
        system("cat /home/aneta/aneta-kupa/source/ns-3-dce/files-0/var/log/*/stdout > ./stdout-kupa.txt");
        ui->output_result->append(qstr);
        resultNumber=n[1]-48;
      }
    else {
        system("cat /home/aneta/aneta-kupa/source/ns-3-dce/files-0/var/log/*/stderr > ./stdout-kupa.txt");
        ui->output_result->append(qstr);
        resultNumber=n[1]-48;
      }
}



void kupagui::on_actionLoad_Command_triggered()
{


  TiXmlDocument readdoc("..//..//..//inputDCE.xml");
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

          string typeOfConectionTmp,httpSizeTmp;
          string tcp_mem_user_min,tcp_mem_user_def,tcp_mem_user_max, tcp_mem_server_min,tcp_mem_server_def,tcp_mem_server_max;
          ui->output_result->setText ("XML file LOADED!!");
          for(TiXmlElement* elem = readroot->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
                  {
                  string elemName = elem->Value();
                  if (elemName=="TypeOfConnection")
                          {
                          TiXmlNode* e = elem->FirstChild();
                          TiXmlText* text = e->ToText();
                          typeOfConectionTmp = text->Value();

                          if (typeOfConectionTmp=="http")
                                  {
                                  //TypeOfConnection =" --TypeOfConnection=w";
                                  ui->tabWidget->setCurrentIndex (2);
                                  }

                          if (typeOfConectionTmp=="iperf-udp")
                                  {
                                  //TypeOfConnection =" --TypeOfConnection=u";
                                  ui->tabWidget->setCurrentIndex (1);
                                  }

                          if (typeOfConectionTmp=="iperf-tcp")
                                  {
                                  //TypeOfConnection =" --TypeOfConnection=p";
                                  ui->tabWidget->setCurrentIndex (0);
                                  }
                          }
                  if (elemName=="congestionControl")
                          {
                          TiXmlNode* e = elem->FirstChild();
                          TiXmlText* text = e->ToText();
                          tcp_cc = text->Value();
                          if (typeOfConectionTmp=="http"){
                              ui->tcp_cc_2->setCurrentText (tcp_cc);
                            }
                          if (typeOfConectionTmp=="iperf-tcp"){
                              ui->tcp_cc->setCurrentText (tcp_cc);
                            }
                          //tcp_cc = " --tcp_cc="+text->Value();

                          }
                  if (elemName=="UDPBandwidth")
                          {
                          TiXmlNode* e = elem->FirstChild();
                          TiXmlText* text = e->ToText ();
                          string udp_bwTemp = text->Value ();
                          //udp_bw = " --udp_bw="+text->Value();
                          ui->udp_bw->setValue (atoi(udp_bwTemp.c_str ()));
                          }
                  if (elemName=="Delay")
                          {
                          TiXmlNode* e = elem->FirstChild();
                          TiXmlText* text = e->ToText();
                          string d = text->Value ();
                          string v = d.erase (d.find ('m'),2);
                          //delay = " --delay="+text->Value()+"ms";
                          ui->delay->setValue (atoi (v.c_str ()));
                          }
                  if (elemName=="ErrorRate")
                          {
                          TiXmlNode* e = elem->FirstChild();
                          TiXmlText* text = e->ToText();
                          string errRateTmp = text->Value();
                          double errRate = atof(errRateTmp.c_str());
                          //error_rate=" --errRate="+errRateTmp;
                          ui->error_rate->setValue(errRate);
                          }
                  if (elemName=="JitterParam")
                          {
                          string jitterTmp = elem->Attribute("jitter");
                          if (jitterTmp=="false"){
                          //jitter=0;
                          ui->jitter_check->setChecked (false);
                          }
                  else{
                          //jitter=1;
                          ui->jitter_check->setChecked (true);
                          }
                  string alphaTmp = elem->Attribute("alpha");
                  double alpha=atof(alphaTmp.c_str());
                  ui->alpha_value->setValue (alpha);

                  string kTmp= elem->Attribute("k");
                  double k=atof(kTmp.c_str());
                  ui->k_value->setValue (k);

                  string tethaTmp = elem->Attribute("tetha");
                  double tetha=atof(tethaTmp.c_str());
                  ui->tetha_value->setValue (tetha);
                  }

          if (elemName=="UserBandwidth")
                  {
                  TiXmlNode* e = elem->FirstChild();
                  TiXmlText* text = e->ToText();
                  std::string user_bw = text->Value();
                  std::string v = user_bw.erase (user_bw.find ('M'),4);
                  ui->user_bw->setValue (atoi(v.c_str ()));
          if (elemName=="ServerBandwidth")
                  {
                  TiXmlNode* e = elem->FirstChild();
                  TiXmlText* text = e->ToText();
                  std::string server_bw = text->Value();
                  string v = user_bw.erase (server_bw.find ('G'),4);
                  ui->server_bw->setValue (atoi(v.c_str ()));

                  }
          if (elemName=="ErrorModel")
                  {
                  TiXmlNode* e = elem->FirstChild();
                  TiXmlText* text = e->ToText();
                  string ErrorModelTmp=text->Value();
                  //ErrorModel = atoi(ErrorModelTmp.c_str());
                  if (ErrorModelTmp=="1"){
                      ui->error_model->setCurrentIndex (0);
                    } else {
                      ui->error_model->setCurrentIndex (1);
                    }
                  }
          if (elemName=="SizeOfHttpFile")
                  {
                  TiXmlNode* e = elem->FirstChild();
                  TiXmlText* text = e->ToText();
                  std::string httpSizeTmp = text->Value();
                  int htmlSize=atoi(httpSizeTmp.c_str());
                  ui->wget_file_size->setValue (htmlSize);
                  }
          if (elemName=="UserMemory")
                  {
                  tcp_mem_user_min = elem->Attribute("min");
                  tcp_mem_user_def = elem->Attribute("default");
                  tcp_mem_user_max = elem->Attribute("max");

                  QString qtcp_mem_user_min = QString::fromStdString (tcp_mem_user_min);
                  QString qtcp_mem_user_def = QString::fromStdString (tcp_mem_user_def);
                  QString qtcp_mem_user_max = QString::fromStdString (tcp_mem_user_max);

                  if (typeOfConectionTmp=="http")
                          {
                          ui->tcp_mem_user_2->setText (qtcp_mem_user_min+" "+qtcp_mem_user_def+ " "+qtcp_mem_user_max);
                          }
                  if (typeOfConectionTmp=="iperf-tcp")
                          {
                           ui->tcp_mem_user->setText (qtcp_mem_user_min+" "+qtcp_mem_user_def+ " "+qtcp_mem_user_max);
                          }
                  }
          if (elemName=="ServerMemory")
                  {
                  tcp_mem_server_min = elem->Attribute("min");
                  tcp_mem_server_def = elem->Attribute("default");
                  tcp_mem_server_max = elem->Attribute("max");

                  QString qtcp_mem_server_min = QString::fromStdString (tcp_mem_server_min);
                  QString qtcp_mem_server_def = QString::fromStdString (tcp_mem_server_def);
                  QString qtcp_mem_server_max = QString::fromStdString (tcp_mem_server_max);

                  if (typeOfConectionTmp=="http")
                          {
                          ui->tcp_mem_server_2->setText (qtcp_mem_server_min+" "+qtcp_mem_server_def+ " "+qtcp_mem_server_max);
                          }
                  if (typeOfConectionTmp=="iperf-tcp")
                          {
                           ui->tcp_mem_server->setText (qtcp_mem_server_min+" "+qtcp_mem_server_def+ " "+qtcp_mem_server_max);
                          }

                  }
          }
  on_button_generate_command_clicked ();
  statusBar()->showMessage(tr("Xml loaded"));
  }
}


void kupagui::on_button_getResult_clicked()
{

  //n = n[5];
  string n = GetStdoutFromCommand ("tail -n 1 ./stdout-kupa.txt");
  QString q  = QString::fromStdString (n);
    if (resultNumber==1){
        ui->output_result->toPlainText ();
        ui->output_result->setText ("the last command run is tcp connection\n and the last line outputfile is "+q+"\n");
        //calculate throughput
        double tcp_time = findTime (n);
        double tcp_data = findData (n);
        double tcp_tp = tcp_data/tcp_time;
        QString tp = QString::number (tcp_tp);
        ui->output_result->append ("throughput is");
        ui->output_result->append (tp);
        if (n[n.find ("Bytes")-1] =='K'){
            ui->output_result->append ("KBps");
          }
        else if (n[n.find ("Bytes")-1] =='M'){
            ui->output_result->append ("MBps");
          }
        else if (n[n.find ("Bytes")-1]=='G'){
            ui->output_result->append ("GBps");
          }
        else{
            ui->output_result->append ("Bps");
          }

      }
    else if (resultNumber==2){
        ui->output_result->toPlainText ();
        ui->output_result->setText ("the last command run is udp connection and the last line outputfile is "+q);
        n = GetStdoutFromCommand ("tail -n 2 ./stdout-kupa.txt | head -n 1");
        double udp_data = findDataUdp(n);
        QString jitter = QString::number (udp_data);
        ui->output_result->append ("measured jitter is");
        ui->output_result->append (jitter);
        ui->output_result->append ("ms");
      }
    else if (resultNumber==3){
        ui->output_result->toPlainText ();
        ui->output_result->setText ("the last command run is http connection and the last line outputfile is "+q);
        n = GetStdoutFromCommand ("tail -n 5 ./stdout-kupa.txt | head -n 1");
        double http_data = findDataHttp (n);
        double http_speed = findSpeedHttp (n);
        double http_time = http_data/http_speed;
        if (n[n.find('s')-3]=='K'){
            http_time = http_time/1000;
            QString ht = QString::number (http_time);
            ui->output_result->append ("measured http time is");
            ui->output_result->append (ht);
          }
        else if (n[n.find('s')-3]=='M'){
            http_time = http_time/1000000;
            QString ht = QString::number (http_time);
            ui->output_result->append ("measured http time is");
            ui->output_result->append (ht);
          }
        else if (n[n.find('s')-3]=='G'){
            http_time = http_time/1000000000;
            QString ht = QString::number (http_time);
            ui->output_result->append ("measured http time is");
            ui->output_result->append (ht);
          }
        else {
            QString ht = QString::number (http_time);
            ui->output_result->append ("measured http time is");
            ui->output_result->append (ht);
          }
        ui->output_result->append ("ms");
      }
    else {
        ui->output_result->toPlainText ();
        ui->output_result->setText ("this is unknown connection. Please run the generated command first!!");
      }
}


void kupagui::on_actionRUN_triggered()
{
    on_button_run_clicked ();
}

void kupagui::on_actionSave_Result_triggered()
{
     QString fileName = QFileDialog::getSaveFileName (ui->output_result, tr("Save file"), "./kupakuparesult.txt",
                                                      tr("Text Files (*.txt)"));
     if (fileName != "") {
                  QFile file(fileName);
                  if (!file.open(QIODevice::WriteOnly)) {
                      // error message
                  } else {
                      QTextStream stream(&file);
                      stream << ui->output_result->toPlainText();
                      stream.flush();
                      file.close();
                  }
              }

}

void kupagui::on_actionEdit_XML_triggered()
{
  system("gedit /home/aneta/aneta-kupa/source/ns-3-dce/inputDCE.xml");
}


void kupagui::on_actionAbout_triggered()
{
  QMessageBox msgBox;
  msgBox.setText("<h2>kupakupa-GUI</h2>");
  msgBox.setInformativeText("<p>Author: Kae Won Choi, Ewaldo Zihan, Aneta"
            "<p>kaewon.choi@gmail.com"
            "<p>zewaldo88@gmail.com"
            "<p>dragon21century@gmail.com"
            "<p>this is application tu run ns-3-dce simulation of iperf and wget with jitter"
            "enjoy :)");
  msgBox.setStandardButtons(QMessageBox::Ok);
  msgBox.exec();
}

void kupagui::on_actionSave_Command_triggered()
{
  QString type;
  QString congestion;
  int server_param_min;
  int server_param_def;
  int server_param_max;
  int user_param_min;
  int user_param_def;
  int user_param_max;
  string server_param;
  string user_param;

  QString filename = QFileDialog::getSaveFileName(this,
                                         tr("Save Xml"), ".",
                                         tr("Xml files (*.xml)"));

  QFile file(filename);
  file.open(QIODevice::WriteOnly);

  QXmlStreamWriter xmlWriter(&file);
  xmlWriter.setAutoFormatting(true);
  xmlWriter.writeStartDocument();

  xmlWriter.writeStartElement("SimulationParameters");

  if (ui->tabWidget->currentIndex ()==0){
      type="iperf-tcp";
      congestion=ui->tcp_cc->currentText ().toLower ();
      server_param = ui->tcp_mem_server->text ().toUtf8 ().constData ();
      user_param = ui->tcp_mem_user->text ().toUtf8 ().constData ();
    } else if (ui->tabWidget->currentIndex ()==1){
      type="iperf-udp";
    } else {
      type="http";
      congestion = ui->tcp_cc_2->currentText ().toLower ();
      server_param = ui->tcp_mem_server_2->text ().toUtf8 ().constData ();
      user_param = ui->tcp_mem_user_2->text ().toUtf8 ().constData ();
    }



  xmlWriter.writeTextElement("typeOfConnection", type);
  xmlWriter.writeTextElement("congestionControl", congestion);
  xmlWriter.writeTextElement("UDPBandwidth", ui->udp_bw->text ());
  xmlWriter.writeTextElement ("Delay", ui->delay->text()+"ms");
  xmlWriter.writeTextElement("ErrorRate",ui->error_rate->text());
  xmlWriter.writeTextElement("Errormodel",QString::number(ui->error_model->currentIndex ()+1));
  xmlWriter.writeTextElement("SizeOfHttpFile", ui->wget_file_size->text());
  xmlWriter.writeTextElement("UserBandwidth", ui->user_bw->text ());
  xmlWriter.writeTextElement("ServerBandwidth",ui->server_bw->text ());;

  xmlWriter.writeStartElement("JitterParam");
  xmlWriter.writeAttribute("jitter",ui->jitter_check->isChecked ()?"false":"true");
  xmlWriter.writeAttribute("alpha",ui->alpha_value->text ());
  xmlWriter.writeAttribute("k",ui->k_value->text ());
  xmlWriter.writeAttribute("tetha",ui->tetha_value->text ());
  //xmlWriter.writeCharacters ("jitter");
  xmlWriter.writeEndElement();

  if (ui->tabWidget->currentIndex ()==0 or ui->tabWidget->currentIndex ()==2){
      server_param = RemoveComma(server_param);
      user_param = RemoveComma (user_param);

      std::size_t first, second;
      first=0;second=0;
      first = server_param.find(' ');
        if (first!=std::string::npos){
          server_param_min=atoi(server_param.substr (0,first).c_str ());
          }
      second = server_param.find(' ', first+2);
        if (second!=std::string::npos){
          server_param_def=atoi(server_param.substr (first, second-first).c_str ());
          server_param_max = atoi(server_param.substr (second).c_str ());
          }
      //reset first and second to get min def max value of tcp_mem_user
      first = 0; second = 0;
      first = user_param.find(' ');
          if (first!=std::string::npos){
            user_param_min=atoi(user_param.substr (0,first).c_str ());
            }
      second = user_param.find(' ', first+2);
          if (second!=std::string::npos){
            user_param_def=atoi(user_param.substr (first, second-first).c_str ());
            user_param_max = atoi(user_param.substr (second).c_str ());
            }

    xmlWriter.writeStartElement("UserMemory");
    xmlWriter.writeAttribute("min",QString::number (user_param_min));
    xmlWriter.writeAttribute("def",QString::number (user_param_def));
    xmlWriter.writeAttribute("max",QString::number (user_param_max));
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("ServerMemory");
    xmlWriter.writeAttribute("min",QString::number (server_param_min));
    xmlWriter.writeAttribute("def",QString::number (server_param_def));
    xmlWriter.writeAttribute("max",QString::number (server_param_max));
    xmlWriter.writeEndElement();
    }

  xmlWriter.writeEndElement();
  xmlWriter.writeEndElement();
  xmlWriter.writeEndDocument();

  file.close();
  statusBar()->showMessage(tr("Xml Saved"));
}

string kupagui::RemoveComma (std::string& str)
{
int i = 0;
std::cout<<"remove comma from "<< str << std::endl;
std::string str2=str;
for (i=0; i<3; i++)
{
	std::size_t found=str.find(',');
	if (found!=std::string::npos)
	{
	str2 = str.replace(str.find(','),1," ");
	} else {
	std::cout<<"no comma found..";
	}
}
std::cout<<str2;
return str2;
}
