QT += network

SOURCES += api_connectors/ApiConnector.cpp \
    $$PWD/PlkApiConnector/PlkApiConnector.cpp \
    $$PWD/PlkApiConnector/PlkApiQueryBuilder.cpp \
    $$PWD/PlkApiConnector/PlkApiResponseParser.cpp \
    $$PWD/ApiConnectorExceptions.cpp
HEADERS  += api_connectors/ApiConnector.hpp \
    $$PWD/PlkApiConnector/PlkApiConnector.hpp \
    $$PWD/PlkApiConnector/PlkApiQueryBuilder.hpp \
    $$PWD/PlkApiConnector/PlkApiResponseParser.hpp \
    $$PWD/ApiConnectorExceptions.hpp
