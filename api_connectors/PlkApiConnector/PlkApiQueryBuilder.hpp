#ifndef PLKAPIQUERYBUILDER_HPP
#define PLKAPIQUERYBUILDER_HPP

#include <QObject>
#include <QPointer>

#include "core_components/DatetimeUtils.hpp"
#include "api_connectors/ApiConnectorExceptions.hpp"
#include "core_components/TrainSearchRequest.hpp"

class PlkApiQueryBuilder : public QObject
{
    Q_OBJECT

    QPointer<TrainSearchRequest> request;

public:

    explicit PlkApiQueryBuilder(QObject *parent = 0);
    ~PlkApiQueryBuilder();

    void setTrainSearchRequest(QPointer<TrainSearchRequest> request);

    QPointer<TrainSearchRequest> getTrainSearchRequest();
    QString getJsonString();


    static QString getJsonStringFor(QPointer<TrainSearchRequest> request);
    static const exception_code TRAIN_SEARCH_REQUEST_NOT_SET = 1;

signals:

public slots:
};

#endif // PLKAPIQUERYBUILDER_HPP
