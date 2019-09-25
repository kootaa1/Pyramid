#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QMap<QString,QPixmap> pixmapContainer;

void MainWindow::on_OpenFile_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                "/home",
                                                tr("Images (*.png *.xpm *.jpg)"));
    if(!path.isEmpty())
    {
        QString name = path.right(path.count() - path.lastIndexOf('/') - 1);
        if(!pixmapContainer.contains(name))
        {
            pixmapContainer.insert(name,path);
            ui->filesComboBox->insertItem(ui->filesComboBox->count()+1, name);
            ui->imageLabel->setPixmap(pixmapContainer[name]);
            ui->imageLabel->setFixedWidth(pixmapContainer[name].width());
            ui->imageLabel->setFixedHeight(pixmapContainer[name].height());
            ui->sizeLabel->setText(QString::number(pixmapContainer[name].width())
                                   +QString("x")+
                                   QString::number(pixmapContainer[name].height()));
            ui->filesComboBox->setCurrentIndex(ui->filesComboBox->count() - 1);
        }
    }
}

void MainWindow::on_filesComboBox_currentTextChanged(const QString &arg1)
{
        ui->imageLabel->setPixmap(pixmapContainer[arg1]);
        ui->imageLabel->setFixedWidth(pixmapContainer[arg1].width());
        ui->imageLabel->setFixedHeight(pixmapContainer[arg1].height());
        ui->sizeLabel->setText(QString::number(pixmapContainer[arg1].width())
                               +QString("x")+
                               QString::number(pixmapContainer[arg1].height()));
}


void MainWindow::on_filesComboBox_currentIndexChanged(int index)
{

}

void MainWindow::on_filesComboBox_currentIndexChanged(const QString &arg1)
{

}
