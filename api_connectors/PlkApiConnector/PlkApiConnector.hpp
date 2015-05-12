#ifndef PLKAPICONNECTOR_HPP
#define PLKAPICONNECTOR_HPP

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

#include <QPointer>

#include "api_connectors/ApiConnector.hpp"
#include "api_connectors/PlkApiConnector/PlkApiQueryBuilder.hpp"
#include "api_connectors/PlkApiConnector/PlkApiResponseParser.hpp"

class PlkApiConnector : public ApiConnector
{

    Q_OBJECT


    QString getJsonRequest();

    QPointer<QNetworkAccessManager> network_access_manager;
    QPointer<QNetworkReply> network_reply;
    QNetworkRequest *network_request;

    void configureForConnectionWithPlk();

public:
    PlkApiConnector(QObject * parent = 0);

public slots:
    void parseResponse(QNetworkReply *repl);
    void processTrainSearchRequest(QPointer<TrainSearchRequest> network_request);
};

#endif // PLKAPICONNECTOR_HPP
