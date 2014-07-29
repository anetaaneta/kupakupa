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
#include <QtWidgets/QCheckBox>
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
    QLabel *label_18;
    QSpinBox *iperf_time_2;
    QLabel *label_23;
    QWidget *wget;
    QLineEdit *tcp_mem_user_2;
    QLineEdit *tcp_mem_server_2;
    QLabel *label_13;
    QComboBox *tcp_cc_2;
    QLabel *label_14;
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
    QDoubleSpinBox *alpha_value;
    QDoubleSpinBox *tetha_value;
    QDoubleSpinBox *k_value;
    QCheckBox *jitter_check;
    QLabel *label_20;
    QLabel *label_21;
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
        kupagui->resize(505, 620);
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
        tcp_mem_server->setMaxLength(200);
        label_2 = new QLabel(IperfTCP);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 20, 201, 16));
        tcp_mem_user = new QLineEdit(IperfTCP);
        tcp_mem_user->setObjectName(QStringLiteral("tcp_mem_user"));
        tcp_mem_user->setGeometry(QRect(130, 90, 201, 20));
        tcp_mem_user->setMaxLength(200);
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
        udp_bw->setMaximum(99999999);
        udp_bw->setSingleStep(1);
        udp_bw->setValue(1);
        label_12 = new QLabel(IperfUDP);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(130, 40, 181, 16));
        label_18 = new QLabel(IperfUDP);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(260, 60, 67, 17));
        iperf_time_2 = new QSpinBox(IperfUDP);
        iperf_time_2->setObjectName(QStringLiteral("iperf_time_2"));
        iperf_time_2->setGeometry(QRect(370, 60, 81, 22));
        iperf_time_2->setMaximum(9999);
        iperf_time_2->setValue(20);
        label_23 = new QLabel(IperfUDP);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(360, 40, 91, 16));
        tabWidget->addTab(IperfUDP, QString());
        wget = new QWidget();
        wget->setObjectName(QStringLiteral("wget"));
        tcp_mem_user_2 = new QLineEdit(wget);
        tcp_mem_user_2->setObjectName(QStringLiteral("tcp_mem_user_2"));
        tcp_mem_user_2->setGeometry(QRect(130, 90, 201, 20));
        tcp_mem_user_2->setMaxLength(27);
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
        error_rate->setGeometry(QRect(280, 210, 71, 22));
        error_rate->setDecimals(3);
        error_rate->setSingleStep(0.001);
        error_rate->setValue(0.001);
        delay = new QSpinBox(groupBox);
        delay->setObjectName(QStringLiteral("delay"));
        delay->setGeometry(QRect(390, 210, 81, 22));
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
        label_11->setGeometry(QRect(390, 190, 71, 16));
        alpha_value = new QDoubleSpinBox(groupBox);
        alpha_value->setObjectName(QStringLiteral("alpha_value"));
        alpha_value->setGeometry(QRect(260, 260, 69, 27));
        alpha_value->setDecimals(3);
        alpha_value->setMaximum(1);
        alpha_value->setSingleStep(0.001);
        alpha_value->setValue(0.3);
        tetha_value = new QDoubleSpinBox(groupBox);
        tetha_value->setObjectName(QStringLiteral("tetha_value"));
        tetha_value->setGeometry(QRect(330, 260, 69, 27));
        tetha_value->setDecimals(1);
        tetha_value->setSingleStep(0.5);
        tetha_value->setValue(1);
        k_value = new QDoubleSpinBox(groupBox);
        k_value->setObjectName(QStringLiteral("k_value"));
        k_value->setGeometry(QRect(400, 260, 69, 27));
        k_value->setMaximum(999);
        k_value->setValue(10);
        jitter_check = new QCheckBox(groupBox);
        jitter_check->setObjectName(QStringLiteral("jitter_check"));
        jitter_check->setGeometry(QRect(190, 260, 61, 22));
        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(260, 240, 51, 17));
        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(330, 240, 67, 17));
        label_22 = new QLabel(groupBox);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(400, 240, 67, 17));
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
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 530, 81, 17));
        dce_source = new QLineEdit(centralWidget);
        dce_source->setObjectName(QStringLiteral("dce_source"));
        dce_source->setGeometry(QRect(100, 530, 351, 27));
        dce_source->setInputMask(QStringLiteral(""));
        dce_source->setMaxLength(32767);
        dce_source->setFrame(true);
        button_changefolder = new QToolButton(centralWidget);
        button_changefolder->setObjectName(QStringLiteral("button_changefolder"));
        button_changefolder->setGeometry(QRect(460, 530, 24, 25));
        kupagui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(kupagui);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 505, 25));
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
#ifndef QT_NO_WHATSTHIS
        iperf_time->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>time to do iperf. simulation will add 10 more seconds</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("kupagui", "Iperf TIme (s)", 0));
#ifndef QT_NO_TOOLTIP
        tcp_mem_server->setToolTip(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tcp_mem_server->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        tcp_mem_server->setInputMask(QString());
        tcp_mem_server->setText(QApplication::translate("kupagui", "4096 8192 8388608", 0));
        label_2->setText(QApplication::translate("kupagui", "tcp_mem_server", 0));
#ifndef QT_NO_TOOLTIP
        tcp_mem_user->setToolTip(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tcp_mem_user->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
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
#ifndef QT_NO_WHATSTHIS
        tcp_cc->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>Reno - default tcp congestion control algorithm</p><p><br/></p><p>Other options:</p><p><span style=\" font-weight:600;\">High Speed TCP</span></p><p>The algorithm is described in RFC 3649. The main use is for connections with large bandwidth and large RTT (such as Gbit/s and 100 ms RTT).</p><p><span style=\" font-weight:600;\">H-TCP</span></p><p>H-TCP was proposed by the Hamilton Institute for transmissions that recover more quickly after a congestion event. It is also designed for links with high bandwidth and RTT.</p><p><span style=\" font-weight:600;\">Scalable TCP</span></p><p>This is another algorithm for WAN links with high bandwidth and RTT. One of its design goals is a quick recovery of the window size after a congestion event. It achieves this goal by resetting the window to a higher value than standard TCP.</p><p><span style=\" font-weight:600;\">TCP BIC</span></p><p>BIC is the abbreviation for Binary Increase Congestion control. BIC uses a unique window growth function. In case"
                        " of packet loss, the window is reduced by a multiplicative factor. The window size just before and after the reduction is then used as parameters for a binary search for the new window size. BIC was used as standard algorithm in the Linux kernel.</p><p><span style=\" font-weight:600;\">TCP CUBIC</span></p><p>CUBIC is a less aggressive variant of BIC (meaning, it doesn't steal as much throughput from competing TCP flows as does BIC).</p><p><span style=\" font-weight:600;\">TCP Hybla</span></p><p>TCP Hybla was proposed in order to transmit data efficiently over satellite links and &quot;defend&quot; the transmission against TCP flows from other origins.</p><p><span style=\" font-weight:600;\">TCP Low Priority (lp)</span></p><p>This is an approach to develop an algorithm that uses excess bandwidth for TCP flows. It can be used for low priority data transfers without &quot;disturbing&quot; other TCP transmissions (which probably don't use TCP Low Priority).</p><p><span style=\" font-weight:600;\">TCP Tahoe/Reno</s"
                        "pan></p><p>These are the classical models used for congestion control. They exhibit the typical slow start of transmissions. The throughput increases gradually until it stays stable. It is decreased as soon as the transfer encounters congestion, then the rate rises again slowly. The window is increased by adding fixed values. TCP Reno uses a multiplicative decrease algorithm for the reduction of window size. TCP Reno is the most widely deployed algorithm.</p><p><span style=\" font-weight:600;\">TCP Vegas</span></p><p>TCP Vegas introduces the measurement of RTT for evaluating the link quality. It uses additive increases and additive decreases for the congestion window.</p><p><span style=\" font-weight:600;\">TCP Veno</span></p><p>This variant is optimised for wireless networks, since it was designed to handle random packet loss better. It tries to keep track of the transfer, and guesses if the quality decreases due to congestion or random packet errors.</p><p><span style=\" font-weight:600;\">TCP Westwood+</spa"
                        "n></p><p>Westwood+ addresses both large bandwidth/RTT values and random packet loss together with dynamically changing network loads. It analyses the state of the transfer by looking at the acknowledgement packets. Westwood+ is a modification of the TCP Reno algorithm.</p><p><br/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_4->setText(QApplication::translate("kupagui", "tcp_cc", 0));
        tabWidget->setTabText(tabWidget->indexOf(IperfTCP), QApplication::translate("kupagui", "Iperf-TCP", 0));
        tcp_download_2->setText(QApplication::translate("kupagui", "Download", 0));
        tcp_upload_2->setText(QApplication::translate("kupagui", "Upload", 0));
        label_12->setText(QApplication::translate("kupagui", "UDP allocated bandwidth", 0));
        label_18->setText(QApplication::translate("kupagui", "Mbps", 0));
#ifndef QT_NO_WHATSTHIS
        iperf_time_2->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>time to do iperf. simulation will add 10 more seconds</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_23->setText(QApplication::translate("kupagui", "Iperf TIme (s)", 0));
        tabWidget->setTabText(tabWidget->indexOf(IperfUDP), QApplication::translate("kupagui", "Iperf-UDP", 0));
#ifndef QT_NO_TOOLTIP
        tcp_mem_user_2->setToolTip(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tcp_mem_user_2->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        tcp_mem_user_2->setText(QApplication::translate("kupagui", "4096 8192 8388608", 0));
#ifndef QT_NO_TOOLTIP
        tcp_mem_server_2->setToolTip(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tcp_mem_server_2->setWhatsThis(QApplication::translate("kupagui", "<html><head/><body><p>put 3 values in bytes, can be separated by comma or space</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
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
        jitter_check->setText(QApplication::translate("kupagui", "jitter", 0));
        label_20->setText(QApplication::translate("kupagui", "alpha", 0));
        label_21->setText(QApplication::translate("kupagui", "tetha", 0));
        label_22->setText(QApplication::translate("kupagui", "k", 0));
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
        button_getResult->setText(QApplication::translate("kupagui", "get result", 0));
        button_exit->setText(QApplication::translate("kupagui", "exit", 0));
        label_19->setText(QApplication::translate("kupagui", "DCE Source:", 0));
        dce_source->setText(QApplication::translate("kupagui", "/home/aneta/aneta-kupa/source/ns-3-dce", 0));
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
