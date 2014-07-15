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

QString TypeOfConnection;
QString ModeOperation = " --ModeOperation=true";
QString tcp_mem_user ="";
QString tcp_mem_server = "";
QString tcp_cc = "";
QString SimuTime="";
QString udp_bw="";
QString file_size="";
QString user_bw="";
QString server_bw="";
QString error_rate="";
QString error_model="";

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
    }
/* -----------------------for iperf udp--------------------------- */
    else if (ui->tabWidget->currentIndex()==1){
        TypeOfConnection =" --TypeOfConnection=u";
        if (ui->tcp_upload_2->isChecked()==true){
            ModeOperation = " --ModeOperation=false";
        }
        udp_bw=" --udp_bw="+ui->udp_bw->text();
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
        file_size = " --htmlSize="+ui->wget_file_size->text()+"Mb";
        FinalCommand = TypeOfConnection + ModeOperation +tcp_mem_user + tcp_mem_server + tcp_cc + file_size;
    }
//concatenates all commands
    FinalCommand = FinalCommand + user_bw + server_bw + error_model + error_rate;
    ui->final_command->setText(FinalCommand);
//create new shell file
    FILE * pFile;
    pFile = fopen ("run-kupakupa.sh", "w");
       if (pFile != NULL){
            std::fstream myfile;
            myfile.open ("run-kupakupa.sh");
            myfile << "#!/bin/bash \n";
            myfile << "export KUPA_HOME=`pwd` \n";

            myfile << "cd /home/aneta/aneta-kupa/source/ns-3-dce/ \n";
            myfile << "./waf shell \n";
            myfile << "./home/aneta/aneta-kupa/source/ns-3-dce/build/myscripts/kupakupa/bin/kupakupa ";
            std::string theCommand = FinalCommand.toUtf8 ().constData ();
            myfile << theCommand <<"\n";
            //back to current folder
            myfile << "cd $KUPA_HOME";
            system ("chmod +x run-kupakupa.sh");
            myfile.close();

            }

}


void kupagui::on_button_run_clicked()
{
    system ("./run-kupakupa.sh");

}

void kupagui::on_actionLoad_Command_triggered()
{
  TiXmlDocument readdoc(":/inputDCE.xml");
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

}
