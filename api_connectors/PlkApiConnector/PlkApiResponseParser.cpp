#include "PlkApiResponseParser.hpp"

PlkApiResponseParser::PlkApiResponseParser(QObject *parent) : QObject(parent)
{

}

QPointer<TrainTimetable> PlkApiResponseParser::parseResponse(QByteArray response){


    QPointer<TrainTimetable> timetable = new TrainTimetable();

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(response, &err);
    QJsonObject json_root = doc.object();
    QJsonArray json_connections = json_root["P"].toArray();
    QString json_travel_source =  json_root["S"].toString();
    QString json_travel_destination =  json_root["T"].toString();

    if(err.error != QJsonParseError::NoError){
        throw new NotJsonResponseException("The response drom the server did not contain valid JSON. " + err.errorString());
    }

    for(int i=0; i< json_connections.size(); i++){

        QJsonObject single_result = json_connections[i].toObject();

        QPointer<TrainConnection> connection = new TrainConnection();
        connection->setSource(json_travel_source);
        connection->setDestination(json_travel_destination);
        connection->setJourneyStartDate(QDateTime::fromString(single_result["O"].toString(), "dd.MM.yyyy HH:mm"));
        connection->setJourneyEndDate(QDateTime::fromString(single_result["P"].toString(), "dd.MM.yyyy HH:mm"));



        QStringList train_types;
        QJsonArray trains = single_result["N"].toArray();
        for(int j=0;j<trains.size();j++){
            QJsonObject curr_train = trains[j].toObject();
            train_types.append(curr_train["P"].toString());
        }
        connection->setCarrierName(train_types.join(","));
        timetable->addConnection(connection);
    }


    return timetable;
}

