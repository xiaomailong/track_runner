#ifndef APICONNECTOREXCEPTION_HPP
#define APICONNECTOREXCEPTION_HPP

#include <QObject>

typedef unsigned short int exception_code;

class ApiConnectorException : public QObject
{
    Q_OBJECT

    QString message;
    exception_code code;

public:

    explicit ApiConnectorException(QString errorMessage, exception_code code = 0);
    QString errorMessage();
    exception_code getCode();

    const char* what(){
          return this->errorMessage().toStdString().c_str();
       }
};

class NotJsonResponseException : public ApiConnectorException{
public:
    NotJsonResponseException(QString what, exception_code code = 0) : ApiConnectorException(what, code) {}
};

#endif // APICONNECTOREXCEPTION_HPP
