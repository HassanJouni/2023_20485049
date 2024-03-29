#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ModelPartList.h"
#include "ModelPart.h"
#include "optiondialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void statusUpdateMessage ( const QString &message , int timeout);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


 public slots:
    void handleButton();
    void handleTreeClicked();
    void on_actionOpen_File_triggered();
    void openOptionDialog();


private:
    Ui::MainWindow *ui;
    ModelPartList* partList;

};
#endif // MAINWINDOW_H
