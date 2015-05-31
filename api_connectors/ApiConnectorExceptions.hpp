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

    ApiConnectorException(QString what, exception_code code = 0)
    {
        this->message = what;
        this->code = code;
    }
    QString errorMessage(){
        return this->message;
    }
    exception_code getCode(){
        return this->code;
    }

    const char* what(){
          return this->errorMessage().toStdString().c_str();
       }
};

class NotJsonResponseException : public ApiConnectorException{
public:
    NotJsonResponseException(QString what, exception_code code = 0) : ApiConnectorException(what, code) {}
};

#endif // APICONNECTOREXCEPTION_HPP
