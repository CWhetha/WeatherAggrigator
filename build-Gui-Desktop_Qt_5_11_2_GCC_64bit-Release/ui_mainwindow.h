/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *GetTomorrowsForecast;
    QPushButton *GetThreeDayForecast;
    QPushButton *Graph24hourforecast;
    QCustomPlot *plot;
    QComboBox *comboBox;
    QLabel *Forcast;
    QPushButton *GetTodaysForecast;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1400, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QStringLiteral("background-color:rgba(64, 150, 191, 236)"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        centralWidget->setBaseSize(QSize(0, -27008));
        GetTomorrowsForecast = new QPushButton(centralWidget);
        GetTomorrowsForecast->setObjectName(QStringLiteral("GetTomorrowsForecast"));
        GetTomorrowsForecast->setGeometry(QRect(50, 110, 281, 31));
        GetThreeDayForecast = new QPushButton(centralWidget);
        GetThreeDayForecast->setObjectName(QStringLiteral("GetThreeDayForecast"));
        GetThreeDayForecast->setGeometry(QRect(50, 150, 281, 31));
        Graph24hourforecast = new QPushButton(centralWidget);
        Graph24hourforecast->setObjectName(QStringLiteral("Graph24hourforecast"));
        Graph24hourforecast->setGeometry(QRect(50, 240, 281, 31));
        plot = new QCustomPlot(centralWidget);
        plot->setObjectName(QStringLiteral("plot"));
        plot->setEnabled(true);
        plot->setGeometry(QRect(790, 20, 511, 381));
        plot->setFocusPolicy(Qt::NoFocus);
        plot->setAcceptDrops(false);
        plot->setAutoFillBackground(false);
        plot->setStyleSheet(QStringLiteral("background-color:rgb(136, 138, 133)"));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(50, 40, 281, 25));
        Forcast = new QLabel(centralWidget);
        Forcast->setObjectName(QStringLiteral("Forcast"));
        Forcast->setGeometry(QRect(350, 20, 431, 411));
        sizePolicy.setHeightForWidth(Forcast->sizePolicy().hasHeightForWidth());
        Forcast->setSizePolicy(sizePolicy);
        Forcast->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        GetTodaysForecast = new QPushButton(centralWidget);
        GetTodaysForecast->setObjectName(QStringLiteral("GetTodaysForecast"));
        GetTodaysForecast->setGeometry(QRect(50, 70, 281, 31));
        GetTodaysForecast->setStyleSheet(QStringLiteral(""));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 131, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 190, 151, 17));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(50, 210, 281, 25));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Weather Aggrigator", nullptr));
        GetTomorrowsForecast->setText(QApplication::translate("MainWindow", "Get Tomorrows Forecast", nullptr));
        GetThreeDayForecast->setText(QApplication::translate("MainWindow", "Get The 3 Day Forecast", nullptr));
        Graph24hourforecast->setText(QApplication::translate("MainWindow", "Graph 24 Hour Forecast", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "London", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "Ottawa", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "Toronto", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "Quebec", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "Halifax", nullptr));
        comboBox->setItemText(5, QApplication::translate("MainWindow", "Charlottetown", nullptr));
        comboBox->setItemText(6, QApplication::translate("MainWindow", "Winnipeg", nullptr));
        comboBox->setItemText(7, QApplication::translate("MainWindow", "Regina", nullptr));
        comboBox->setItemText(8, QApplication::translate("MainWindow", "Edmonton", nullptr));
        comboBox->setItemText(9, QApplication::translate("MainWindow", "Victoria", nullptr));
        comboBox->setItemText(10, QApplication::translate("MainWindow", "Yellowknife", nullptr));
        comboBox->setItemText(11, QApplication::translate("MainWindow", "Whitehorse", nullptr));

        Forcast->setText(QString());
        GetTodaysForecast->setText(QApplication::translate("MainWindow", "Get Todays Forecast", nullptr));
        label->setText(QApplication::translate("MainWindow", "Select City:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Select Day To Graph:", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("MainWindow", "Tomorrow", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("MainWindow", "Two Days From Now", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("MainWindow", "Three Days From Now", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
