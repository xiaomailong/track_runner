#ifndef GUICONTROLLER_HPP
#define GUICONTROLLER_HPP

#include <QObject>

#include <api_connectors/ApiConnector.hpp>
#include <widgets/GuiView.hpp>

class GuiController : public QObject
{
    Q_OBJECT

    ApiConnector *connector;
    GuiView *view;

public:
    explicit GuiController(ApiConnector *connector, GuiView *view, QObject *parent = 0);

signals:

public slots:
};

#endif // GUICONTROLLER_HPP
