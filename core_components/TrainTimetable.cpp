#include "TrainTimetable.hpp"

TrainTimetable::TrainTimetable(QObject *parent) : QObject(parent)
{

}

void TrainTimetable::addConnection(QPointer<TrainConnection> connection){
    this->connections.push_back(connection);
}
