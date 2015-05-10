#include "PlkApiConnector.hpp"


PlkApiConnector::PlkApiConnector(QObject *parent): ApiConnector(parent){
    this->setState(ApiConnector::STATE_IDLE);
    this->network_request = NULL;
    this->network_access_manager = new QNetworkAccessManager(this);
    QObject::connect(this->network_access_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(parseResponse(QNetworkReply*)));
}

void PlkApiConnector::processTrainSearchRequest(QPointer<TrainSearchRequest> request){
    if(this->getState() != ApiConnector::STATE_IDLE){
        throw new ApiConnectorException("One PlkApiConnector instance can process only one request at once");
    }
    this->setState(ApiConnector::STATE_REQUEST_ISSUED);
    this->setTrainSearchRequest(request);
    this->configureForConnectionWithPlk();
    this->network_reply =  this->network_access_manager->post(*this->network_request, PlkApiQueryBuilder::getJsonStringFor(this->getTrainSearchRequest()).toUtf8());
}


void PlkApiConnector::configureForConnectionWithPlk(){
    if(this->network_request != NULL){
       return;
    }
    this->network_request = new QNetworkRequest();
    this->network_request->setUrl(QUrl("http://wcf.rozklad.plk-sa.pl/wcf20100/Rozklad.svc/C"));
    this->network_request->setRawHeader("Content-Type", "application/json; charset=UTF-8");
    this->network_request->setRawHeader("X-Requested-With", "pl.plksa.RozkladJazdy");
    this->network_request->setRawHeader("User-Agent", "Mozilla/5.0 (Linux; Android 4.4.2; VirtualBox Build/KVT49L) AppleWebKit/537.36 (KHTML, like Gecko) Version/4.0 Chrome/30.0.0.0 Safari/537.36");
    this->network_request->setRawHeader("Accept-Encoding", "gzip,deflate");
}

void PlkApiConnector::parseResponse(QNetworkReply *repl){
    this->setState(ApiConnector::STATE_AFTER_REQUEST);
    QByteArray raw_response = repl->readAll();
    QPointer<TrainTimetable> timetable = PlkApiResponseParser::parseResponse(raw_response);
    emit this->onProcessTrainSearchRequestFinished(timetable);
    this->setState(ApiConnector::STATE_IDLE);
}


