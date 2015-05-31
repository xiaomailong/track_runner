#include "TrainListWidget.hpp"
#include "ui_TrainListWidget.h"

TrainListWidget::TrainListWidget(QWidget *parent) :
    GuiView(parent),
    ui(new Ui::TrainListWidget)
{
    ui->setupUi(this);
    this->loading_screen = new WaitingDialog(this);
    this->ui->input_date->setDateTime(QDateTime::currentDateTime());
    this->refresh_search_button_state();
}

TrainListWidget::~TrainListWidget()
{
    delete ui;
}


void TrainListWidget::on_button_search_clicked()
{
    QPointer<TrainSearchRequest> request = new TrainSearchRequest();
    request->setSource(this->ui->input_from->text());
    request->setDestination(this->ui->input_to->text());
    request->setJourneyStartDate(this->ui->input_date->dateTime());
    emit this->requestTimetable(request);
    this->loading_screen->show();
}

void TrainListWidget::timetableRequestFinished(QPointer<TrainTimetable> timetable){
    this->loading_screen->hide();
    TrainTimetable *table = timetable;
    QPointer<TrainTimetableModel>  model = new TrainTimetableModel(timetable);
    this->ui->table_view->setModel(model);
}

void TrainListWidget::displayError(QString error_message){
    this->loading_screen->hide();
    QMessageBox::critical(this, "Critical error", error_message);
}

void TrainListWidget::on_button_now_clicked()
{
    this->ui->input_date->setDateTime(QDateTime::currentDateTime());
}

void TrainListWidget::on_button_switch_clicked()
{
    QString extra = this->ui->input_from->text();
    this->ui->input_from->setText(this->ui->input_to->text());
    this->ui->input_to->setText(extra);
}

void TrainListWidget::refresh_search_button_state(){
    if(this->ui->input_from->text() == "" || this->ui->input_to->text() == "" ){
        this->ui->button_search->setDisabled(true);
    }else{
        this->ui->button_search->setDisabled(false);
    }
}

void TrainListWidget::on_input_from_textChanged(const QString &arg1)
{
    this->refresh_search_button_state();
}

void TrainListWidget::on_input_to_textEdited(const QString &arg1)
{
    this->refresh_search_button_state();
}
