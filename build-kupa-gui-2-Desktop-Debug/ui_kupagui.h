/********************************************************************************
** Form generated from reading UI file 'kupagui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KUPAGUI_H
#define UI_KUPAGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_kupagui
{
public:
    QAction *actionLoad_Command;
    QAction *actionSave_Command;
    QAction *actionRUN;
    QAction *actionSave_Result;
    QAction *actionBye_Bye;
    QAction *actionEdit_XML;
    QAction *actionGuide;
    QAction *actionAbout;
    QAction *actionEdit_Path;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QTabWidget *tabWidget;
    QWidget *IperfTCP;
    QRadioButton *tcp_upload;
    QRadioButton *tcp_download;
    QSpinBox *iperf_time;
    QLabel *label;
    QLineEdit *tcp_mem_server;
    QLabel *label_2;
    QLineEdit *tcp_mem_user;
    QLabel *label_3;
    QComboBox *tcp_cc;
    QLabel *label_4;
    QWidget *IperfUDP;
    QRadioButton *tcp_download_2;
    QRadioButton *tcp_upload_2;
    QSpinBox *udp_bw;
    QLabel *label_12;
    QWidget *wget;
    QLineEdit *tcp_mem_user_2;
    QSpinBox *iperf_time_2;
    QLineEdit *tcp_mem_server_2;
    QLabel *label_13;
    QComboBox *tcp_cc_2;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QSpinBox *wget_file_size;
    QLabel *label_17;
    QSpinBox *user_bw;
    QSpinBox *server_bw;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *error_model;
    QDoubleSpinBox *error_rate;
    QSpinBox *delay;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *button_generate_command;
    QLineEdit *final_command;
    QTextEdit *output_result;
    QPushButton *button_run;
    QPushButton *button_getResult;
    QPushButton *button_exit;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuXML;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *kupagui)
    {
        if (kupagui->objectName().isEmpty())
            kupagui->setObjectName(QStringLiteral("kupagui"));
        kupagui->resize(495, 580);
        actionLoad_Command = new QAction(kupagui);
        actionLoad_Command->setObjectName(QStringLiteral("actionLoad_Command"));
        actionSave_Command = new QAction(kupagui);
        actionSave_Command->setObjectName(QStringLiteral("actionSave_Command"));
        actionRUN = new QAction(kupagui);
        actionRUN->setObjectName(QStringLiteral("actionRUN"));
        actionSave_Result = new QAction(kupagui);
        actionSave_Result->setObjectName(QStringLiteral("actionSave_Result"));
        actionBye_Bye = new QAction(kupagui);
        actionBye_Bye->setObjectName(QStringLiteral("actionBye_Bye"));
        actionEdit_XML = new QAction(kupagui);
        actionEdit_XML->setObjectName(QStringLiteral("actionEdit_XML"));
        actionGuide = new QAction(kupagui);
        actionGuide->setObjectName(QStringLiteral("actionGuide"));
        actionAbout = new QAction(kupagui);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionEdit_Path = new QAction(kupagui);
        actionEdit_Path->setObjectName(QStringLiteral("actionEdit_Path"));
        centralWidget = new QWidget(kupagui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 481, 291));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 461, 161));
        IperfTCP = new QWidget();
        IperfTCP->setObjectName(QStringLiteral("IperfTCP"));
        tcp_upload = new QRadioButton(IperfTCP);
        tcp_upload->setObjectName(QStringLiteral("tcp_upload"));
        tcp_upload->setGeometry(QRect(10, 40, 82, 17));
        tcp_upload->setChecked(false);
        tcp_download = new QRadioButton(IperfTCP);
        tcp_download->setObjectName(QStringLiteral("tcp_download"));
        tcp_download->setGeometry(QRect(10, 70, 101, 17));
        tcp_download->setChecked(true);
        iperf_time = new QSpinBox(IperfTCP);
        iperf_time->setObjectName(QStringLiteral("iperf_time"));
        iperf_time->setGeometry(QRect(360, 40, 81, 22));
        iperf_time->setMaximum(9999);
        iperf_time->setValue(20);
        label = new QLabel(IperfTCP);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 20, 91, 16));
        tcp_mem_server = new QLineEdit(IperfTCP);
        tcp_mem_server->setObjectName(QStringLiteral("tcp_mem_server"));
        tcp_mem_server->setGeometry(QRect(130, 40, 201, 20));
        tcp_mem_server->setMaxLength(50);
        label_2 = new QLabel(IperfTCP);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 20, 201, 16));
        tcp_mem_user = new QLineEdit(IperfTCP);
        tcp_mem_user->setObjectName(QStringLiteral("tcp_mem_user"));
        tcp_mem_user->setGeometry(QRect(130, 90, 201, 20));
        tcp_mem_user->setMaxLength(50);
        label_3 = new QLabel(IperfTCP);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 70, 201, 16));
        tcp_cc = new QComboBox(IperfTCP);
        tcp_cc->setObjectName(QStringLiteral("tcp_cc"));
        tcp_cc->setGeometry(QRect(360, 90, 81, 22));
        label_4 = new QLabel(IperfTCP);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(380, 70, 51, 16));
        tabWidget->addTab(IperfTCP, QString());
        IperfUDP = new QWidget();
        IperfUDP->setObjectName(QStringLiteral("IperfUDP"));
        tcp_download_2 = new QRadioButton(IperfUDP);
        tcp_download_2->setObjectName(QStringLiteral("tcp_download_2"));
        tcp_download_2->setGeometry(QRect(10, 70, 101, 17));
        tcp_download_2->setChecked(true);
        tcp_upload_2 = new QRadioButton(IperfUDP);
        tcp_upload_2->setObjectName(QStringLiteral("tcp_upload_2"));
        tcp_upload_2->setGeometry(QRect(10, 40, 82, 17));
        udp_bw = new QSpinBox(IperfUDP);
        udp_bw->setObjectName(QStringLiteral("udp_bw"));
        udp_bw->setGeometry(QRect(130, 60, 121, 22));
        udp_bw->setMaximum(999999999);
        udp_bw->setSingleStep(100);
        udp_bw->setValue(1000);
        label_12 = new QLabel(IperfUDP);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(130, 40, 181, 16));
        tabWidget->addTab(IperfUDP, QString());
        wget = new QWidget();
        wget->setObjectName(QStringLiteral("wget"));
        tcp_mem_user_2 = new QLineEdit(wget);
        tcp_mem_user_2->setObjectName(QStringLiteral("tcp_mem_user_2"));
        tcp_mem_user_2->setGeometry(QRect(130, 90, 201, 20));
        tcp_mem_user_2->setMaxLength(27);
        iperf_time_2 = new QSpinBox(wget);
        iperf_time_2->setObjectName(QStringLiteral("iperf_time_2"));
        iperf_time_2->setGeometry(QRect(360, 40, 81, 22));
        iperf_time_2->setMaximum(9999);
        iperf_time_2->setValue(20);
        tcp_mem_server_2 = new QLineEdit(wget);
        tcp_mem_server_2->setObjectName(QStringLiteral("tcp_mem_server_2"));
        tcp_mem_server_2->setGeometry(QRect(130, 40, 201, 20));
        tcp_mem_server_2->setMaxLength(32767);
        label_13 = new QLabel(wget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(380, 70, 51, 16));
        tcp_cc_2 = new QComboBox(wget);
        tcp_cc_2->setObjectName(QStringLiteral("tcp_cc_2"));
        tcp_cc_2->setGeometry(QRect(360, 90, 81, 22));
        label_14 = new QLabel(wget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(130, 70, 201, 16));
        label_15 = new QLabel(wget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(350, 20, 91, 20));
        label_16 = new QLabel(wget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(130, 20, 201, 16));
        wget_file_size = new QSpinBox(wget);
        wget_file_size->setObjectName(QStringLiteral("wget_file_size"));
        wget_file_size->setGeometry(QRect(10, 40, 71, 22));
        wget_file_size->setMaximum(9999);
        wget_file_size->setValue(2);
        label_17 = new QLabel(wget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 20, 91, 16));
        tabWidget->addTab(wget, QString());
        user_bw = new QSpinBox(groupBox);
        user_bw->setObjectName(QStringLiteral("user_bw"));
        user_bw->setGeometry(QRect(20, 210, 81, 22));
        user_bw->setMaximum(999);
        user_bw->setValue(150);
        server_bw = new QSpinBox(groupBox);
        server_bw->setObjectName(QStringLiteral("server_bw"));
        server_bw->setGeometry(QRect(20, 260, 81, 22));
        server_bw->setValue(10);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 190, 111, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 240, 121, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(110, 210, 41, 16));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(110, 260, 41, 20));
        error_model = new QComboBox(groupBox);
        error_model->setObjectName(QStringLiteral("error_model"));
        error_model->setGeometry(QRect(190, 210, 69, 22));
        error_rate = new QDoubleSpinBox(groupBox);
        error_rate->setObjectName(QStringLiteral("error_rate"));
        error_rate->setGeometry(QRect(281, 210, 71, 22));
        error_rate->setDecimals(3);
        error_rate->setSingleStep(0.001);
        error_rate->setValue(0.01);
        delay = new QSpinBox(groupBox);
        delay->setObjectName(QStringLiteral("delay"));
        delay->setGeometry(QRect(370, 210, 81, 22));
        delay->setMaximum(99999);
        delay->setValue(2);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(180, 190, 91, 16));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(280, 190, 71, 16));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(380, 190, 71, 16));
        button_generate_command = new QPushButton(centralWidget);
        button_generate_command->setObjectName(QStringLiteral("button_generate_command"));
        button_generate_command->setGeometry(QRect(10, 300, 161, 41));
        final_command = new QLineEdit(centralWidget);
        final_command->setObjectName(QStringLiteral("final_command"));
        final_command->setGeometry(QRect(180, 300, 301, 31));
        output_result = new QTextEdit(centralWidget);
        output_result->setObjectName(QStringLiteral("output_result"));
        output_result->setGeometry(QRect(20, 350, 331, 161));
        button_run = new QPushButton(centralWidget);
        button_run->setObjectName(QStringLiteral("button_run"));
        button_run->setGeometry(QRect(370, 350, 99, 27));
        button_getResult = new QPushButton(centralWidget);
        button_getResult->setObjectName(QStringLiteral("button_getResult"));
        button_getResult->setGeometry(QRect(370, 380, 99, 27));
        button_exit = new QPushButton(centralWidget);
        button_exit->setObjectName(QStringLiteral("button_exit"));
        button_exit->setGeometry(QRect(370, 420, 99, 27));
        kupagui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(kupagui);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 495, 25));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuXML = new QMenu(menuBar);
        menuXML->setObjectName(QStringLiteral("menuXML"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        kupagui->setMenuBar(menuBar);
        mainToolBar = new QToolBar(kupagui);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        kupagui->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(kupagui);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        kupagui->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuXML->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuMenu->addAction(actionLoad_Command);
        menuMenu->addAction(actionSave_Command);
        menuMenu->addSeparator();
        menuMenu->addAction(actionRUN);
        menuMenu->addAction(actionSave_Result);
        menuMenu->addSeparator();
        menuMenu->addAction(actionBye_Bye);
        menuXML->addAction(actionEdit_XML);
        menuHelp->addAction(actionGuide);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);

        retranslateUi(kupagui);
        QObject::connect(button_exit, SIGNAL(clicked()), kupagui, SLOT(close()));
        QObject::connect(actionBye_Bye, SIGNAL(triggered()), kupagui, SLOT(close()));
        QObject::connect(actionGuide, SIGNAL(triggered()), kupagui, SLOT(show()));

        tabWidget->setCurrentIndex(0);
        error_model->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(kupagui);
    } // setupUi

    void retranslateUi(QMainWindow *kupagui)
    {
        kupagui->setWindowTitle(QApplication::translate("kupagui", "kupagui", 0));
        actionLoad_Command->setText(QApplication::translate("kupagui", "Load Command", 0));
        actionSave_Command->setText(QApplication::translate("kupagui", "Save Command", 0));
        actionRUN->setText(QApplication::translate("kupagui", "Run the command", 0));
        actionSave_Result->setText(QApplication::translate("kupagui", "Save Result", 0));
        actionBye_Bye->setText(QApplication::translate("kupagui", "Bye Bye!", 0));
        actionEdit_XML->setText(QApplication::translate("kupagui", "Edit XML", 0));
        actionGuide->setText(QApplication::translate("kupagui", "Guide", 0));
        actionAbout->setText(QApplication::translate("kupagui", "About", 0));
        actionEdit_Path->setText(QApplication::translate("kupagui", "Edit Path", 0));
        groupBox->setTitle(QApplication::translate("kupagui", "Command Editor", 0));
        tcp_upload->setText(QApplication::translate("kupagui", "Upload", 0));
        tcp_download->setText(QApplication::translate("kupagui", "Download", 0));
        label->setText(QApplication::translate("kupagui", "Iperf TIme (s)", 0));
        tcp_mem_server->setInputMask(QString());
        tcp_mem_server->setText(QApplication::translate("kupagui", "4096 8192 8388608", 0));
        label_2->setText(QApplication::translate("kupagui", "tcp_mem_server", 0));
        tcp_mem_user->setText(QApplication::translate("kupagui", "4096 8192 8388608", 0));
        label_3->setText(QApplication::translate("kupagui", "tcp_mem_user", 0));
        tcp_cc->clear();
        tcp_cc->insertItems(0, QStringList()
         << QApplication::translate("kupagui", "Reno", 0)
         << QApplication::translate("kupagui", "BIC", 0)
         << QApplication::translate("kupagui", "CUBIC", 0)
         << QApplication::translate("kupagui", "Highspeed", 0)
         << QApplication::translate("kupagui", "HTCP", 0)
         << QApplication::translate("kupagui", "Hybla", 0)
         << QApplication::translate("kupagui", "Illinois", 0)
         << QApplication::translate("kupagui", "LP", 0)
         << QApplication::translate("kupagui", "Scalable", 0)
         << QApplication::translate("kupagui", "Vegas", 0)
         << QApplication::translate("kupagui", "Veno", 0)
         << QApplication::translate("kupagui", "Westwood", 0)
         << QApplication::translate("kupagui", "Yeah", 0)
        );
        label_4->setText(QApplication::translate("kupagui", "tcp_cc", 0));
        tabWidget->setTabText(tabWidget->indexOf(IperfTCP), QApplication::translate("kupagui", "Iperf-TCP", 0));
        tcp_download_2->setText(QApplication::translate("kupagui", "Download", 0));
        tcp_upload_2->setText(QApplication::translate("kupagui", "Upload", 0));
        label_12->setText(QApplication::translate("kupagui", "UDP allocated bandwidth", 0));
        tabWidget->setTabText(tabWidget->indexOf(IperfUDP), QApplication::translate("kupagui", "Iperf-UDP", 0));
        tcp_mem_user_2->setText(QApplication::translate("kupagui", "4096 8192 8388608", 0));
        tcp_mem_server_2->setInputMask(QString());
        tcp_mem_server_2->setText(QApplication::translate("kupagui", "4096 8192 8388608", 0));
        label_13->setText(QApplication::translate("kupagui", "tcp_cc", 0));
        tcp_cc_2->clear();
        tcp_cc_2->insertItems(0, QStringList()
         << QApplication::translate("kupagui", "Reno", 0)
         << QApplication::translate("kupagui", "BIC", 0)
         << QApplication::translate("kupagui", "CUBIC", 0)
         << QApplication::translate("kupagui", "Highspeed", 0)
         << QApplication::translate("kupagui", "HTCP", 0)
         << QApplication::translate("kupagui", "Hybla", 0)
         << QApplication::translate("kupagui", "Illinois", 0)
         << QApplication::translate("kupagui", "Low Priority", 0)
         << QApplication::translate("kupagui", "Scalable", 0)
         << QApplication::translate("kupagui", "Vegas", 0)
         << QApplication::translate("kupagui", "Veno", 0)
         << QApplication::translate("kupagui", "Westwood", 0)
         << QApplication::translate("kupagui", "Yeah", 0)
        );
        label_14->setText(QApplication::translate("kupagui", "tcp_mem_user", 0));
        label_15->setText(QApplication::translate("kupagui", "Iperf TIme (s)", 0));
        label_16->setText(QApplication::translate("kupagui", "tcp_mem_server", 0));
        label_17->setText(QApplication::translate("kupagui", "File Size (Mb)", 0));
        tabWidget->setTabText(tabWidget->indexOf(wget), QApplication::translate("kupagui", "wget", 0));
        label_5->setText(QApplication::translate("kupagui", "User Bandwidth", 0));
        label_6->setText(QApplication::translate("kupagui", "Server Bandwidth", 0));
        label_7->setText(QApplication::translate("kupagui", "Mbps", 0));
        label_8->setText(QApplication::translate("kupagui", "Gbps", 0));
        error_model->clear();
        error_model->insertItems(0, QStringList()
         << QApplication::translate("kupagui", "Rate", 0)
         << QApplication::translate("kupagui", "Burst", 0)
        );
        label_9->setText(QApplication::translate("kupagui", "Error Model", 0));
        label_10->setText(QApplication::translate("kupagui", "Error Rate", 0));
        label_11->setText(QApplication::translate("kupagui", "Delay (ms)", 0));
        button_generate_command->setText(QApplication::translate("kupagui", "Generate Command", 0));
        button_run->setText(QApplication::translate("kupagui", "RUN!", 0));
        button_getResult->setText(QApplication::translate("kupagui", "get result", 0));
        button_exit->setText(QApplication::translate("kupagui", "exit", 0));
        menuMenu->setTitle(QApplication::translate("kupagui", "Menu", 0));
        menuXML->setTitle(QApplication::translate("kupagui", "Options", 0));
        menuHelp->setTitle(QApplication::translate("kupagui", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class kupagui: public Ui_kupagui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KUPAGUI_H
