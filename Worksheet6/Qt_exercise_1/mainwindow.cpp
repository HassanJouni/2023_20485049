#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ModelPart.h"
#include "ModelPartList.h"
#include <QMessageBox>
#include <QFileDialog>
#include "optiondialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this ->partList = new ModelPartList ("PartsList");

    ui->treeView->setModel(this->partList);

    ModelPart *rootItem = this->partList->getRootItem();

    for (int i = 0; i < 3; i++) {
        // Create and add top-level items
        QString name = QString("TopLevel %1").arg(i);
        QString visible("true");
        ModelPart *childItem = new ModelPart({name, visible});
        rootItem->appendChild(childItem);

        // Create and add child items
        for (int j = 0; j < 5; j++) {
            QString name = QString("Item %1,%2").arg(i).arg(j);
            QString visible("true");
            ModelPart *childChildItem = new ModelPart({name, visible});
            childItem->appendChild(childChildItem);
        }
    }

    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::handleButton);

    connect(this, &MainWindow::statusUpdateMessage, ui->statusbar, &QStatusBar::showMessage);

    connect(this, &MainWindow::statusUpdateMessage, ui->statusbar, &QStatusBar::showMessage);

    connect(ui->treeView, &QTreeView::clicked, this, &MainWindow::openOptionDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::handleButton() {

   emit statusUpdateMessage("Add button was clicked", 0);
}

void MainWindow::handleTreeClicked() {
    QModelIndex index = ui->treeView->currentIndex();
    ModelPart* selectedPart = static_cast<ModelPart*>(index.internalPointer());

    if (selectedPart) {

        QString text = selectedPart->data(0).toString();

        emit statusUpdateMessage(QString("the selected item is:") + text, 0);

    }
    else {

        emit statusUpdateMessage(QString("no item is selected"), 0);
    }
            
}

void MainWindow::on_actionOpen_File_triggered() {

        emit statusUpdateMessage("Open File action triggered", 0);
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        "C:\\", // Initial directory
        tr("STL Files (*.stl);;Text Files (*.txt)")
        );
    }

void MainWindow::openOptionDialog()
{
    // Get selected item in the tree view
    QModelIndex index = ui->treeView->currentIndex();
    ModelPart* selectedPart = static_cast<ModelPart*>(index.internalPointer());

    // Create an instance of OptionDialog
    OptionDialog dialog(this);

    // Execute the dialog (blocks until closed)
    int result = dialog.exec();

    if (result == QDialog::Accepted) {
        emit statusUpdateMessage("Dialog accepted", 0);
    } else {
        emit statusUpdateMessage("Dialog rejected", 0);
    }
}





