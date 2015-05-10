#include "TrainSearchRequest.hpp"

TrainSearchRequest::TrainSearchRequest(QObject *parent) : QObject(parent)
{

}

void TrainSearchRequest::setCarrierName(QString name){
    this->carrier_name = name;
}

void TrainSearchRequest::setSource(QString source){
    this->source = source;
}

void TrainSearchRequest::setDestination(QString destination){
    this->destination = destination;
}

void TrainSearchRequest::setJourneyEndDate(QDateTime date){
    this->journey_end_date = date;
}


void TrainSearchRequest::setJourneyStartDate(QDateTime date){
    this->journey_start_date = date;
}

void TrainSearchRequest::setTravelDuration(QTime duration){
    this->travel_duration = duration;
}

QString TrainSearchRequest::getSource(){
    return this->source;
}

QString TrainSearchRequest::getDestination(){
    return this->destination;
}

QDateTime TrainSearchRequest::getJourneyStartDate(){
    return this->journey_start_date;
}

QDateTime TrainSearchRequest::getJourneyEndDate(){
    return this->journey_end_date;
}

QTime TrainSearchRequest::getTravelDuration(){
    return this->travel_duration;
}

QString TrainSearchRequest::getCarrierName(){
    return this->carrier_name;
}
