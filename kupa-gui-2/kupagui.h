#ifndef KUPAGUI_H
#define KUPAGUI_H

#include <QMainWindow>
#include <string.h>
#include <stdio.h>
#include <QAbstractButton>
#include <QXmlStreamReader>
#include "tinyxml.h"

namespace Ui {
class kupagui;

}

class kupagui : public QMainWindow
{
    Q_OBJECT

public:
    explicit kupagui(QWidget *parent = 0);
    ~kupagui();

private slots:
    void on_button_run_clicked();
  void on_button_generate_command_clicked();
  void on_actionLoad_Command_triggered();
private:
    Ui::kupagui *ui;
    //string loadTextFile();
};
extern QString TypeOfConnection;
#endif // KUPAGUI_H
