#include "optiondialog.h"
#include "ui_optiondialog.h"
#include <QPushButton>

OptionDialog::OptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionDialog)
{
    ui->setupUi(this);
}

OptionDialog::~OptionDialog()
{
    delete ui;
}


