#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->btn0,QPushButton::clicked,this,Dialog::append);
    connect(ui->btn1,QPushButton::clicked,this,Dialog::append);
    connect(ui->btn2,QPushButton::clicked,this,Dialog::append);
    connect(ui->btn3,QPushButton::clicked,this,Dialog::append);
    connect(ui->btn4,QPushButton::clicked,this,Dialog::append);
    connect(ui->btn5,QPushButton::clicked,this,Dialog::append);
    connect(ui->btn6,QPushButton::clicked,this,Dialog::append);
    connect(ui->btn7,QPushButton::clicked,this,Dialog::append);
    connect(ui->btn8,QPushButton::clicked,this,Dialog::append);
    connect(ui->btn9,QPushButton::clicked,this,Dialog::append);
    connect(ui->btnSave,QPushButton::clicked,this,Dialog::save);
    connect(ui->btnVerify,QPushButton::clicked,this,Dialog::verify);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::append()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if(!btn) return;
    temp += btn->text();
    ui->lblNotify->setText("Code: " + temp);
    if(code.isEmpty()){
        ui->btnSave->setEnabled(true);
        ui->btnVerify->setEnabled(false);
    } else {
        ui->btnSave->setEnabled(false);
        ui->btnVerify->setEnabled(true);
    }
}

void Dialog::save()
{
    code = temp;
    temp.clear();
    ui->lblNotify->setText("Code has been saved, now try to verify that");
    QMessageBox::information(this,"Saved","Code has been saved, now try to verify that");
    ui->btnSave->setEnabled(false);
}

void Dialog::verify()
{
    if(temp == code){
        ui->lblNotify->setText("Please Enter code and hit Save");
        QMessageBox::information(this,"Verified", "Code was correct, you are verified");
        code.clear();
        temp.clear();
        ui->btnSave->setEnabled(false);
        ui->btnVerify->setEnabled(false);
    } else {
        ui->lblNotify->setText("Code doesn't match, try again");
        QMessageBox::critical(this,"Not Verified", "Code doesn't match, try again");
        temp.clear();
    }
}


