#include "kupagui.h"
#include "ui_kupagui.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QSaveFile>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <QMessageBox>

QString TypeOfConnection;
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
        file_size = " --file_size="+ui->wget_file_size->text();
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
            myfile.close();
            system ("chmod +x run-kupakupa.sh");
            }

}

void kupagui::on_button_run_clicked()
{
  system ("cat /home/aneta/aneta-kupa/source/ns-3-dce/files-0/var/log/*/stdout >> /home/aneta/aneta-kupa/source/ns-3-dce/myscripts/kupakupa/output.txt");
  //std::string connectionType = TypeOfConnection.toUtf8 ().constData ();
  QChar k = 'u';
  ui->output_result->insertPlainText (TypeOfConnection);
  if (k == 'p'){
      ui->output_result->insertPlainText ("TypeOfConnection is tcp");
    }
  else if (k=='u'){
      ui->output_result->insertPlainText ("TypeOfConnection is udp");
    }
  else {
      ui->output_result->insertPlainText ("TypeOfConnection is wget");
    }
  system ("./run-kupakupa.sh");
}

void kupagui::on_actionLoad_Command_triggered()
{
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
              tr("XML Files (*.xml)"));

      if (!fileName.isEmpty()) {
          QFile file(fileName);
          if (!file.open(QIODevice::ReadOnly)) {
              QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
              return;
          }
          /*QTextStream in(&file);
          ui->output_result->setText(in.readAll());
          file.close();
          }*/

      xmlFile = new QFile(file);
              if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
                      QMessageBox::critical(this,"Load XML File Problem",
                      "Couldn't open xmlfile.xml to load settings for download",
                      QMessageBox::Ok);
                      return;
              }
      xmlReader = new QXmlStreamReader(xmlFile);


      //Parse the XML until we reach end of it
      while(!xmlReader->atEnd() && !xmlReader->hasError()) {
              // Read next element
              QXmlStreamReader::TokenType token = xmlReader->readNext();
              //If token is just StartDocument - go to next
              if(token == QXmlStreamReader::StartDocument) {
                      continue;
              }
              //If token is StartElement - read it
              if(token == QXmlStreamReader::StartElement) {

                      if(xmlReader->name() == "name") {

                          continue;
                      }

                      if(xmlReader->name() == "id") {
                          qDebug() << xmlReader->readElementText();
                      }
              }
      }

      if(xmlReader->hasError()) {
              QMessageBox::critical(this,
              "xmlFile.xml Parse Error",xmlReader->errorString(),
              QMessageBox::Ok);
              return;
      }

      //close reader and flush file
      xmlReader->clear();
      xmlFile->close();
        }
}
