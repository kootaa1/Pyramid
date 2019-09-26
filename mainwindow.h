#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDoubleValidator>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_OpenFile_triggered();

    void on_filesComboBox_currentTextChanged(const QString &arg1);

    void on_layresComboBox_currentIndexChanged(const QString &arg1);

    void on_coefficientEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QDoubleValidator validator;
    QMap<QString,QPixmap> pixmapContainer;
    QPixmap currentPixmap;
    double coefficient;
};
#endif // MAINWINDOW_H
