#ifndef DCZAJAAPIRESPONSEPARSER_HPP
#define DCZAJAAPIRESPONSEPARSER_HPP

#include <QObject>

class DczajaApiResponseParser : public QObject
{
    Q_OBJECT
public:
    explicit DczajaApiResponseParser(QObject *parent = 0);

signals:

public slots:
};

#endif // DCZAJAAPIRESPONSEPARSER_HPP
