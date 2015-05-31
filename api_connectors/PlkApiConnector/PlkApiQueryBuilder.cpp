#include "PlkApiQueryBuilder.hpp"

PlkApiQueryBuilder::PlkApiQueryBuilder(QObject *parent) : QObject(parent)
{

}

PlkApiQueryBuilder::~PlkApiQueryBuilder(){

}

void PlkApiQueryBuilder::setTrainSearchRequest(QPointer<TrainSearchRequest> request){
    this->request = request;
}

QPointer<TrainSearchRequest> PlkApiQueryBuilder::getTrainSearchRequest(){
    if(this->request){
        return this->request;
    }
    throw new ApiConnectorException("TrainSearchRequest is not set on PlkApiQueryBuilder", PlkApiQueryBuilder::TRAIN_SEARCH_REQUEST_NOT_SET);
}

QString PlkApiQueryBuilder::getJsonString(){

    if(this->getTrainSearchRequest() == NULL){
        return QString("");
    }

    QString start_date = DatetimeUtils::formatDate(this->getTrainSearchRequest()->getJourneyStartDate());
    QString start_hour = DatetimeUtils::formatHour(this->getTrainSearchRequest()->getJourneyStartDate());

    QString source = this->getTrainSearchRequest()->getSource();
    QString destination = this->getTrainSearchRequest()->getDestination();

    QString json = "{\"C\":5,\"N\":0,\"S\":\"" + source + "\",\"T\":\"" + destination + "\",\"V\":\"\",\"O\":true,\"B\":false,\"CP\":10,\"D\":\"" + start_date + " " + start_hour +  "\",\"TS\":[\"SZ\",\"DA\",\"LO\",\"AG\"],\"CS\":[\"AR\",\"CARGO\",\"IC\",\"KD\",\"KM\",\"KS\",\"KW\",\"LKA\",\"ODEG\",\"PR\",\"SKM\",\"SKM_3M\",\"WKD\"],\"PS\":[]}";
    return json;

}

QString PlkApiQueryBuilder::getJsonStringFor(QPointer<TrainSearchRequest> request){
    PlkApiQueryBuilder builder;
    builder.setTrainSearchRequest(request);
    return builder.getJsonString();
}
