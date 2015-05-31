#include "TrainTimetable.hpp"

TrainTimetable::TrainTimetable(QObject *parent) : QObject(parent)
{

}

void TrainTimetable::addConnection(QPointer<TrainConnection> connection){
    this->connections.push_back(connection);
}

int TrainTimetable::size(){
    return this->connections.size();
}

QPointer<TrainConnection> TrainTimetable::at(int index){
    if(this->size() > index){
        return this->connections.at(index);
    }else{
        return 0;
    }
}
