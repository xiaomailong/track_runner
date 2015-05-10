#ifndef QUERYSERVERERROR_HPP
#define QUERYSERVERERROR_HPP

#include <QObject>
#include <QVariant>

class QueryServerError : public QObject
{
    Q_OBJECT

    QString description;
    unsigned short code;
    static QVariant definitions;

    explicit QueryServerError(QObject *parent = 0);
    static void updateDefinitions();

public:

    static QueryServerError *getById(QString error_code);

signals:

public slots:
};

#endif // QUERYSERVERERROR_HPP
