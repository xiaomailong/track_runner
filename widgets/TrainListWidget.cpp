#include "TrainListWidget.hpp"
#include "ui_TrainListWidget.h"

TrainListWidget::TrainListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrainListWidget)
{
    ui->setupUi(this);
}

TrainListWidget::~TrainListWidget()
{
    delete ui;
}
