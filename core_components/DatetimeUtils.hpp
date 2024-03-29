#ifndef DATE_TIME_UTILS
#define DATE_TIME_UTILS

#include <QDateTime>

class DatetimeUtils {

public:

    static QString DEFAULT_DATE_FORMAT(){
     return "dd.MM.yyyy";
    }

    static QString formatDate(QDateTime date){
        return date.toString("dd.MM.yyyy");
    }

    static QString formatHour(QDateTime date){
        return date.toString("HH:mm");
    }

};

#endif // COREUTILS

