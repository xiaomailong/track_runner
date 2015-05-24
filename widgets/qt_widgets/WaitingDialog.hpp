#ifndef WAITINGDIALOG_HPP
#define WAITINGDIALOG_HPP

#include <QDialog>

namespace Ui {
class WaitingDialog;
}

class WaitingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WaitingDialog(QWidget *parent = 0);
    ~WaitingDialog();

private:
    Ui::WaitingDialog *ui;
};

#endif // WAITINGDIALOG_HPP
