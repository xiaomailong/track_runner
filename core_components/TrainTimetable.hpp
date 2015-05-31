#ifndef QUERYSERVERRESPONSE_HPP
#define QUERYSERVERRESPONSE_HPP

#include <QList>
#include <QPointer>

#include "core_components/TrainConnection.hpp"

class TrainTimetable : public QObject
{
    Q_OBJECT

    QList<QPointer<TrainConnection> > connections;

public:
    explicit TrainTimetable(QObject *parent = 0);
    void addConnection(QPointer<TrainConnection> connection);
    int size();
    QPointer<TrainConnection> at(int index);

signals:

public slots:
};

#endif // QUERYSERVERRESPONSE_HPP
