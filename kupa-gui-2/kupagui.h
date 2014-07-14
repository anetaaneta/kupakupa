#ifndef KUPAGUI_H
#define KUPAGUI_H

#include <QMainWindow>
#include <string.h>
#include <stdio.h>
#include <QAbstractButton>

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
    void on_button_generate_command_clicked();

private:
    Ui::kupagui *ui;
    //string loadTextFile();
};

#endif // KUPAGUI_H
