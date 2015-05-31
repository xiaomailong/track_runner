#ifndef DCZAJAAPIRESPONSEPARSER_HPP
#define DCZAJAAPIRESPONSEPARSER_HPP


#include <QObject>
#include <QPointer>
#include <QDebug>

#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include <QStringList>

#include "api_connectors/ApiConnectorExceptions.hpp"
#include "core_components/TrainTimetable.hpp"
#include "core_components/DatetimeUtils.hpp"

class DczajaApiResponseParser : public QObject
{
    Q_OBJECT

    explicit DczajaApiResponseParser(QObject *parent = 0);

public:
    static QPointer<TrainTimetable> parseResponse(QByteArray response);

signals:

public slots:
};

#endif // DCZAJAAPIRESPONSEPARSER_HPP
