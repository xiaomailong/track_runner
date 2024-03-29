#ifndef GUIVIEW_HPP
#define GUIVIEW_HPP

#include <QWidget>
#include <core_components/TrainSearchRequest.hpp>
#include <core_components/TrainConnection.hpp>
#include <core_components/TrainTimetable.hpp>

class GuiView : public QWidget
{
public:
    explicit GuiView(QWidget *parent = 0);

signals:
    void requestTimetable(QPointer<TrainSearchRequest> train_search_request);

public slots:
    virtual void timetableRequestFinished(QPointer<TrainTimetable> timetable) = 0;
    virtual void displayError(QString error_message) = 0;
};

#endif // GUIVIEW_HPP
