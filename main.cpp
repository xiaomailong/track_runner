#include <QApplication>
#include "widgets/qt_widgets/TrainListWidget.hpp"
#include "api_connectors/PlkApiConnector/PlkApiConnector.hpp"
#include "api_connectors/DczajaApiConnector/DczajaApiConnector.hpp"
#include "widgets/GuiController.hpp"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    TrainListWidget *widget = new TrainListWidget();
    PlkApiConnector *con = new PlkApiConnector();
    DczajaApiConnector *czajacon = new DczajaApiConnector();

    GuiController *ctrlr = new GuiController(con,widget,&a);
    return a.exec();
}
