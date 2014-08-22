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
#include <QDateTime>

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
string dce_source;

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

void kupagui::printCalcThroughPut(double throughput){
    if (throughput < 0.1)
    {
        throughput=throughput*1000; // in Byte/Sec
        QString calTp = QString::number (throughput);
        ui->output_result->append ("\n Calculated throughput is ");
        ui->output_result->append (calTp);
        ui->output_result->append (" Bps");
    }
    if (throughput <= 100)
    {
        QString calTp = QString::number (throughput);
        ui->output_result->append ("\n Calculated throughput is ");
        ui->output_result->append (calTp);
        ui->output_result->append (" kBps");
    }

    if (throughput > 100)
    {
        throughput=throughput/1000; // in MByte/Sec
        QString calTp = QString::number (throughput);
        ui->output_result->append ("\n Calculated throughput is ");
        ui->output_result->append (calTp);
        ui->output_result->append (" MBps");
    }

    if (throughput > 100000)
    {
        throughput=throughput/1000000; // in GByte/Sec

        QString calTp = QString::number (throughput);
        ui->output_result->append ("\n Calculated throughput is ");
        ui->output_result->append (calTp);
        ui->output_result->append (" GBps");
    }

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

    dce_source = ui->dce_source->text ().toUtf8 ().constData ();

    //if (ui->jitter_check->isChecked ()==true){
        chan_jitter=" --chan_jitter=1";
      /*}else{
        chan_jitter=" --chan_jitter=0";
      }*/

    QString chan_alpha=" --chan_alpha="+ui->alpha_value->text();
    QString chan_theta=" --chan_theta="+ui->theta_value->text ();
    QString chan_k=" --chan_k="+ui->k_value->text ();
    //QString error_model="";
    if (ui->error_model->currentIndex()==0){
        error_model=" --ErrorModel=1"; //rate error model
    }else{
        error_model=" --ErrorModel=2"; //burst error model
    }

    int min, def, max;
    std::size_t first, second;
    first=0;second=0;
    string mem_user, mem_server;

/* -----------------------for iperf tcp--------------------------- */
    if (ui->tabWidget->currentIndex()==0){
        TypeOfConnection =" --TypeOfConnection=p";
        if (ui->tcp_upload->isChecked()==true){
            ModeOperation = " --ModeOperation=false";
        }
        if (ui->tcp_mem_user->displayText().isEmpty() == false){
        mem_user = ui->tcp_mem_user->text ().toUtf8 ().constData ();
        mem_user = RemoveComma (mem_user);

        first = mem_user.find(' ');
          if (first!=std::string::npos){
            min=atoi(mem_user.substr (0,first).c_str ());
            }
        second = mem_user.find(' ', first+2);
          if (second!=std::string::npos){
            def=atoi(mem_user.substr (first, second-first).c_str ());
            max= atoi(mem_user.substr (second).c_str ());
            }
        tcp_mem_user=" --tcp_mem_user="+QString::number (min)+","+QString::number (def)+","+QString::number (max);
            }
        if (ui->tcp_mem_server->displayText().isEmpty() == false){
            mem_server = ui->tcp_mem_server->text ().toUtf8 ().constData ();
            mem_server = RemoveComma (mem_server);

            first = mem_server.find(' ');
              if (first!=std::string::npos){
                min=atoi(mem_server.substr (0,first).c_str ());
                }
            second = mem_server.find(' ', first+2);
              if (second!=std::string::npos){
                def=atoi(mem_server.substr (first, second-first).c_str ());
                max= atoi(mem_server.substr (second).c_str ());
                }
            tcp_mem_server=" --tcp_mem_server="+QString::number (min)+","+QString::number (def)+","+QString::number (max);
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
        SimuTime =" --SimuTime="+ui->iperf_time_2->text();
        FinalCommand = TypeOfConnection + ModeOperation + udp_bw;
        resultNumber=2;
    }

/* -----------------------for wget-thttpd--------------------------- */
    else if(ui->tabWidget->currentIndex()==2){
        TypeOfConnection =" --TypeOfConnection=w";

        if (ui->tcp_mem_user_2->displayText().isEmpty() == false){
        mem_user = ui->tcp_mem_user_2->text ().toUtf8 ().constData ();
        mem_user = RemoveComma (mem_user);

        first = mem_user.find(' ');
          if (first!=std::string::npos){
            min=atoi(mem_user.substr (0,first).c_str ());
            }
        second = mem_user.find(' ', first+1);
          if (second!=std::string::npos){
            def=atoi(mem_user.substr (first, second-first).c_str ());
            max= atoi(mem_user.substr (second).c_str ());
            }
        tcp_mem_user=" --tcp_mem_user="+QString::number (min)+","+QString::number (def)+","+QString::number (max);
            }
        if (ui->tcp_mem_server_2->displayText().isEmpty() == false){
            mem_server = ui->tcp_mem_server_2->text ().toUtf8 ().constData ();
            mem_server = RemoveComma (mem_server);

            first = mem_server.find(' ');
              if (first!=std::string::npos){
                min=atoi(mem_server.substr (0,first).c_str ());
                }
            second = mem_server.find(' ', first+1);
              if (second!=std::string::npos){
                def=atoi(mem_server.substr (first, second-first).c_str ());
                max= atoi(mem_server.substr (second).c_str ());
                }
            tcp_mem_server=" --tcp_mem_server="+QString::number (min)+","+QString::number (def)+","+QString::number (max);
            }

        tcp_cc = " --tcp_cc="+ui->tcp_cc_2->currentText().toLower();
        file_size = " --htmlSize="+ui->wget_file_size->text();
        FinalCommand = TypeOfConnection + ModeOperation +tcp_mem_user + tcp_mem_server + tcp_cc + file_size;
        resultNumber=3;
    }
//concatenates all commands
    FinalCommand = FinalCommand + user_bw + server_bw + error_model + error_rate + chan_alpha + chan_k + chan_theta + chan_jitter;
    ui->final_command->setText(FinalCommand);
    statusBar()->showMessage(tr("command created"));
    theCommand = FinalCommand.toUtf8 ().constData ();
//create new shell file
    dce_source = ui->dce_source->text ().toUtf8 ().constData ();
    FILE * pFile;
    pFile = fopen ("shell-kupakupa.sh", "w");
       if (pFile != NULL){
            std::fstream myfile;
            myfile.open ("shell-kupakupa.sh");
            myfile << "#!/bin/bash \n";
            myfile <<"#"<<resultNumber<<"\n";
            myfile << "export KUPA_HOME=`pwd` \n";

            //myfile << "cd "+dce_source+" \n";

            /*this one will not work and never will. because it create new shell inside a shell.
            the command after waf shell will not be axecuted, it's considered on different shell environment.*/
            //myfile << "./waf shell \n";
            myfile <<dce_source<<"/build/myscripts/kupakupa/bin/kupakupa "+theCommand+"\n";

            //myfile <<"./waf --run \"kupakupa "<< theCommand <<"\"\n";
            //back to current folder
            //myfile << "cd $KUPA_HOME";
            myfile.close();
            fclose (pFile);
            system("chmod +x shell-kupakupa.sh");
            }
       statusBar()->showMessage(tr("shell file created"));
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
    dce_source = ui->dce_source->text ().toUtf8 ().constData ();
    string ls = GetStdoutFromCommand("./shell-kupakupa.sh");
    QString qstr = QString::fromStdString(ls);
    ui->output_result->setText (qstr);
    string n = GetStdoutFromCommand ("head -n 2 shell-kupakupa.sh | tail -n 1");
    qstr = QString::fromStdString (n);
    //remove previous output
    system("rm -f ./stdout-kupa.txt");
    statusBar()->showMessage(tr("simulation is done"));
    if (n[1]=='1' or n[1]=='2'){
        GetStdoutFromCommand ("cat "+dce_source+"/files-0/var/log/*/stdout > ./stdout-kupa.txt");
        ui->output_result->append(qstr);
        resultNumber=n[1]-48;
      }
    else {
        GetStdoutFromCommand ("cat "+dce_source+"/files-0/var/log/*/stderr > ./stdout-kupa.txt");
        ui->output_result->append(qstr);
        resultNumber=n[1]-48;
      }
}



void kupagui::on_actionLoad_Command_triggered()
{
  dce_source = ui->dce_source->text ().toUtf8 ().constData ();
  const QString source = QString::fromStdString (dce_source);
  QString filename = QFileDialog::getOpenFileName(this,
                                 tr("Open Xml"), source+"/inputDCE.xml",
                                 tr("Xml files (*.xml)"));

  QFile file(filename);
          if (!file.open(QFile::ReadOnly | QFile::Text))
  {
      std::cerr << "Error: Cannot read file " << qPrintable(filename)
                << ": " << qPrintable(file.errorString())
                << std::endl;

  }

  /*QXmlStreamReader Rxml;
  Rxml.setDevice(&file);
  Rxml.readNext();*/

  TiXmlDocument readdoc(filename.toUtf8 ().constData ());
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
                  if (elemName=="ModeOperation")
                          {
                          std::locale loc;
                          TiXmlNode* e = elem->FirstChild();
                          TiXmlText* text = e->ToText();
                          string modeOperTmp = text->Value();
                          if (modeOperTmp=="download") {
                            //ModeOperation = true;
                            if (typeOfConectionTmp=="http"){
                                ui->tcp_download_2->setChecked (true);
                              } else {
                                ui->tcp_download->setChecked (true);
                              }
                            }
                          if (modeOperTmp=="upload") {
                            //ModeOperation = false;
                            if (typeOfConectionTmp=="http"){
                                ui->tcp_upload_2->setChecked (true);
                              } else {
                                ui->tcp_upload->setChecked (true);
                              }
                            }
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
                          //ui->jitter_check->setChecked (false);
                          }
                  else{
                          //jitter=1;
                          //ui->jitter_check->setChecked (true);
                          }
                          string alphaTmp = elem->Attribute("alpha");
                          double alpha=atof(alphaTmp.c_str());
                          ui->alpha_value->setValue (alpha);

                          string kTmp= elem->Attribute("k");
                          double k=atof(kTmp.c_str());
                          ui->k_value->setValue (k);

                          string thetaTmp = elem->Attribute("theta");
                          double theta=atof(thetaTmp.c_str());
                          ui->theta_value->setValue (theta);
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
          if (elemName=="SimuTime")
                  {
                  TiXmlNode* e = elem->FirstChild();
                  TiXmlText* text = e->ToText();
                  std::string simuTimeTmp = text->Value();
                  int simuTime=atoi(simuTimeTmp.c_str());
                  if (typeOfConectionTmp=="iperf-tcp"){
                      ui->iperf_time->setValue (simuTime);
                    }else {
                      ui->iperf_time_2->setValue (simuTime);
                    }

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
  dce_source = ui->dce_source->text ().toUtf8 ().constData ();
  double lastReceive = atof(GetStdoutFromCommand ("cat "+ dce_source+"/lastReceive.txt").c_str());
  double firstSend = atof(GetStdoutFromCommand ("cat "+ dce_source+"/firstSend.txt").c_str());
  double totalRec = atof(GetStdoutFromCommand ("cat "+ dce_source+"/recTotal.txt").c_str());

  double throughput= (totalRec/(lastReceive-firstSend))*1000000; // in kByte/sec



  string n = GetStdoutFromCommand ("tail -n 1 ./stdout-kupa.txt");
  QString q  = QString::fromStdString (n);
  QFile file("out.txt");
  file.open(QIODevice::ReadWrite | QIODevice::Append |QIODevice::Text);
  QTextStream out(&file);


  //get time log
  QDateTime now = QDateTime::currentDateTime();

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
        out << now.toString ()+ "\t"+tp + "\t";
        if (n[n.find ("Bytes")-1] =='K'){
            ui->output_result->append ("KBps");
            out << "KBps \t";
          }
        else if (n[n.find ("Bytes")-1] =='M'){
            ui->output_result->append ("MBps");
            out << "MBps \t";
          }
        else if (n[n.find ("Bytes")-1]=='G'){
            ui->output_result->append ("GBps");
            out << "GBps \t";
          }
        else{
            ui->output_result->append ("Bps");
            out << "Bps \t";
          }

         printCalcThroughPut(throughput);
         out << ui->error_rate->text ()+"\n";
      }
    else if (resultNumber==2){
        ui->output_result->toPlainText ();
        int r = n.size ()-2; //last chat should be size -1, but i found it should be -2. interesting..
        if (n[r]=='r'){
            //if last sentence contains "out-of-order", we get the result from a line before that
            n = GetStdoutFromCommand ("tail -n 2 ./stdout-kupa.txt | head -n 1");
          }
        ui->output_result->setText ("the last command run is udp connection and the last line outputfile is "+QString::fromStdString (n));

        double udp_data = findDataUdp(n);
        QString jitter = QString::number (udp_data);
        ui->output_result->append ("measured jitter is");
        ui->output_result->append (jitter);
        out << now.toString () + "\t"+jitter + "\t"+"ms"+"\t"+ui->alpha_value->text () + "\t" +ui->theta_value->text ()+"\t"+ui->k_value->text ()+"\n";
        ui->output_result->append ("ms");

         printCalcThroughPut(throughput);

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
            out << now.toString () + "\t"+ht + "\t";
          }
        else if (n[n.find('s')-3]=='M'){
            http_time = http_time/1000000;
            QString ht = QString::number (http_time);
            ui->output_result->append ("measured http time is");
            ui->output_result->append (ht);

            out << now.toString () + "\t"+ht + "\t";
          }
        else if (n[n.find('s')-3]=='G'){
            http_time = http_time/1000000000;
            QString ht = QString::number (http_time);
            ui->output_result->append ("measured http time is");
            ui->output_result->append (ht);
            out << now.toString () + "\t"+ht + "\t";
          }
        else {
            QString ht = QString::number (http_time);
            ui->output_result->append ("measured http time is");
            ui->output_result->append (ht);
            out << now.toString () + "\t"+ht + "\t";
          }
        ui->output_result->append ("ms");
        out << "ms \t" + ui->error_rate->text ()+"\n";

         printCalcThroughPut(throughput);
      }
    else {
        ui->output_result->toPlainText ();
        ui->output_result->setText ("this is unknown connection. Please run the generated command first!!");
      }
    file.close();
    statusBar()->showMessage(tr("result loaded"));
}


void kupagui::on_actionRUN_triggered()
{
    on_button_run_clicked ();
}

void kupagui::on_actionSave_Result_triggered()
{
  dce_source = ui->dce_source->text ().toUtf8 ().constData ();
     QString fileName = QFileDialog::getSaveFileName (ui->output_result, tr("Save file"), QString::fromStdString (dce_source)+"/kupakuparesult.txt",
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
    statusBar()->showMessage(tr("result saved"));
}

void kupagui::on_actionEdit_XML_triggered()
{
  dce_source = ui->dce_source->text ().toUtf8 ().constData ();
  GetStdoutFromCommand ("gedit "+dce_source+"/inputDCE.xml");
  statusBar()->showMessage(tr("opening external program to edit XML"));
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
  statusBar()->showMessage(tr("about page is shown"));
}

void kupagui::on_actionSave_Command_triggered()
{
  dce_source = ui->dce_source->text ().toUtf8 ().constData ();
  QString type;
  QString congestion="reno";
  int server_param_min=4096;
  int server_param_def=8192;
  int server_param_max=8388608;
  int user_param_min=4096;
  int user_param_def=8192;
  int user_param_max=8388608;
  string server_param;
  string user_param;
  QString mode;
  QString simuTime;

  QString filename = QFileDialog::getSaveFileName(this,
                                         tr("Save Xml"), QString::fromStdString (dce_source)+"/inputDCE.xml",
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
      mode = ui->tcp_download->isChecked ()?"download":"upload";
      simuTime = ui->iperf_time->text ();
    } else if (ui->tabWidget->currentIndex ()==1){
      type="iperf-udp";
      mode = ui->tcp_download_2->isChecked ()? "download":"upload";
      simuTime = ui->iperf_time_2->text ();
    } else {
      type="http";
      congestion = ui->tcp_cc_2->currentText ().toLower ();
      server_param = ui->tcp_mem_server_2->text ().toUtf8 ().constData ();
      user_param = ui->tcp_mem_user_2->text ().toUtf8 ().constData ();
    }



  xmlWriter.writeTextElement("TypeOfConnection", type);
  xmlWriter.writeTextElement("congestionControl", congestion);
  xmlWriter.writeTextElement("UDPBandwidth", ui->udp_bw->text ());
  xmlWriter.writeTextElement("ModeOperation", mode);
  xmlWriter.writeTextElement("Delay", ui->delay->text()+"ms");
  xmlWriter.writeTextElement("ErrorRate",ui->error_rate->text());

  xmlWriter.writeStartElement("JitterParam");
  xmlWriter.writeAttribute("jitter", "true");
  xmlWriter.writeAttribute("alpha",ui->alpha_value->text ());
  xmlWriter.writeAttribute("k",ui->k_value->text ());
  xmlWriter.writeAttribute("theta",ui->theta_value->text ());

  xmlWriter.writeEndElement();

  xmlWriter.writeTextElement("UserBandwidth", ui->user_bw->text ()+"Mbps");
  xmlWriter.writeTextElement("ServerBandwidth",ui->server_bw->text ()+"Gbps");;

  xmlWriter.writeTextElement("Errormodel",QString::number(ui->error_model->currentIndex ()+1));
  xmlWriter.writeTextElement("SizeOfHttpFile", ui->wget_file_size->text());
  xmlWriter.writeTextElement("SimuTime", simuTime);


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

void kupagui::on_button_changefolder_clicked()
{
  QString dir = QFileDialog::getExistingDirectory(this, tr("Select your ns-3-dce folder source"),
                                                  "/home",
                                                  QFileDialog::ShowDirsOnly
                                                  | QFileDialog::DontResolveSymlinks);
  ui->dce_source->setText (dir);
  statusBar()->showMessage(tr("DCE source changed"));
}
