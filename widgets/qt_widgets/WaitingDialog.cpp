#include "WaitingDialog.hpp"
#include "ui_WaitingDialog.h"

WaitingDialog::WaitingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WaitingDialog)
{
    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    ui->setupUi(this);
    QMovie *movie = new QMovie(":/images/resources/725.GIF");
    this->ui->label->setMovie(movie);
    movie->start();
    this->hide();
}

WaitingDialog::~WaitingDialog()
{
    delete ui;
}
