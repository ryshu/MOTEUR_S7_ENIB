#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtCore>
#include <QDebug>

#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QTimer>

#include <libpcan.h>        // /usr/include/libpcan.h
#include <fcntl.h>    // O_RDWR
#include <signal.h>
#include <unistd.h>   // exit

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void openCANPort();
    void receiveCANMessage();

public slots:

    void onTimer_Tick();

private slots:
    void on_speed_horizontalSlider_valueChanged(int value);

    void on_speed_spinBox_valueChanged(int arg1);

    void on_mode_1_clicked();

    void on_mode_2_clicked();

    void on_mode_3_clicked();

    void on_position_choice_valueChanged(int value);

private:

    HANDLE h;
    TPCANRdMsg pMsgBuff;

    Ui::MainWindow  *ui;

    int mode;

    QTimer *timer_tick;
};

#endif // MAINWINDOW_H
