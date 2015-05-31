#ifndef DCZAJAAPICONNECTOR_HPP
#define DCZAJAAPICONNECTOR_HPP


#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

#include <QPointer>
#include <QUrlQuery>

#include "api_connectors/ApiConnector.hpp"
#include "core_components/DatetimeUtils.hpp"
#include "api_connectors/DczajaApiConnector/DczajaApiResponseParser.hpp"

class DczajaApiConnector : public ApiConnector
{

    Q_OBJECT


    QString getJsonRequest();

    QPointer<QNetworkAccessManager> network_access_manager;
    QPointer<QNetworkReply> network_reply;
    QNetworkRequest *network_request;

    void configureForConnectionWithDczaja();

public:
    DczajaApiConnector(QObject * parent = 0);

public slots:
    void parseResponse(QNetworkReply *repl);
    void processTrainSearchRequest(QPointer<TrainSearchRequest> network_request);
};
#endif // DCZAJAAPICONNECTOR_HPP
