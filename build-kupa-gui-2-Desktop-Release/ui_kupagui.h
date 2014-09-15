/********************************************************************************
** Form generated from reading UI file 'kupagui.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
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
#include <QtWidgets/QFrame>
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
#include <QtWidgets/QToolButton>
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
    QLabel *label;
    QComboBox *tcp_cc;
    QLabel *label_4;
    QDoubleSpinBox *iperf_time;
    QTabWidget *memory_option;
    QWidget *usermemory;
    QLabel *label_24;
    QLineEdit *tcp_mem_user_rmem;
    QLabel *label_15;
    QLineEdit *tcp_mem_user;
    QLabel *label_8;
    QLineEdit *tcp_mem_user_wmem;
    QWidget *servermemory;
    QLineEdit *tcp_mem_server;
    QLineEdit *tcp_mem_server_rmem;
    QLabel *label_31;
    QLineEdit *tcp_mem_server_wmem;
    QLabel *label_29;
    QLabel *label_30;
    QWidget *IperfUDP;
    QRadioButton *udp_download;
    QRadioButton *udp_upload;
    QSpinBox *udp_bw;
    QLabel *label_12;
    QLabel *label_18;
    QLabel *label_23;
    QDoubleSpinBox *iperf_time_udp;
    QWidget *wget;
    QLabel *label_13;
    QComboBox *tcp_cc_wget;
    QSpinBox *wget_file_size;
    QLabel *label_17;
    QTabWidget *memory_option_2;
    QWidget *usermemory_2;
    QLabel *label_25;
    QLineEdit *tcp_mem_user_rmem_2;
    QLabel *label_16;
    QLineEdit *tcp_mem_user_2;
    QLabel *label_11;
    QLineEdit *tcp_mem_user_wmem_2;
    QWidget *servermemory_2;
    QLineEdit *tcp_mem_server_2;
    QLineEdit *tcp_mem_server_rmem_2;
    QLabel *label_32;
    QLineEdit *tcp_mem_server_wmem_2;
    QLabel *label_33;
    QLabel *label_34;
    QComboBox *error_model;
    QDoubleSpinBox *error_rate;
    QLabel *label_9;
    QLabel *label_10;
    QFrame *frame;
    QComboBox *server_bw_unit;
    QComboBox *user_bw_unit;
    QSpinBox *server_bw;
    QLabel *label_5;
    QSpinBox *user_bw;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *frame_6;
    QLabel *label_27;
    QLabel *label_21;
    QLabel *label_20;
    QDoubleSpinBox *alpha_value;
    QDoubleSpinBox *variance_value;
    QDoubleSpinBox *mean_value;
    QLabel *label_22;
    QPushButton *button_generate_command;
    QLineEdit *final_command;
    QTextEdit *output_result;
    QPushButton *button_run;
    QPushButton *button_getResult;
    QPushButton *button_exit;
    QLabel *label_19;
    QLineEdit *dce_source;
    QToolButton *button_changefolder;
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
        kupagui->resize(617, 721);
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
        groupBox->setGeometry(QRect(10, 0, 601, 431));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 30, 581, 221));
        IperfTCP = new QWidget();
        IperfTCP->setObjectName(QStringLiteral("IperfTCP"));
        tcp_upload = new QRadioButton(IperfTCP);
        tcp_upload->setObjectName(QStringLiteral("tcp_upload"));
        tcp_upload->setGeometry(QRect(0, 40, 82, 17));
        tcp_upload->setChecked(false);
        tcp_download = new QRadioButton(IperfTCP);
        tcp_download->setObjectName(QStringLiteral("tcp_download"));
        tcp_download->setGeometry(QRect(0, 70, 101, 17));
        tcp_download->setChecked(true);
        label = new QLabel(IperfTCP);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(480, 40, 101, 20));
        tcp_cc = new QComboBox(IperfTCP);
        tcp_cc->setObjectName(QStringLiteral("tcp_cc"));
        tcp_cc->setGeometry(QRect(490, 140, 71, 22));
        label_4 = new QLabel(IperfTCP);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(500, 110, 51, 16));
        iperf_time = new QDoubleSpinBox(IperfTCP);
        iperf_time->setObjectName(QStringLiteral("iperf_time"));
        iperf_time->setGeometry(QRect(490, 70, 71, 21));
        iperf_time->setDecimals(2);
        iperf_time->setMaximum(500);
        iperf_time->setSingleStep(1);
        iperf_time->setValue(10);
        memory_option = new QTabWidget(IperfTCP);
        memory_option->setObjectName(QStringLiteral("memory_option"));
        memory_option->setGeometry(QRect(110, 20, 351, 151));
        usermemory = new QWidget();
        usermemory->setObjectName(QStringLiteral("usermemory"));
        label_24 = new QLabel(usermemory);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(30, 80, 71, 20));
        tcp_mem_user_rmem = new QLineEdit(usermemory);
        tcp_mem_user_rmem->setObjectName(QStringLiteral("tcp_mem_user_rmem"));
        tcp_mem_user_rmem->setGeometry(QRect(110, 80, 201, 20));
        tcp_mem_user_rmem->setMaxLength(200);
        label_15 = new QLabel(usermemory);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(30, 50, 81, 20));
        tcp_mem_user = new QLineEdit(usermemory);
        tcp_mem_user->setObjectName(QStringLiteral("tcp_mem_user"));
        tcp_mem_user->setGeometry(QRect(110, 20, 201, 20));
        tcp_mem_user->setMaxLength(200);
        label_8 = new QLabel(usermemory);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 20, 71, 16));
        tcp_mem_user_wmem = new QLineEdit(usermemory);
        tcp_mem_user_wmem->setObjectName(QStringLiteral("tcp_mem_user_wmem"));
        tcp_mem_user_wmem->setGeometry(QRect(110, 50, 201, 20));
        tcp_mem_user_wmem->setMaxLength(200);
        memory_option->addTab(usermemory, QString());
        servermemory = new QWidget();
        servermemory->setObjectName(QStringLiteral("servermemory"));
        tcp_mem_server = new QLineEdit(servermemory);
        tcp_mem_server->setObjectName(QStringLiteral("tcp_mem_server"));
        tcp_mem_server->setGeometry(QRect(110, 20, 201, 20));
        tcp_mem_server->setMaxLength(200);
        tcp_mem_server_rmem = new QLineEdit(servermemory);
        tcp_mem_server_rmem->setObjectName(QStringLiteral("tcp_mem_server_rmem"));
        tcp_mem_server_rmem->setGeometry(QRect(110, 80, 201, 20));
        tcp_mem_server_rmem->setMaxLength(200);
        label_31 = new QLabel(servermemory);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(30, 80, 71, 20));
        tcp_mem_server_wmem = new QLineEdit(servermemory);
        tcp_mem_server_wmem->setObjectName(QStringLiteral("tcp_mem_server_wmem"));
        tcp_mem_server_wmem->setGeometry(QRect(110, 50, 201, 20));
        tcp_mem_server_wmem->setMaxLength(200);
        label_29 = new QLabel(servermemory);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(30, 20, 71, 16));
        label_30 = new QLabel(servermemory);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(30, 50, 81, 20));
        memory_option->addTab(servermemory, QString());
        tabWidget->addTab(IperfTCP, QString());
        IperfUDP = new QWidget();
        IperfUDP->setObjectName(QStringLiteral("IperfUDP"));
        udp_download = new QRadioButton(IperfUDP);
        udp_download->setObjectName(QStringLiteral("udp_download"));
        udp_download->setGeometry(QRect(20, 70, 101, 17));
        udp_download->setChecked(true);
        udp_upload = new QRadioButton(IperfUDP);
        udp_upload->setObjectName(QStringLiteral("udp_upload"));
        udp_upload->setGeometry(QRect(20, 40, 82, 17));
        udp_bw = new QSpinBox(IperfUDP);
        udp_bw->setObjectName(QStringLiteral("udp_bw"));
        udp_bw->setGeometry(QRect(190, 70, 121, 22));
        udp_bw->setMaximum(99999999);
        udp_bw->setSingleStep(1);
        udp_bw->setValue(20);
        label_12 = new QLabel(IperfUDP);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(190, 40, 181, 16));
        label_18 = new QLabel(IperfUDP);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(330, 70, 67, 17));
        label_23 = new QLabel(IperfUDP);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(460, 40, 91, 16));
        iperf_time_udp = new QDoubleSpinBox(IperfUDP);
        iperf_time_udp->setObjectName(QStringLiteral("iperf_time_udp"));
        iperf_time_udp->setGeometry(QRect(460, 70, 91, 21));
        iperf_time_udp->setDecimals(2);
        iperf_time_udp->setMaximum(200);
        iperf_time_udp->setSingleStep(1);
        iperf_time_udp->setValue(10);
        tabWidget->addTab(IperfUDP, QString());
        wget = new QWidget();
        wget->setObjectName(QStringLiteral("wget"));
        label_13 = new QLabel(wget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(480, 40, 51, 16));
        tcp_cc_wget = new QComboBox(wget);
        tcp_cc_wget->setObjectName(QStringLiteral("tcp_cc_wget"));
        tcp_cc_wget->setGeometry(QRect(480, 70, 81, 22));
        wget_file_size = new QSpinBox(wget);
        wget_file_size->setObjectName(QStringLiteral("wget_file_size"));
        wget_file_size->setGeometry(QRect(10, 40, 71, 22));
        wget_file_size->setMaximum(9999);
        wget_file_size->setValue(2);
        label_17 = new QLabel(wget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 20, 91, 16));
        memory_option_2 = new QTabWidget(wget);
        memory_option_2->setObjectName(QStringLiteral("memory_option_2"));
        memory_option_2->setGeometry(QRect(110, 20, 351, 151));
        usermemory_2 = new QWidget();
        usermemory_2->setObjectName(QStringLiteral("usermemory_2"));
        label_25 = new QLabel(usermemory_2);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(30, 80, 71, 20));
        tcp_mem_user_rmem_2 = new QLineEdit(usermemory_2);
        tcp_mem_user_rmem_2->setObjectName(QStringLiteral("tcp_mem_user_rmem_2"));
        tcp_mem_user_rmem_2->setGeometry(QRect(110, 80, 201, 20));
        tcp_mem_user_rmem_2->setMaxLength(200);
        label_16 = new QLabel(usermemory_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(30, 50, 81, 20));
        tcp_mem_user_2 = new QLineEdit(usermemory_2);
        tcp_mem_user_2->setObjectName(QStringLiteral("tcp_mem_user_2"));
        tcp_mem_user_2->setGeometry(QRect(110, 20, 201, 20));
        tcp_mem_user_2->setMaxLength(200);
        label_11 = new QLabel(usermemory_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 20, 71, 16));
        tcp_mem_user_wmem_2 = new QLineEdit(usermemory_2);
        tcp_mem_user_wmem_2->setObjectName(QStringLiteral("tcp_mem_user_wmem_2"));
        tcp_mem_user_wmem_2->setGeometry(QRect(110, 50, 201, 20));
        tcp_mem_user_wmem_2->setMaxLength(200);
        memory_option_2->addTab(usermemory_2, QString());
        servermemory_2 = new QWidget();
        servermemory_2->setObjectName(QStringLiteral("servermemory_2"));
        tcp_mem_server_2 = new QLineEdit(servermemory_2);
        tcp_mem_server_2->setObjectName(QStringLiteral("tcp_mem_server_2"));
        tcp_mem_server_2->setGeometry(QRect(110, 20, 201, 20));
        tcp_mem_server_2->setMaxLength(200);
        tcp_mem_server_rmem_2 = new QLineEdit(servermemory_2);
        tcp_mem_server_rmem_2->setObjectName(QStringLiteral("tcp_mem_server_rmem_2"));
        tcp_mem_server_rmem_2->setGeometry(QRect(110, 80, 201, 20));
        tcp_mem_server_rmem_2->setMaxLength(200);
        label_32 = new QLabel(servermemory_2);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(30, 80, 71, 20));
        tcp_mem_server_wmem_2 = new QLineEdit(servermemory_2);
        tcp_mem_server_wmem_2->setObjectName(QStringLiteral("tcp_mem_server_wmem_2"));
        tcp_mem_server_wmem_2->setGeometry(QRect(110, 50, 201, 20));
        tcp_mem_server_wmem_2->setMaxLength(200);
        label_33 = new QLabel(servermemory_2);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(30, 20, 71, 16));
        label_34 = new QLabel(servermemory_2);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(30, 50, 81, 20));
        memory_option_2->addTab(servermemory_2, QString());
        tabWidget->addTab(wget, QString());
        error_model = new QComboBox(groupBox);
        error_model->setObjectName(QStringLiteral("error_model"));
        error_model->setGeometry(QRect(280, 300, 69, 22));
        error_rate = new QDoubleSpinBox(groupBox);
        error_rate->setObjectName(QStringLiteral("error_rate"));
        error_rate->setGeometry(QRect(280, 360, 71, 22));
        error_rate->setDecimals(3);
        error_rate->setSingleStep(0.001);
        error_rate->setValue(0);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(270, 270, 91, 16));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(280, 330, 71, 16));
        frame = new QFrame(groupBox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 260, 241, 161));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        server_bw_unit = new QComboBox(frame);
        server_bw_unit->setObjectName(QStringLiteral("server_bw_unit"));
        server_bw_unit->setGeometry(QRect(160, 100, 64, 22));
        user_bw_unit = new QComboBox(frame);
        user_bw_unit->setObjectName(QStringLiteral("user_bw_unit"));
        user_bw_unit->setGeometry(QRect(160, 50, 65, 22));
        server_bw = new QSpinBox(frame);
        server_bw->setObjectName(QStringLiteral("server_bw"));
        server_bw->setGeometry(QRect(71, 100, 81, 22));
        server_bw->setValue(10);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 53, 41, 16));
        user_bw = new QSpinBox(frame);
        user_bw->setObjectName(QStringLiteral("user_bw"));
        user_bw->setGeometry(QRect(71, 50, 81, 22));
        user_bw->setMaximum(999);
        user_bw->setValue(150);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 103, 61, 16));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 10, 111, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);
        frame_6 = new QFrame(groupBox);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setGeometry(QRect(370, 260, 221, 161));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        label_27 = new QLabel(frame_6);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(10, 10, 111, 16));
        label_27->setFont(font);
        label_21 = new QLabel(frame_6);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(20, 110, 67, 17));
        label_20 = new QLabel(frame_6);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(20, 36, 91, 20));
        alpha_value = new QDoubleSpinBox(frame_6);
        alpha_value->setObjectName(QStringLiteral("alpha_value"));
        alpha_value->setGeometry(QRect(130, 30, 69, 27));
        alpha_value->setDecimals(3);
        alpha_value->setMaximum(1);
        alpha_value->setSingleStep(0.05);
        alpha_value->setValue(0);
        variance_value = new QDoubleSpinBox(frame_6);
        variance_value->setObjectName(QStringLiteral("variance_value"));
        variance_value->setGeometry(QRect(130, 110, 69, 27));
        variance_value->setDecimals(3);
        variance_value->setSingleStep(0.5);
        variance_value->setValue(0);
        mean_value = new QDoubleSpinBox(frame_6);
        mean_value->setObjectName(QStringLiteral("mean_value"));
        mean_value->setGeometry(QRect(130, 70, 69, 27));
        mean_value->setDecimals(3);
        mean_value->setMaximum(999);
        mean_value->setSingleStep(0.5);
        mean_value->setValue(1);
        label_22 = new QLabel(frame_6);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(20, 70, 41, 20));
        frame->raise();
        tabWidget->raise();
        error_model->raise();
        error_rate->raise();
        label_9->raise();
        label_10->raise();
        frame_6->raise();
        button_generate_command = new QPushButton(centralWidget);
        button_generate_command->setObjectName(QStringLiteral("button_generate_command"));
        button_generate_command->setGeometry(QRect(20, 440, 151, 30));
        final_command = new QLineEdit(centralWidget);
        final_command->setObjectName(QStringLiteral("final_command"));
        final_command->setGeometry(QRect(170, 440, 421, 31));
        output_result = new QTextEdit(centralWidget);
        output_result->setObjectName(QStringLiteral("output_result"));
        output_result->setGeometry(QRect(20, 480, 451, 121));
        button_run = new QPushButton(centralWidget);
        button_run->setObjectName(QStringLiteral("button_run"));
        button_run->setGeometry(QRect(480, 480, 99, 27));
        button_getResult = new QPushButton(centralWidget);
        button_getResult->setObjectName(QStringLiteral("button_getResult"));
        button_getResult->setGeometry(QRect(480, 520, 99, 27));
        button_exit = new QPushButton(centralWidget);
        button_exit->setObjectName(QStringLiteral("button_exit"));
        button_exit->setGeometry(QRect(480, 560, 99, 27));
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(20, 620, 81, 17));
        dce_source = new QLineEdit(centralWidget);
        dce_source->setObjectName(QStringLiteral("dce_source"));
        dce_source->setGeometry(QRect(110, 620, 421, 27));
        dce_source->setInputMask(QStringLiteral(""));
        dce_source->setMaxLength(32767);
        dce_source->setFrame(true);
        button_changefolder = new QToolButton(centralWidget);
        button_changefolder->setObjectName(QStringLiteral("button_changefolder"));
        button_changefolder->setGeometry(QRect(550, 620, 24, 25));
        kupagui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(kupagui);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 617, 25));
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
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);

        retranslateUi(kupagui);
        QObject::connect(button_exit, SIGNAL(clicked()), kupagui, SLOT(close()));
        QObject::connect(actionBye_Bye, SIGNAL(triggered()), kupagui, SLOT(close()));
        QObject::connect(actionGuide, SIGNAL(triggered()), kupagui, SLOT(show()));

        tabWidget->setCurrentIndex(2);
        memory_option->setCurrentIndex(0);
        memory_option_2->setCurrentIndex(0);
        error_model->setCurrentIndex(0);
        server_bw_unit->setCurrentIndex(1);
        user_bw_unit->setCurrentIndex(0);


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
#ifndef QT_NO_TOOLTIP
        groupBox->setToolTip(QApplication::translate("kupagui", "<html><head/><body><p>use command editor to make your own command for kupakupa</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        groupBox->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>this part is generating command for you to run :)</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        groupBox->setTitle(QApplication::translate("kupagui", "Command Editor", 0));
#ifndef QT_NO_WHATSTHIS
        tabWidget->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>set up your iper or http connection here</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        tcp_upload->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>client send data to server</p><p><br/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        tcp_upload->setText(QApplication::translate("kupagui", "Upload", 0));
#ifndef QT_NO_WHATSTHIS
        tcp_download->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>client get data from server</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        tcp_download->setText(QApplication::translate("kupagui", "Download", 0));
        label->setText(QApplication::translate("kupagui", "Iperf TIme (s)", 0));
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
#ifndef QT_NO_WHATSTHIS
        tcp_cc->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>Reno - default tcp congestion control algorithm</p><p><br/></p><p>Other options:</p><p><span style=\" font-weight:600;\">High Speed TCP</span></p><p>The algorithm is described in RFC 3649. The main use is for connections with large bandwidth and large RTT (such as Gbit/s and 100 ms RTT).</p><p><span style=\" font-weight:600;\">H-TCP</span></p><p>H-TCP was proposed by the Hamilton Institute for transmissions that recover more quickly after a congestion event. It is also designed for links with high bandwidth and RTT.</p><p><span style=\" font-weight:600;\">Scalable TCP</span></p><p>This is another algorithm for WAN links with high bandwidth and RTT. One of its design goals is a quick recovery of the window size after a congestion event. It achieves this goal by resetting the window to a higher value than standard TCP.</p><p><span style=\" font-weight:600;\">TCP BIC</span></p><p>BIC is the abbreviation for Binary Increase Congestion control. BIC uses a unique window growth function. In case"
                        " of packet loss, the window is reduced by a multiplicative factor. The window size just before and after the reduction is then used as parameters for a binary search for the new window size. BIC was used as standard algorithm in the Linux kernel.</p><p><span style=\" font-weight:600;\">TCP CUBIC</span></p><p>CUBIC is a less aggressive variant of BIC (meaning, it doesn't steal as much throughput from competing TCP flows as does BIC).</p><p><span style=\" font-weight:600;\">TCP Hybla</span></p><p>TCP Hybla was proposed in order to transmit data efficiently over satellite links and &quot;defend&quot; the transmission against TCP flows from other origins.</p><p><span style=\" font-weight:600;\">TCP Low Priority (lp)</span></p><p>This is an approach to develop an algorithm that uses excess bandwidth for TCP flows. It can be used for low priority data transfers without &quot;disturbing&quot; other TCP transmissions (which probably don't use TCP Low Priority).</p><p><span style=\" font-weight:600;\">TCP Tahoe/Reno</s"
                        "pan></p><p>These are the classical models used for congestion control. They exhibit the typical slow start of transmissions. The throughput increases gradually until it stays stable. It is decreased as soon as the transfer encounters congestion, then the rate rises again slowly. The window is increased by adding fixed values. TCP Reno uses a multiplicative decrease algorithm for the reduction of window size. TCP Reno is the most widely deployed algorithm.</p><p><span style=\" font-weight:600;\">TCP Vegas</span></p><p>TCP Vegas introduces the measurement of RTT for evaluating the link quality. It uses additive increases and additive decreases for the congestion window.</p><p><span style=\" font-weight:600;\">TCP Veno</span></p><p>This variant is optimised for wireless networks, since it was designed to handle random packet loss better. It tries to keep track of the transfer, and guesses if the quality decreases due to congestion or random packet errors.</p><p><span style=\" font-weight:600;\">TCP Westwood+</spa"
                        "n></p><p>Westwood+ addresses both large bandwidth/RTT values and random packet loss together with dynamically changing network loads. It analyses the state of the transfer by looking at the acknowledgement packets. Westwood+ is a modification of the TCP Reno algorithm.</p><p><br/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_4->setText(QApplication::translate("kupagui", "tcp_cc", 0));
        label_24->setText(QApplication::translate("kupagui", "tcp_rmem", 0));
#ifndef QT_NO_TOOLTIP
        tcp_mem_user_rmem->setToolTip(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tcp_mem_user_rmem->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        tcp_mem_user_rmem->setInputMask(QString());
        tcp_mem_user_rmem->setText(QApplication::translate("kupagui", "8388608 8388608 8388608", 0));
        label_15->setText(QApplication::translate("kupagui", "tcp_wmem", 0));
#ifndef QT_NO_TOOLTIP
        tcp_mem_user->setToolTip(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tcp_mem_user->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        tcp_mem_user->setInputMask(QString());
        tcp_mem_user->setText(QApplication::translate("kupagui", "8388608 8388608 8388608", 0));
        label_8->setText(QApplication::translate("kupagui", "tcp_mem", 0));
#ifndef QT_NO_TOOLTIP
        tcp_mem_user_wmem->setToolTip(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tcp_mem_user_wmem->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        tcp_mem_user_wmem->setInputMask(QString());
        tcp_mem_user_wmem->setText(QApplication::translate("kupagui", "8388608 8388608 8388608", 0));
        memory_option->setTabText(memory_option->indexOf(usermemory), QApplication::translate("kupagui", "User Memory", 0));
#ifndef QT_NO_TOOLTIP
        tcp_mem_server->setToolTip(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tcp_mem_server->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        tcp_mem_server->setInputMask(QString());
        tcp_mem_server->setText(QApplication::translate("kupagui", "8388608 8388608 8388608", 0));
#ifndef QT_NO_TOOLTIP
        tcp_mem_server_rmem->setToolTip(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tcp_mem_server_rmem->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        tcp_mem_server_rmem->setInputMask(QString());
        tcp_mem_server_rmem->setText(QApplication::translate("kupagui", "8388608 8388608 8388608", 0));
        label_31->setText(QApplication::translate("kupagui", "tcp_rmem", 0));
#ifndef QT_NO_TOOLTIP
        tcp_mem_server_wmem->setToolTip(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tcp_mem_server_wmem->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        tcp_mem_server_wmem->setInputMask(QString());
        tcp_mem_server_wmem->setText(QApplication::translate("kupagui", "8388608 8388608 8388608", 0));
        label_29->setText(QApplication::translate("kupagui", "tcp_mem", 0));
        label_30->setText(QApplication::translate("kupagui", "tcp_wmem", 0));
        memory_option->setTabText(memory_option->indexOf(servermemory), QApplication::translate("kupagui", "Server Memory", 0));
        tabWidget->setTabText(tabWidget->indexOf(IperfTCP), QApplication::translate("kupagui", "Iperf-TCP", 0));
        udp_download->setText(QApplication::translate("kupagui", "Download", 0));
        udp_upload->setText(QApplication::translate("kupagui", "Upload", 0));
        label_12->setText(QApplication::translate("kupagui", "UDP allocated bandwidth", 0));
        label_18->setText(QApplication::translate("kupagui", "Mbps", 0));
        label_23->setText(QApplication::translate("kupagui", "Iperf TIme (s)", 0));
        tabWidget->setTabText(tabWidget->indexOf(IperfUDP), QApplication::translate("kupagui", "Iperf-UDP", 0));
        label_13->setText(QApplication::translate("kupagui", "tcp_cc", 0));
        tcp_cc_wget->clear();
        tcp_cc_wget->insertItems(0, QStringList()
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
        label_17->setText(QApplication::translate("kupagui", "File Size (Mb)", 0));
        label_25->setText(QApplication::translate("kupagui", "tcp_rmem", 0));
#ifndef QT_NO_TOOLTIP
        tcp_mem_user_rmem_2->setToolTip(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tcp_mem_user_rmem_2->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        tcp_mem_user_rmem_2->setInputMask(QString());
        tcp_mem_user_rmem_2->setText(QApplication::translate("kupagui", "8388608 8388608 8388608", 0));
        label_16->setText(QApplication::translate("kupagui", "tcp_wmem", 0));
#ifndef QT_NO_TOOLTIP
        tcp_mem_user_2->setToolTip(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tcp_mem_user_2->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        tcp_mem_user_2->setInputMask(QString());
        tcp_mem_user_2->setText(QApplication::translate("kupagui", "8388608 8388608 8388608", 0));
        label_11->setText(QApplication::translate("kupagui", "tcp_mem", 0));
#ifndef QT_NO_TOOLTIP
        tcp_mem_user_wmem_2->setToolTip(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tcp_mem_user_wmem_2->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        tcp_mem_user_wmem_2->setInputMask(QString());
        tcp_mem_user_wmem_2->setText(QApplication::translate("kupagui", "8388608 8388608 8388608", 0));
        memory_option_2->setTabText(memory_option_2->indexOf(usermemory_2), QApplication::translate("kupagui", "User Memory", 0));
#ifndef QT_NO_TOOLTIP
        tcp_mem_server_2->setToolTip(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tcp_mem_server_2->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        tcp_mem_server_2->setInputMask(QString());
        tcp_mem_server_2->setText(QApplication::translate("kupagui", "8388608 8388608 8388608", 0));
#ifndef QT_NO_TOOLTIP
        tcp_mem_server_rmem_2->setToolTip(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tcp_mem_server_rmem_2->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        tcp_mem_server_rmem_2->setInputMask(QString());
        tcp_mem_server_rmem_2->setText(QApplication::translate("kupagui", "8388608 8388608 8388608", 0));
        label_32->setText(QApplication::translate("kupagui", "tcp_rmem", 0));
#ifndef QT_NO_TOOLTIP
        tcp_mem_server_wmem_2->setToolTip(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tcp_mem_server_wmem_2->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        tcp_mem_server_wmem_2->setInputMask(QString());
        tcp_mem_server_wmem_2->setText(QApplication::translate("kupagui", "8388608 8388608 8388608", 0));
        label_33->setText(QApplication::translate("kupagui", "tcp_mem", 0));
        label_34->setText(QApplication::translate("kupagui", "tcp_wmem", 0));
        memory_option_2->setTabText(memory_option_2->indexOf(servermemory_2), QApplication::translate("kupagui", "Server Memory", 0));
        tabWidget->setTabText(tabWidget->indexOf(wget), QApplication::translate("kupagui", "wget", 0));
        error_model->clear();
        error_model->insertItems(0, QStringList()
         << QApplication::translate("kupagui", "Rate", 0)
         << QApplication::translate("kupagui", "Burst", 0)
        );
        label_9->setText(QApplication::translate("kupagui", "Error Model", 0));
        label_10->setText(QApplication::translate("kupagui", "Error Rate", 0));
        server_bw_unit->clear();
        server_bw_unit->insertItems(0, QStringList()
         << QApplication::translate("kupagui", "Mbps", 0)
         << QApplication::translate("kupagui", "Gbps", 0)
        );
        user_bw_unit->clear();
        user_bw_unit->insertItems(0, QStringList()
         << QApplication::translate("kupagui", "Mbps", 0)
         << QApplication::translate("kupagui", "Gbps", 0)
        );
        label_5->setText(QApplication::translate("kupagui", "User ", 0));
        label_6->setText(QApplication::translate("kupagui", "Server ", 0));
        label_7->setText(QApplication::translate("kupagui", "Bandwidth", 0));
        label_27->setText(QApplication::translate("kupagui", "Delay", 0));
        label_21->setText(QApplication::translate("kupagui", "Variance", 0));
        label_20->setText(QApplication::translate("kupagui", "Randomness", 0));
        label_22->setText(QApplication::translate("kupagui", "Mean", 0));
        button_generate_command->setText(QApplication::translate("kupagui", "Generate Command", 0));
#ifndef QT_NO_WHATSTHIS
        final_command->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>the command will be generated in this area, as well as the .sh file on source folder</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        output_result->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>result box, display all stdout from run and get result button</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        button_run->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>run the .sh file from source folder and put the stdout on result box</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        button_run->setText(QApplication::translate("kupagui", "RUN!", 0));
#ifndef QT_NO_WHATSTHIS
        button_getResult->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>parse desired output to output box</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        button_getResult->setText(QApplication::translate("kupagui", "Get Result", 0));
        button_exit->setText(QApplication::translate("kupagui", "Exit", 0));
        label_19->setText(QApplication::translate("kupagui", "DCE Source:", 0));
        dce_source->setText(QApplication::translate("kupagui", "/home/nama/dce/source/ns-3-dce", 0));
        button_changefolder->setText(QApplication::translate("kupagui", "...", 0));
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
