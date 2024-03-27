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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
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
    QLabel *previewLabel;
    QPushButton *newFrameButton;
    QFrame *frame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *frameLabel1;
    QLabel *frameLabel2;
    QLabel *frameLabel3;
    QLabel *frameLabel4;
    QLabel *frameLabel5;
    QPushButton *previousFrameButton;
    QPushButton *nextFrameButton;
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
        previewLabel = new QLabel(mainWidget);
        previewLabel->setObjectName("previewLabel");
        previewLabel->setGeometry(QRect(650, 0, 100, 100));
        newFrameButton = new QPushButton(mainWidget);
        newFrameButton->setObjectName("newFrameButton");
        newFrameButton->setGeometry(QRect(89, 450, 101, 32));
        frame = new QFrame(mainWidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(200, 440, 500, 100));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(-1, -1, 501, 101));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frameLabel1 = new QLabel(horizontalLayoutWidget);
        frameLabel1->setObjectName("frameLabel1");

        horizontalLayout->addWidget(frameLabel1);

        frameLabel2 = new QLabel(horizontalLayoutWidget);
        frameLabel2->setObjectName("frameLabel2");

        horizontalLayout->addWidget(frameLabel2);

        frameLabel3 = new QLabel(horizontalLayoutWidget);
        frameLabel3->setObjectName("frameLabel3");

        horizontalLayout->addWidget(frameLabel3);

        frameLabel4 = new QLabel(horizontalLayoutWidget);
        frameLabel4->setObjectName("frameLabel4");

        horizontalLayout->addWidget(frameLabel4);

        frameLabel5 = new QLabel(horizontalLayoutWidget);
        frameLabel5->setObjectName("frameLabel5");

        horizontalLayout->addWidget(frameLabel5);

        previousFrameButton = new QPushButton(mainWidget);
        previousFrameButton->setObjectName("previousFrameButton");
        previousFrameButton->setGeometry(QRect(89, 480, 101, 32));
        nextFrameButton = new QPushButton(mainWidget);
        nextFrameButton->setObjectName("nextFrameButton");
        nextFrameButton->setGeometry(QRect(89, 510, 101, 32));
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
        previewLabel->setText(QCoreApplication::translate("MainWindow", "Preview Window", nullptr));
        newFrameButton->setText(QCoreApplication::translate("MainWindow", "New Frame", nullptr));
        frameLabel1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        frameLabel2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        frameLabel3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        frameLabel4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        frameLabel5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        previousFrameButton->setText(QCoreApplication::translate("MainWindow", "Next Frame", nullptr));
        nextFrameButton->setText(QCoreApplication::translate("MainWindow", "Previous Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
