#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include "api_connectors/PlkApiConnector/PlkApiConnector.hpp"
#include "core_components/TrainSearchRequest.hpp"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    TrainSearchRequest *tsr = new TrainSearchRequest();
    tsr->setSource("Legnica");
    tsr->setDestination("Wrocław");
    tsr->setJourneyStartDate(QDateTime::currentDateTime());

    PlkApiConnector *connector  = new PlkApiConnector();
    connector->processTrainSearchRequest(tsr);
}
