#include "GuiController.hpp"

GuiController::GuiController(ApiConnector *connector, GuiView *view, QObject *parent) : QObject(parent)
{
    this->connector = connector;
    this->view = view;
    QObject::connect(this->view, SIGNAL(requestTimetable(QPointer<TrainSearchRequest>)), this->connector, SLOT(processTrainSearchRequest(QPointer<TrainSearchRequest>)));
    QObject::connect(this->connector, SIGNAL(onProcessTrainSearchRequestFinished(QPointer<TrainTimetable>)), this->view, SLOT(timetableRequestFinished(QPointer<TrainTimetable>)));
    QObject::connect(this->connector, SIGNAL(processingErrorOccured(QString)), this->view,SLOT(displayError(QString)));
    QObject::connect(this->connector, SIGNAL(connectionErrorOccured(QString)), this->view,SLOT(displayError(QString)));
    #ifdef __ANDROID_API__
        this->view->showFullScreen();
    #else
    this->view->show();
    #endif


}

