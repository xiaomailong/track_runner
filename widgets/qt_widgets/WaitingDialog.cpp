#include "WaitingDialog.hpp"
#include "ui_WaitingDialog.h"

WaitingDialog::WaitingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WaitingDialog)
{
    ui->setupUi(this);
}

WaitingDialog::~WaitingDialog()
{
    delete ui;
}
