#ifndef OPTIONDIALOG_H
#define OPTIONDIALOG_H

#include <QDialog>
#include "ui_optiondialog.h"

namespace Ui {
class OptionDialog;
}

class OptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionDialog(QWidget *parent = nullptr);
    ~OptionDialog();



private:
    Ui::OptionDialog *ui;
};

#endif // OPTIONDIALOG_H
