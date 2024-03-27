/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "canvaswidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *mainWidget;
    CanvasWidget *canvasWidget;
    QLabel *canvasLabel;
    QPushButton *saveProjectButton;
    QPushButton *loadProjectButton;
    QPushButton *createProjectButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        mainWidget = new QWidget(MainWindow);
        mainWidget->setObjectName("mainWidget");
        canvasWidget = new CanvasWidget(mainWidget);
        canvasWidget->setObjectName("canvasWidget");
        canvasWidget->setGeometry(QRect(200, 0, 400, 400));
        QPalette palette;
        QBrush brush(QColor(253, 253, 253, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        QBrush brush1(QColor(247, 251, 250, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(117, 117, 117, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        canvasWidget->setPalette(palette);
        canvasWidget->setAutoFillBackground(false);
        canvasLabel = new QLabel(canvasWidget);
        canvasLabel->setObjectName("canvasLabel");
        canvasLabel->setGeometry(QRect(0, 0, 400, 400));
        canvasLabel->setMinimumSize(QSize(400, 400));
        canvasLabel->setMaximumSize(QSize(400, 400));
        canvasLabel->setAutoFillBackground(true);
        canvasLabel->setScaledContents(true);
        saveProjectButton = new QPushButton(mainWidget);
        saveProjectButton->setObjectName("saveProjectButton");
        saveProjectButton->setGeometry(QRect(10, 30, 100, 32));
        loadProjectButton = new QPushButton(mainWidget);
        loadProjectButton->setObjectName("loadProjectButton");
        loadProjectButton->setGeometry(QRect(10, 60, 100, 32));
        createProjectButton = new QPushButton(mainWidget);
        createProjectButton->setObjectName("createProjectButton");
        createProjectButton->setGeometry(QRect(10, 90, 100, 32));
        MainWindow->setCentralWidget(mainWidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(accessibility)
        canvasLabel->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        canvasLabel->setText(QCoreApplication::translate("MainWindow", "There is text on this QLabel", nullptr));
        saveProjectButton->setText(QCoreApplication::translate("MainWindow", "Save Project", nullptr));
        loadProjectButton->setText(QCoreApplication::translate("MainWindow", "Load Project", nullptr));
        createProjectButton->setText(QCoreApplication::translate("MainWindow", "Create Project", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
