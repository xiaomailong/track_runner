#ifndef API_CONNECTOR_HPP
#define API_CONNECTOR_HPP

#include <QObject>
#include <QDateTime>
#include <QtNetwork/QNetworkRequest>
#include <QPointer>

#include "core_components/TrainTimetable.hpp"
#include "core_components/TrainSearchRequest.hpp"
#include "api_connectors/ApiConnectorExceptions.hpp"

#include <QPointer>

typedef short unsigned int connector_state;

class ApiConnector: public QObject{

    Q_OBJECT

private:

    static const unsigned short default_limit = 5;
    static const bool supports_carrier_names = false;
    static const bool supports_travel_durations = false;

    QPointer<TrainSearchRequest> search_request;

    short unsigned int limit;
    short unsigned int state;

protected:
    void setState(connector_state state);

signals:
    void onProcessTrainSearchRequestFinished(QPointer<TrainTimetable> server_response);

    void connectionErrorOccured(QString message);
    void processingErrorOccured(QString message);

public slots:
    virtual void processTrainSearchRequest(QPointer<TrainSearchRequest> request) = 0;
    void setTrainSearchRequest(QPointer<TrainSearchRequest> request);


public:

    ApiConnector(QObject * parent): QObject(parent){}
    ~ApiConnector(){}

    static const connector_state STATE_IDLE = 1;
    static const connector_state STATE_REQUEST_ISSUED = 2;
    static const connector_state STATE_AFTER_REQUEST = 3;

    short unsigned int getState();

    QPointer<TrainSearchRequest> getTrainSearchRequest();


    static const exception_code EXCEPTION_TRAIN_SEARCH_REQUEST_NOT_SET = 1;
};


#endif
