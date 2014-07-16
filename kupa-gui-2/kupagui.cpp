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

QString TypeOfConnection = "";
string theCommand;
int resultNumber;

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
    QString ModeOperation = " --ModeOperation=true";
    QString tcp_mem_user ="";
    QString tcp_mem_server = "";
    QString tcp_cc = "";
    QString SimuTime="";
    QString udp_bw="";
    QString file_size="";
    QString user_bw=" --user_bw="+ui->user_bw->text()+"Mbps";
    QString server_bw=" --server_bw="+ui->server_bw->text()+"Gbps";
    QString error_rate=" --errRate="+ui->error_rate->text();
    QString error_model="";
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
    FinalCommand = FinalCommand + user_bw + server_bw + error_model + error_rate;
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
  /*TiXmlDocument readdoc("inputDCE.xml");
  bool loadOkay = readdoc.LoadFile();
  if(!loadOkay)
  {
          std::cerr << readdoc.ErrorDesc(); //<< endl;
  }
  TiXmlElement* readroot = readdoc.FirstChildElement();
  if(readroot == NULL)
  {
         std::cerr << "Failed to load file: No root element.";
                   //<< endl;
          readdoc.Clear();
  }
  //int ErrorModel;
  QString typeOfConection,tcp_cc,udp_bw,delay,httpSize, tcp_mem_user, tcp_mem_server;
  QString tcp_mem_user_min,tcp_mem_user_def,tcp_mem_user_max, tcp_mem_server_min,tcp_mem_server_def,tcp_mem_server_max;
  for(TiXmlElement* elem = readroot->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
  {
  std::string elemName = elem->Value();
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
                  std::string ErrorModel=text->Value();
          }
          if (elemName=="SizeOfHttpFile")
          {
                  TiXmlNode* e = elem->FirstChild();
                  TiXmlText* text = e->ToText();
                  httpSize = text->Value();
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
  */
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
