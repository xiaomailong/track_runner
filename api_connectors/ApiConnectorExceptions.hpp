#ifndef APICONNECTOREXCEPTION_HPP
#define APICONNECTOREXCEPTION_HPP

#include <QObject>

class ApiConnectorException : public QObject
{
    Q_OBJECT
public:
    explicit ApiConnectorException(QObject *parent = 0);

signals:

public slots:
};

#endif // APICONNECTOREXCEPTION_HPP
