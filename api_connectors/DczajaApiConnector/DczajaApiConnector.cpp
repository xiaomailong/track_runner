#include "DczajaApiConnector.hpp"


DczajaApiConnector::DczajaApiConnector(QObject *parent): ApiConnector(parent){
    this->setState(ApiConnector::STATE_IDLE);
    this->network_request = NULL;
    this->network_access_manager = new QNetworkAccessManager(this);
    QObject::connect(this->network_access_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(parseResponse(QNetworkReply*)));
}

void DczajaApiConnector::processTrainSearchRequest(QPointer<TrainSearchRequest> request){
    try{
        if(this->getState() != ApiConnector::STATE_IDLE){
            throw new ApiConnectorException("One DczajaApiConnector instance can process only one request at once");
        }
        this->setState(ApiConnector::STATE_REQUEST_ISSUED);
        this->setTrainSearchRequest(request);
        this->configureForConnectionWithDczaja();
        this->network_reply =  this->network_access_manager->get(*this->network_request);
    }catch(ApiConnectorException* exception){
        this->setState(ApiConnector::STATE_IDLE);
        emit this->processingErrorOccured(exception->what());
    }catch(NotJsonResponseException* exception){
        this->setState(ApiConnector::STATE_IDLE);
        emit this->connectionErrorOccured(exception->what());
    }
}


void DczajaApiConnector::configureForConnectionWithDczaja(){
    if(this->network_request != NULL){
        return;
    }
    this->network_request = new QNetworkRequest();
    QUrl url = QUrl("http://94.23.254.81/~rozkladpkp/cgi-bin/get_connection.py");

    QUrlQuery get_params;
    get_params.addQueryItem("tlk", "1");
    get_params.addQueryItem("eic", "1");
    get_params.addQueryItem("regio", "1");
    get_params.addQueryItem("time", DatetimeUtils::formatHour(this->getTrainSearchRequest()->getJourneyStartDate()));
    get_params.addQueryItem("date", DatetimeUtils::formatDate(this->getTrainSearchRequest()->getJourneyStartDate()));
    get_params.addQueryItem("start", this->getTrainSearchRequest()->getSource());
    get_params.addQueryItem("end", this->getTrainSearchRequest()->getDestination());
    get_params.addQueryItem("direct", "1");
    get_params.addQueryItem("is_departure", "1");
    get_params.addQueryItem("speed", "1");
    url.setQuery(get_params);

    this->network_request->setUrl(url);
    this->network_request->setRawHeader("Content-Type", "application/json; charset=UTF-8");
    this->network_request->setRawHeader("X-Requested-With", "track_runner");
    this->network_request->setRawHeader("User-Agent", "Track Runner https://github.com/glothriel/track_runner");
    this->network_request->setRawHeader("Accept-Encoding", "gzip,deflate");
}

void DczajaApiConnector::parseResponse(QNetworkReply *repl){
    try{
        if(repl->error() != QNetworkReply::NoError){
            throw new ApiConnectorException("Nie udało się połaczyć z serwerem.");
        }
        this->setState(ApiConnector::STATE_AFTER_REQUEST);
        QByteArray raw_response = repl->readAll();
        QPointer<TrainTimetable> timetable = DczajaApiResponseParser::parseResponse(raw_response);
        emit this->onProcessTrainSearchRequestFinished(timetable);

        this->setState(ApiConnector::STATE_IDLE);
    }catch(ApiConnectorException* exception){
        this->setState(ApiConnector::STATE_IDLE);
        emit this->connectionErrorOccured(exception->what());
    }catch(NotJsonResponseException* exception){
        emit this->processingErrorOccured(exception->what());
    }
}


