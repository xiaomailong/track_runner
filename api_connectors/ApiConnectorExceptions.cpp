#include "ApiConnectorExceptions.hpp"

ApiConnectorException::ApiConnectorException(QString what, exception_code code)
{
    this->message = what;
    this->code = code;
}

QString ApiConnectorException::errorMessage(){
    return this->message;
}

exception_code ApiConnectorException::getCode(){
    return this->code;
}
