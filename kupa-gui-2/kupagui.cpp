#include "kupagui.h"
#include "ui_kupagui.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QSaveFile>

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
    QString TypeOfConnection = "";
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
}

