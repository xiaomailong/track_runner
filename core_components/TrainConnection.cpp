#include "TrainConnection.hpp"

TrainConnection::TrainConnection(QObject *parent) : QObject(parent)
{

}

void TrainConnection::setCarrierName(QString name){
    this->carrier_name = name;
}

void TrainConnection::setSource(QString source){
    this->source = source;
}


void TrainConnection::setDestination(QString destination){
    this->destination = destination;
}

void TrainConnection::setJourneyEndDate(QDateTime date){
    this->journey_end_date = date;
}


void TrainConnection::setJourneyStartDate(QDateTime date){
    this->journey_start_date = date;
}

void TrainConnection::setTravelDuration(QTime duration){
    this->travel_duration = duration;
}
