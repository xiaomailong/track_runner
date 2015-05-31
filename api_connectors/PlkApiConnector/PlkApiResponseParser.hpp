#ifndef PLKAPISERVERPROTOCOL_HPP
#define PLKAPISERVERPROTOCOL_HPP

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

class PlkApiResponseParser : public QObject
{
    Q_OBJECT

    explicit PlkApiResponseParser(QObject *parent = 0);
public:
    static QPointer<TrainTimetable> parseResponse(QByteArray response);
};

#endif // PLKAPISERVERPROTOCOL_HPP
