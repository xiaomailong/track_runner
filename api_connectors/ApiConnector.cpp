#include "api_connectors/ApiConnector.hpp"

QPointer<TrainSearchRequest> ApiConnector::getTrainSearchRequest(){
    if(!this->search_request){
        throw new ApiConnectorException("TrainSearchRequest was not set to ApiConnector subclass", ApiConnector::EXCEPTION_TRAIN_SEARCH_REQUEST_NOT_SET);
    }
    else{
        return this->search_request;
    }
}

void ApiConnector::setTrainSearchRequest(QPointer<TrainSearchRequest> request){
    this->search_request = request;
}

short unsigned int ApiConnector::getState(){
    return this->state;
}

void ApiConnector::setState(connector_state state){
    this->state = state;
}


