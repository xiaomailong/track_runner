#ifndef TRAINSEARCHREQUEST_HPP
#define TRAINSEARCHREQUEST_HPP

#include <QObject>
#include <QDateTime>
#include <QTime>

class TrainSearchRequest : public QObject
{
    Q_OBJECT

    QString source;
    QString destination;

    QDateTime journey_start_date;
    QDateTime journey_end_date;

    QTime travel_duration;

    QString carrier_name;


public:
    explicit TrainSearchRequest(QObject *parent = 0);

    void setSource(QString source);
    void setDestination(QString destination);
    void setJourneyStartDate(QDateTime date);
    void setJourneyEndDate(QDateTime date);
    void setTravelDuration(QTime duration);
    void setCarrierName(QString name);

    QString getSource();
    QString getDestination();
    QDateTime getJourneyStartDate();
    QDateTime getJourneyEndDate();
    QTime getTravelDuration();
    QString getCarrierName();

signals:

public slots:
};

#endif // TRAINSEARCHREQUEST_HPP
