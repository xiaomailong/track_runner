#ifndef TRAINTIMETABLEMODEL_HPP
#define TRAINTIMETABLEMODEL_HPP

#include <QStandardItemModel>
#include <QPointer>
#include <QDebug>
#include <Qt>

#include "core_components/DatetimeUtils.hpp"
#include "core_components/TrainTimetable.hpp"

class TrainTimetableModel : public QAbstractTableModel
{
    Q_OBJECT

    QPointer<TrainTimetable> train_timetable;

protected:

public:
    TrainTimetableModel(QObject *parent = 0);
    TrainTimetableModel(QPointer<TrainTimetable> train_timetable);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

public slots:
    void setTimetable(QPointer<TrainTimetable> train_timetable);
};

#endif // TRAINTIMETABLEMODEL_HPP
