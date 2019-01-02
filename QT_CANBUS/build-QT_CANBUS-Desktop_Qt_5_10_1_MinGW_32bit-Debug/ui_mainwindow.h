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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QSlider *speed_horizontalSlider;
    QSpinBox *speed_spinBox;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QLabel *state_pos_f1;
    QLabel *label_5;
    QLabel *state_pos_f2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *mode_1;
    QRadioButton *mode_2;
    QRadioButton *mode_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QSlider *position_choice;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(451, 511);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 431, 431));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        speed_horizontalSlider = new QSlider(verticalLayoutWidget);
        speed_horizontalSlider->setObjectName(QStringLiteral("speed_horizontalSlider"));
        speed_horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(speed_horizontalSlider);

        speed_spinBox = new QSpinBox(verticalLayoutWidget);
        speed_spinBox->setObjectName(QStringLiteral("speed_spinBox"));

        horizontalLayout->addWidget(speed_spinBox);


        verticalLayout->addLayout(horizontalLayout);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_2->addWidget(label_10);

        state_pos_f1 = new QLabel(verticalLayoutWidget);
        state_pos_f1->setObjectName(QStringLiteral("state_pos_f1"));
        state_pos_f1->setMinimumSize(QSize(75, 75));
        state_pos_f1->setMaximumSize(QSize(75, 75));
        state_pos_f1->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));

        horizontalLayout_2->addWidget(state_pos_f1);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        state_pos_f2 = new QLabel(verticalLayoutWidget);
        state_pos_f2->setObjectName(QStringLiteral("state_pos_f2"));
        state_pos_f2->setMinimumSize(QSize(75, 75));
        state_pos_f2->setMaximumSize(QSize(75, 75));
        state_pos_f2->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));

        horizontalLayout_2->addWidget(state_pos_f2);


        verticalLayout->addLayout(horizontalLayout_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        mode_1 = new QRadioButton(verticalLayoutWidget);
        mode_1->setObjectName(QStringLiteral("mode_1"));

        verticalLayout_2->addWidget(mode_1);

        mode_2 = new QRadioButton(verticalLayoutWidget);
        mode_2->setObjectName(QStringLiteral("mode_2"));

        verticalLayout_2->addWidget(mode_2);

        mode_3 = new QRadioButton(verticalLayoutWidget);
        mode_3->setObjectName(QStringLiteral("mode_3"));

        verticalLayout_2->addWidget(mode_3);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_4->addWidget(label_7);

        position_choice = new QSlider(verticalLayoutWidget);
        position_choice->setObjectName(QStringLiteral("position_choice"));
        position_choice->setMaximum(100);
        position_choice->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(position_choice);


        verticalLayout->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 451, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Contr\303\264le de vitesse", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Choix de la vitesse ", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Etat de fin de course", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Interrupteur 1 :", nullptr));
        state_pos_f1->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Interrupteur 2:", nullptr));
        state_pos_f2->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Choix du mode", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Choix du mode", nullptr));
        mode_1->setText(QApplication::translate("MainWindow", "1) STOP sur fin de course", nullptr));
        mode_2->setText(QApplication::translate("MainWindow", "2) ALLER-RETOUR", nullptr));
        mode_3->setText(QApplication::translate("MainWindow", "3) Arr\303\252t sur position d\303\251finit", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Si mode 3, choix de la position :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
