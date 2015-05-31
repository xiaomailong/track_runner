#include "TrainTimetableModel.hpp"

TrainTimetableModel::TrainTimetableModel(QObject *parent)  : QAbstractTableModel(parent)
{

}

TrainTimetableModel::TrainTimetableModel(QPointer<TrainTimetable> train_timetable) : QAbstractTableModel(0){
    this->setTimetable(train_timetable);
}

int TrainTimetableModel::rowCount(const QModelIndex &parent) const{
    int siz = this->train_timetable->size();
    return this->train_timetable->size();
}

int TrainTimetableModel::columnCount(const QModelIndex &parent) const{
    return 3;
}

QVariant TrainTimetableModel::data(const QModelIndex &index, int role) const{
    if(!this->train_timetable || !role==Qt::DisplayRole){
        return QVariant();
    }
    if(index.column() == 0){
        return this->train_timetable->at(index.row())->getSource();
    }else if(index.column() == 1){
        return this->train_timetable->at(index.row())->getDestination();
    }else{
        return DatetimeUtils::formatHour(this->train_timetable->at(index.row())->getJourneyStartDate());
    }
}

void TrainTimetableModel::setTimetable(QPointer<TrainTimetable> train_timetable){

        this->train_timetable = train_timetable;

}
