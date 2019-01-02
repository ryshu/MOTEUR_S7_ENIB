/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_20;
    QLineEdit *pressure_result;
    QLabel *label_30;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer;
    QLineEdit *wind_result;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *dist_result;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lum_result;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *mpu9250_3d_view;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QLineEdit *acc_x_result;
    QLabel *label_12;
    QLineEdit *acc_y_result;
    QLabel *label_13;
    QLineEdit *acc_z_result;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_14;
    QLineEdit *gyro_x_result;
    QLabel *label_15;
    QLineEdit *gyro_y_result;
    QLabel *label_16;
    QLineEdit *gyro_z_result;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget_11;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_18;
    QSpinBox *test_id;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_19;
    QLineEdit *test_data_0;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_20;
    QLineEdit *test_data_1;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_21;
    QLineEdit *test_data_2;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_22;
    QLineEdit *test_data_3;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_23;
    QLineEdit *test_data_4;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_24;
    QLineEdit *test_data_5;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_25;
    QLineEdit *test_data_6;
    QVBoxLayout *verticalLayout_22;
    QLabel *label_26;
    QLineEdit *test_data_7;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_18;
    QVBoxLayout *verticalLayout_23;
    QLabel *label_27;
    QHBoxLayout *horizontalLayout_17;
    QLineEdit *test_result_0;
    QLineEdit *test_result_1;
    QLineEdit *test_result_2;
    QLineEdit *test_result_3;
    QLineEdit *test_result_4;
    QLineEdit *test_result_5;
    QLineEdit *test_result_6;
    QLineEdit *test_result_7;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_28;
    QLabel *label_29;
    QPushButton *send_data;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(605, 578);
        MainWindow->setMinimumSize(QSize(605, 578));
        MainWindow->setMaximumSize(QSize(605, 578));
        MainWindow->setAutoFillBackground(true);
        MainWindow->setDockNestingEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(605, 513));
        centralWidget->setMaximumSize(QSize(605, 513));
        centralWidget->setAutoFillBackground(true);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 611, 541));
        tabWidget->setAutoFillBackground(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setAutoFillBackground(true);
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 0, 561, 481));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(517, 52));
        label->setMaximumSize(QSize(517, 52));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAutoFillBackground(true);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(172, 0));
        label_5->setAutoFillBackground(true);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_7);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        pressure_result = new QLineEdit(verticalLayoutWidget);
        pressure_result->setObjectName(QStringLiteral("pressure_result"));
        pressure_result->setMaximumSize(QSize(50, 16777215));
        pressure_result->setReadOnly(true);

        horizontalLayout_20->addWidget(pressure_result);

        label_30 = new QLabel(verticalLayoutWidget);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setAlignment(Qt::AlignCenter);

        horizontalLayout_20->addWidget(label_30);


        horizontalLayout_14->addLayout(horizontalLayout_20);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_8);


        verticalLayout_14->addLayout(horizontalLayout_14);


        verticalLayout_6->addLayout(verticalLayout_14);


        horizontalLayout->addLayout(verticalLayout_6);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAutoFillBackground(true);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(172, 0));
        label_7->setMaximumSize(QSize(172, 16777215));
        label_7->setAutoFillBackground(true);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_7);


        horizontalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);

        wind_result = new QLineEdit(verticalLayoutWidget);
        wind_result->setObjectName(QStringLiteral("wind_result"));
        wind_result->setMaximumSize(QSize(50, 16777215));
        wind_result->setReadOnly(true);

        horizontalLayout_11->addWidget(wind_result);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);


        verticalLayout_8->addLayout(horizontalLayout_11);


        horizontalLayout_4->addLayout(verticalLayout_8);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAutoFillBackground(true);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(172, 0));
        label_6->setMaximumSize(QSize(172, 16777215));
        label_6->setAutoFillBackground(true);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_6);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAutoFillBackground(true);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_9);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_5);

        dist_result = new QLineEdit(verticalLayoutWidget);
        dist_result->setObjectName(QStringLiteral("dist_result"));
        dist_result->setMaximumSize(QSize(50, 16777215));
        dist_result->setReadOnly(true);

        horizontalLayout_13->addWidget(dist_result);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_6);


        verticalLayout_12->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_3);

        lum_result = new QLineEdit(verticalLayoutWidget);
        lum_result->setObjectName(QStringLiteral("lum_result"));
        lum_result->setMaximumSize(QSize(50, 16777215));
        lum_result->setReadOnly(true);

        horizontalLayout_12->addWidget(lum_result);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_4);


        verticalLayout_12->addLayout(horizontalLayout_12);


        verticalLayout_9->addLayout(verticalLayout_12);


        horizontalLayout_3->addLayout(verticalLayout_9);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAutoFillBackground(true);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        mpu9250_3d_view = new QPushButton(verticalLayoutWidget);
        mpu9250_3d_view->setObjectName(QStringLiteral("mpu9250_3d_view"));
        mpu9250_3d_view->setMinimumSize(QSize(100, 0));
        mpu9250_3d_view->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(mpu9250_3d_view);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(172, 0));
        label_8->setMaximumSize(QSize(172, 16777215));
        label_8->setAutoFillBackground(true);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_8);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAutoFillBackground(true);
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_11);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(25, 16777215));
        label_10->setAutoFillBackground(true);
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_10);

        acc_x_result = new QLineEdit(verticalLayoutWidget);
        acc_x_result->setObjectName(QStringLiteral("acc_x_result"));
        acc_x_result->setMaximumSize(QSize(50, 16777215));
        acc_x_result->setReadOnly(true);

        horizontalLayout_9->addWidget(acc_x_result);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMaximumSize(QSize(25, 16777215));
        label_12->setAutoFillBackground(true);
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_12);

        acc_y_result = new QLineEdit(verticalLayoutWidget);
        acc_y_result->setObjectName(QStringLiteral("acc_y_result"));
        acc_y_result->setMaximumSize(QSize(50, 16777215));
        acc_y_result->setReadOnly(true);

        horizontalLayout_9->addWidget(acc_y_result);

        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMaximumSize(QSize(25, 16777215));
        label_13->setAutoFillBackground(true);
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_13);

        acc_z_result = new QLineEdit(verticalLayoutWidget);
        acc_z_result->setObjectName(QStringLiteral("acc_z_result"));
        acc_z_result->setMaximumSize(QSize(50, 16777215));
        acc_z_result->setReadOnly(true);

        horizontalLayout_9->addWidget(acc_z_result);


        verticalLayout_11->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMaximumSize(QSize(25, 16777215));
        label_14->setAutoFillBackground(true);
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_14);

        gyro_x_result = new QLineEdit(verticalLayoutWidget);
        gyro_x_result->setObjectName(QStringLiteral("gyro_x_result"));
        gyro_x_result->setMaximumSize(QSize(50, 16777215));
        gyro_x_result->setReadOnly(true);

        horizontalLayout_10->addWidget(gyro_x_result);

        label_15 = new QLabel(verticalLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMaximumSize(QSize(25, 16777215));
        label_15->setAutoFillBackground(true);
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_15);

        gyro_y_result = new QLineEdit(verticalLayoutWidget);
        gyro_y_result->setObjectName(QStringLiteral("gyro_y_result"));
        gyro_y_result->setMaximumSize(QSize(50, 16777215));
        gyro_y_result->setReadOnly(true);

        horizontalLayout_10->addWidget(gyro_y_result);

        label_16 = new QLabel(verticalLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMaximumSize(QSize(25, 16777215));
        label_16->setAutoFillBackground(true);
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_16);

        gyro_z_result = new QLineEdit(verticalLayoutWidget);
        gyro_z_result->setObjectName(QStringLiteral("gyro_z_result"));
        gyro_z_result->setMaximumSize(QSize(50, 16777215));
        gyro_z_result->setReadOnly(true);

        horizontalLayout_10->addWidget(gyro_z_result);


        verticalLayout_11->addLayout(horizontalLayout_10);


        horizontalLayout_2->addLayout(verticalLayout_11);


        verticalLayout->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_2->setAutoFillBackground(true);
        verticalLayoutWidget_11 = new QWidget(tab_2);
        verticalLayoutWidget_11->setObjectName(QStringLiteral("verticalLayoutWidget_11"));
        verticalLayoutWidget_11->setGeometry(QRect(20, 10, 551, 471));
        verticalLayout_13 = new QVBoxLayout(verticalLayoutWidget_11);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(verticalLayoutWidget_11);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMinimumSize(QSize(517, 52));
        label_17->setMaximumSize(QSize(517, 52));
        label_17->setFont(font);
        label_17->setAutoFillBackground(true);
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(label_17);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_18 = new QLabel(verticalLayoutWidget_11);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setAutoFillBackground(true);

        horizontalLayout_15->addWidget(label_18);

        test_id = new QSpinBox(verticalLayoutWidget_11);
        test_id->setObjectName(QStringLiteral("test_id"));
        test_id->setMinimum(1);
        test_id->setMaximum(4);

        horizontalLayout_15->addWidget(test_id);


        verticalLayout_13->addLayout(horizontalLayout_15);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_4);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label_19 = new QLabel(verticalLayoutWidget_11);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setAutoFillBackground(true);
        label_19->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(label_19);

        test_data_0 = new QLineEdit(verticalLayoutWidget_11);
        test_data_0->setObjectName(QStringLiteral("test_data_0"));
        test_data_0->setMaximumSize(QSize(55, 22));

        verticalLayout_15->addWidget(test_data_0);


        horizontalLayout_16->addLayout(verticalLayout_15);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        label_20 = new QLabel(verticalLayoutWidget_11);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setAutoFillBackground(true);
        label_20->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_20);

        test_data_1 = new QLineEdit(verticalLayoutWidget_11);
        test_data_1->setObjectName(QStringLiteral("test_data_1"));
        test_data_1->setMaximumSize(QSize(55, 16777215));

        verticalLayout_16->addWidget(test_data_1);


        horizontalLayout_16->addLayout(verticalLayout_16);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        label_21 = new QLabel(verticalLayoutWidget_11);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setAutoFillBackground(true);
        label_21->setAlignment(Qt::AlignCenter);

        verticalLayout_17->addWidget(label_21);

        test_data_2 = new QLineEdit(verticalLayoutWidget_11);
        test_data_2->setObjectName(QStringLiteral("test_data_2"));
        test_data_2->setMaximumSize(QSize(55, 16777215));

        verticalLayout_17->addWidget(test_data_2);


        horizontalLayout_16->addLayout(verticalLayout_17);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        label_22 = new QLabel(verticalLayoutWidget_11);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setAutoFillBackground(true);
        label_22->setAlignment(Qt::AlignCenter);

        verticalLayout_18->addWidget(label_22);

        test_data_3 = new QLineEdit(verticalLayoutWidget_11);
        test_data_3->setObjectName(QStringLiteral("test_data_3"));
        test_data_3->setMaximumSize(QSize(55, 16777215));

        verticalLayout_18->addWidget(test_data_3);


        horizontalLayout_16->addLayout(verticalLayout_18);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        label_23 = new QLabel(verticalLayoutWidget_11);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setAutoFillBackground(true);
        label_23->setAlignment(Qt::AlignCenter);

        verticalLayout_19->addWidget(label_23);

        test_data_4 = new QLineEdit(verticalLayoutWidget_11);
        test_data_4->setObjectName(QStringLiteral("test_data_4"));
        test_data_4->setMaximumSize(QSize(55, 16777215));
        test_data_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_19->addWidget(test_data_4);


        horizontalLayout_16->addLayout(verticalLayout_19);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        label_24 = new QLabel(verticalLayoutWidget_11);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setAutoFillBackground(true);
        label_24->setAlignment(Qt::AlignCenter);

        verticalLayout_20->addWidget(label_24);

        test_data_5 = new QLineEdit(verticalLayoutWidget_11);
        test_data_5->setObjectName(QStringLiteral("test_data_5"));
        test_data_5->setMaximumSize(QSize(55, 16777215));

        verticalLayout_20->addWidget(test_data_5);


        horizontalLayout_16->addLayout(verticalLayout_20);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setSpacing(6);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        label_25 = new QLabel(verticalLayoutWidget_11);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setAutoFillBackground(true);
        label_25->setAlignment(Qt::AlignCenter);

        verticalLayout_21->addWidget(label_25);

        test_data_6 = new QLineEdit(verticalLayoutWidget_11);
        test_data_6->setObjectName(QStringLiteral("test_data_6"));
        test_data_6->setMaximumSize(QSize(55, 16777215));

        verticalLayout_21->addWidget(test_data_6);


        horizontalLayout_16->addLayout(verticalLayout_21);

        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        label_26 = new QLabel(verticalLayoutWidget_11);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setAutoFillBackground(true);
        label_26->setAlignment(Qt::AlignCenter);

        verticalLayout_22->addWidget(label_26);

        test_data_7 = new QLineEdit(verticalLayoutWidget_11);
        test_data_7->setObjectName(QStringLiteral("test_data_7"));
        test_data_7->setMaximumSize(QSize(55, 16777215));

        verticalLayout_22->addWidget(test_data_7);


        horizontalLayout_16->addLayout(verticalLayout_22);


        verticalLayout_13->addLayout(horizontalLayout_16);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_3);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        label_27 = new QLabel(verticalLayoutWidget_11);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setAutoFillBackground(true);

        verticalLayout_23->addWidget(label_27);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        test_result_0 = new QLineEdit(verticalLayoutWidget_11);
        test_result_0->setObjectName(QStringLiteral("test_result_0"));
        test_result_0->setMaximumSize(QSize(55, 22));
        test_result_0->setReadOnly(true);

        horizontalLayout_17->addWidget(test_result_0);

        test_result_1 = new QLineEdit(verticalLayoutWidget_11);
        test_result_1->setObjectName(QStringLiteral("test_result_1"));
        test_result_1->setMaximumSize(QSize(55, 22));
        test_result_1->setReadOnly(true);

        horizontalLayout_17->addWidget(test_result_1);

        test_result_2 = new QLineEdit(verticalLayoutWidget_11);
        test_result_2->setObjectName(QStringLiteral("test_result_2"));
        test_result_2->setMaximumSize(QSize(55, 22));
        test_result_2->setReadOnly(true);

        horizontalLayout_17->addWidget(test_result_2);

        test_result_3 = new QLineEdit(verticalLayoutWidget_11);
        test_result_3->setObjectName(QStringLiteral("test_result_3"));
        test_result_3->setMaximumSize(QSize(55, 22));
        test_result_3->setReadOnly(true);

        horizontalLayout_17->addWidget(test_result_3);

        test_result_4 = new QLineEdit(verticalLayoutWidget_11);
        test_result_4->setObjectName(QStringLiteral("test_result_4"));
        test_result_4->setMaximumSize(QSize(55, 22));
        test_result_4->setReadOnly(true);

        horizontalLayout_17->addWidget(test_result_4);

        test_result_5 = new QLineEdit(verticalLayoutWidget_11);
        test_result_5->setObjectName(QStringLiteral("test_result_5"));
        test_result_5->setMaximumSize(QSize(55, 22));
        test_result_5->setReadOnly(true);

        horizontalLayout_17->addWidget(test_result_5);

        test_result_6 = new QLineEdit(verticalLayoutWidget_11);
        test_result_6->setObjectName(QStringLiteral("test_result_6"));
        test_result_6->setMaximumSize(QSize(55, 22));
        test_result_6->setReadOnly(true);

        horizontalLayout_17->addWidget(test_result_6);

        test_result_7 = new QLineEdit(verticalLayoutWidget_11);
        test_result_7->setObjectName(QStringLiteral("test_result_7"));
        test_result_7->setMaximumSize(QSize(55, 22));
        test_result_7->setReadOnly(true);

        horizontalLayout_17->addWidget(test_result_7);


        verticalLayout_23->addLayout(horizontalLayout_17);


        horizontalLayout_18->addLayout(verticalLayout_23);


        verticalLayout_13->addLayout(horizontalLayout_18);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_5);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_28 = new QLabel(verticalLayoutWidget_11);
        label_28->setObjectName(QStringLiteral("label_28"));

        horizontalLayout_19->addWidget(label_28);

        label_29 = new QLabel(verticalLayoutWidget_11);
        label_29->setObjectName(QStringLiteral("label_29"));

        horizontalLayout_19->addWidget(label_29);

        send_data = new QPushButton(verticalLayoutWidget_11);
        send_data->setObjectName(QStringLiteral("send_data"));

        horizontalLayout_19->addWidget(send_data);


        verticalLayout_13->addLayout(horizontalLayout_19);

        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 605, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "MPL115A - Capteur de pression", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Pression", nullptr));
        label_30->setText(QApplication::translate("MainWindow", "kPa", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "ANEMOMETRE", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Vitesse du vent", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "VL6180X - Capteur distance / luminosit\303\251", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Distance", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Luminosit\303\251", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "MPU9250 - Acc\303\251l\303\251rom\303\250tre | Gyroscope", nullptr));
        mpu9250_3d_view->setText(QApplication::translate("MainWindow", "Vue 3D", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Acc\303\251l\303\251ration", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Vitesse angulaire", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "X", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Y", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Z", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "X", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "Y", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Z", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Capteurs", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "BANC DE TEST", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "ID du capteur \303\240 contacter", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "DATA 0", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "DATA 1", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "DATA 2", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "DATA 3", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "DATA 4", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "DATA 5", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "DATA 6", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "DATA 7", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "R\303\251ponse :", nullptr));
        label_28->setText(QString());
        label_29->setText(QString());
        send_data->setText(QApplication::translate("MainWindow", "Send", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Banc de test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
