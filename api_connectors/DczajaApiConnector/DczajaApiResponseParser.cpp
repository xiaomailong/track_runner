#include "DczajaApiResponseParser.hpp"

DczajaApiResponseParser::DczajaApiResponseParser(QObject *parent) : QObject(parent)
{

}

QPointer<TrainTimetable> DczajaApiResponseParser::parseResponse(QByteArray response){

    qDebug() << response;

    QPointer<TrainTimetable> timetable = new TrainTimetable();

    QJsonParseError err;

    if(err.error != QJsonParseError::NoError){
        throw new NotJsonResponseException("The response from the server did not contain valid JSON. Error message: " + err.errorString());
    }

    QJsonDocument doc = QJsonDocument::fromJson(response, &err);
    QJsonObject json_root = doc.object();
    QJsonArray json_connections = json_root["connections"].toArray();
    QString json_travel_source =  json_root["start"].toString();
    QString json_travel_destination =  json_root["end"].toString();



    for(int i=0; i< json_connections.size(); i++){

        QJsonObject single_result = json_connections[i].toObject();

        QPointer<TrainConnection> connection = new TrainConnection();
        connection->setSource(json_travel_source);
        connection->setDestination(json_travel_destination);
        QString departure = single_result["dateStart"].toString() + " " + single_result["departure"].toString();
        QString arrival = single_result["dateStart"].toString() + " " + single_result["arrival"].toString();
        qDebug() << departure;
        connection->setJourneyStartDate(QDateTime::fromString(departure, "dd.MM.yy HH:mm"));
        connection->setJourneyEndDate(QDateTime::fromString(arrival, "dd.MM.yy HH:mm"));

        QStringList train_types;
        QJsonArray trains = single_result["trains"].toArray();
        for(int j=0;j<trains.size();j++){
            QJsonObject curr_train = trains[j].toObject();
            train_types.append(curr_train["carrier"].toString());
        }
        connection->setCarrierName(train_types.join(","));
        timetable->addConnection(connection);
    }


    return timetable;
}

