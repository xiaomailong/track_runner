#ifndef TRAINLISTWIDGET_HPP
#define TRAINLISTWIDGET_HPP

#include <QWidget>

namespace Ui {
class TrainListWidget;
}

class TrainListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TrainListWidget(QWidget *parent = 0);
    ~TrainListWidget();

private:
    Ui::TrainListWidget *ui;
};

#endif // TRAINLISTWIDGET_HPP
