#include "mainwindow.h"
#include "ui_mainwindow.h"

#define DEFAULT_NODE "/dev/pcanusb32"

//===============================================================
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->state_pos_f1->setStyleSheet("background-color: rgb(255, 0, 0);");
    ui->state_pos_f2->setStyleSheet("background-color: rgb(255, 0, 0);");

    openCANPort();

    timer_tick = new QTimer();
    connect( timer_tick, SIGNAL(timeout()), this, SLOT(onTimer_Tick()));

    timer_tick -> start(100); // in ms
}
//===============================================================

MainWindow::~MainWindow()
{
    delete ui;
}

//===============================================================
void MainWindow::openCANPort()
{
    const char *szDevNode = DEFAULT_NODE;

    h=LINUX_CAN_Open(szDevNode, O_RDWR);
    if (!h)
        {
            printf("can't open %s\n", szDevNode);
        }
    CAN_Init(h, CAN_BAUD_500K,  CAN_INIT_TYPE_ST);         // BTR0BTR1	bitrate code in hex (default=0x1c (500 kbps))
    CAN_Status(h); // Clear Status

}
//===============================================================
void MainWindow::receiveCANMessage()
{
    LINUX_CAN_Read_Timeout(h, &pMsgBuff,1); // Timeout=1ms --> Non Bloquant

    if(pMsgBuff.Msg.DATA[0] == 0x01)
    { // We speek of "End pos 1"
        ui->state_pos_f1->setStyleSheet("background-color: rgb(0, 255, 0);");
        ui->state_pos_f2->setStyleSheet("background-color: rgb(255, 0, 0);");
    } else if(pMsgBuff.Msg.DATA[0] == 0x02) {  // We speek of "End pos 2"
        ui->state_pos_f2->setStyleSheet("background-color: rgb(0, 255, 0);");
        ui->state_pos_f1->setStyleSheet("background-color: rgb(255, 0, 0);");
    }
}
//===============================================================

void MainWindow::onTimer_Tick()
{
    receiveCANMessage();
}

void MainWindow::on_speed_horizontalSlider_valueChanged(int value)
{
    ui->speed_spinBox->setValue(value);
}

void MainWindow::on_speed_spinBox_valueChanged(int arg1)
{
    ui->speed_horizontalSlider->setValue(arg1);
}

void MainWindow::on_mode_1_clicked()
{
    this->mode = 1;

    TPCANMsg msgBuff;

    msgBuff.ID      =   0x01;
    msgBuff.MSGTYPE =   MSGTYPE_STANDARD;
    msgBuff.LEN     =   8;

    msgBuff.DATA[0] =   0x01;

    for(int i = 1; i < 8; i++)
        msgBuff.DATA[i] =   0x00;

    LINUX_CAN_Write_Timeout(h, &msgBuff,0);

}

void MainWindow::on_mode_2_clicked()
{
    this->mode = 2;

    TPCANMsg msgBuff;

    msgBuff.ID      =   0x01;
    msgBuff.MSGTYPE =   MSGTYPE_STANDARD;
    msgBuff.LEN     =   8;

    msgBuff.DATA[0] =   0x02;

    for(int i = 1; i < 8; i++)
        msgBuff.DATA[i] =   0x00;

    LINUX_CAN_Write_Timeout(h, &msgBuff,0);
}

void MainWindow::on_mode_3_clicked()
{
    this->mode = 3;

    TPCANMsg msgBuff;

    msgBuff.ID      =   0x01;
    msgBuff.MSGTYPE =   MSGTYPE_STANDARD;
    msgBuff.LEN     =   8;

    msgBuff.DATA[0] =   0x03;
    msgBuff.DATA[1] =   ui->position_choice->value().toInt();

    for(int i = 2; i < 8; i++)
        msgBuff.DATA[i] =   0x00;

    LINUX_CAN_Write_Timeout(h, &msgBuff,0);
}

void MainWindow::on_position_choice_valueChanged(int value)
{
    if(this->mode != 3)
    {
        return;
    }

    TPCANMsg msgBuff;

    msgBuff.ID      =   0x03;
    msgBuff.MSGTYPE =   MSGTYPE_STANDARD;
    msgBuff.LEN     =   8;

    msgBuff.DATA[0] =   0x01;
    msgBuff.DATA[1] =   value;

    for(int i = 2; i < 8; i++)
        msgBuff.DATA[i] =   0x00;

    LINUX_CAN_Write_Timeout(h, &msgBuff,0);
}
