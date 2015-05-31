#ifndef TRAINLISTWIDGET_HPP
#define TRAINLISTWIDGET_HPP

#include "widgets/GuiView.hpp"
#include "widgets/qt_widgets/WaitingDialog.hpp"
#include "core_components/TrainSearchRequest.hpp"
#include "core_components/TrainTimetableModel.hpp"

#include <QPointer>
#include <QMessageBox>

namespace Ui {
class TrainListWidget;
}

class TrainListWidget : public GuiView
{
    Q_OBJECT

    WaitingDialog *loading_screen;

public:
    explicit TrainListWidget(QWidget *parent = 0);
    ~TrainListWidget();

signals:
    void requestTimetable(QPointer<TrainSearchRequest> train_search_request);

public slots:
    void timetableRequestFinished(QPointer<TrainTimetable> timetable);
    void displayError(QString error_message);

private slots:
    void on_button_search_clicked();

    void on_button_now_clicked();

    void on_button_switch_clicked();

    void refresh_search_button_state();

    void on_input_from_textChanged(const QString &arg1);

    void on_input_to_textEdited(const QString &arg1);

private:
    Ui::TrainListWidget *ui;
};

#endif // TRAINLISTWIDGET_HPP
