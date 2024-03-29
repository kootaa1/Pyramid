#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

const int MAX_LAYERS_COUNT = 5;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), validator(1, 10, 2, this)
{
    ui->setupUi(this);
    setWindowTitle("Pyramid");

    validator.setNotation(QDoubleValidator::StandardNotation);
    validator.setLocale(QLocale::English);
    ui->coefficientEdit->setValidator(&validator);
    connect(ui->coefficientEdit, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));

    for(int i = 0; i < MAX_LAYERS_COUNT; i++)
    {
        ui->layresComboBox->insertItem(i,QString::number(i));
    }
    coefficient = 2.;
}

MainWindow::~MainWindow()
{
    delete ui;
}



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
            currentPixmap = pixmapContainer[name];
            ui->imageLabel->setPixmap(currentPixmap);
            //            ui->imageLabel->setFixedWidth(currentPixmap.width());
            //            ui->imageLabel->setFixedHeight(currentPixmap.height());
            ui->sizeLabel->setText(QString("Size: ") +
                                   QString::number(currentPixmap.width()) +
                                   QString(" x ") +
                                   QString::number(currentPixmap.height()));
            ui->filesComboBox->setCurrentIndex(ui->filesComboBox->count() - 1);
        }
    }
}

void MainWindow::on_filesComboBox_currentTextChanged(const QString &arg1)
{
    currentPixmap = pixmapContainer[arg1];
    ui->imageLabel->setPixmap(currentPixmap);
    //    ui->imageLabel->setFixedWidth(currentPixmap.width());
    //    ui->imageLabel->setFixedHeight(currentPixmap.height());
    ui->sizeLabel->setText(QString("Size: ") +
                           QString::number(currentPixmap.width()) +
                           QString(" x ") +
                           QString::number(currentPixmap.height()));
    ui->layresComboBox->setCurrentIndex(0);
}

void MainWindow::on_layresComboBox_currentIndexChanged(const QString &arg1)
{
    currentPixmap = pixmapContainer[ui->filesComboBox->currentText()];
    double oldWidth = currentPixmap.width();
    double oldHeight = currentPixmap.height();
    double width = currentPixmap.width() / pow(coefficient, ui->layresComboBox->currentIndex());
    double height = currentPixmap.height() / pow(coefficient, ui->layresComboBox->currentIndex());
    currentPixmap = currentPixmap.scaled(width, height);
    currentPixmap = currentPixmap.scaled(oldWidth, oldHeight);
    ui->imageLabel->setPixmap(currentPixmap);
    ui->sizeLabel->setText(QString("Size: ") +
                           QString::number((int)width) +
                           QString(" x ") +
                           QString::number((int)height));
}

void MainWindow::on_coefficientEdit_textChanged(const QString &arg1)
{
    double previousCoefficient = coefficient;
    coefficient = arg1.toDouble();
    if(coefficient < 1)
        ui->coefficientEdit->setText(QString::number(previousCoefficient));
    coefficient = previousCoefficient;
}
