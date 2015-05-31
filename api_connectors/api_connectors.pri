QT += network

SOURCES += api_connectors/ApiConnector.cpp \
    $$PWD/PlkApiConnector/PlkApiConnector.cpp \
    $$PWD/PlkApiConnector/PlkApiQueryBuilder.cpp \
    $$PWD/PlkApiConnector/PlkApiResponseParser.cpp \
    $$PWD/ApiConnectorExceptions.cpp \
    $$PWD/DczajaApiConnector/DczajaApiConnector.cpp \
    $$PWD/DczajaApiConnector/DczajaApiResponseParser.cpp
HEADERS  += api_connectors/ApiConnector.hpp \
    $$PWD/PlkApiConnector/PlkApiConnector.hpp \
    $$PWD/PlkApiConnector/PlkApiQueryBuilder.hpp \
    $$PWD/PlkApiConnector/PlkApiResponseParser.hpp \
    $$PWD/ApiConnectorExceptions.hpp \
    $$PWD/DczajaApiConnector/DczajaApiConnector.hpp \
    $$PWD/DczajaApiConnector/DczajaApiResponseParser.hpp
