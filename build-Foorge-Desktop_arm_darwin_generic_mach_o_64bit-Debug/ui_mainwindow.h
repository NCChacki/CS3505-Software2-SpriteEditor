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
#include <QtWidgets/QSlider>
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
    QPushButton *nextFrameButton;
    QPushButton *previousFrameButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *frameLabel1;
    QLabel *frameLabel2;
    QFrame *frame_2;
    QLabel *frameLabel3;
    QLabel *frameLabel4;
    QLabel *frameLabel5;
    QSlider *frameRateSlider;
    QPushButton *deleteFrameButton;
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
        newFrameButton->setGeometry(QRect(40, 430, 101, 32));
        nextFrameButton = new QPushButton(mainWidget);
        nextFrameButton->setObjectName("nextFrameButton");
        nextFrameButton->setGeometry(QRect(40, 490, 101, 32));
        previousFrameButton = new QPushButton(mainWidget);
        previousFrameButton->setObjectName("previousFrameButton");
        previousFrameButton->setGeometry(QRect(40, 520, 101, 32));
        horizontalLayoutWidget = new QWidget(mainWidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(150, 440, 591, 102));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frameLabel1 = new QLabel(horizontalLayoutWidget);
        frameLabel1->setObjectName("frameLabel1");
        frameLabel1->setMinimumSize(QSize(100, 100));
        frameLabel1->setMaximumSize(QSize(100, 100));

        horizontalLayout->addWidget(frameLabel1);

        frameLabel2 = new QLabel(horizontalLayoutWidget);
        frameLabel2->setObjectName("frameLabel2");
        frameLabel2->setMinimumSize(QSize(100, 100));
        frameLabel2->setMaximumSize(QSize(100, 100));

        horizontalLayout->addWidget(frameLabel2);

        frame_2 = new QFrame(horizontalLayoutWidget);
        frame_2->setObjectName("frame_2");
        frame_2->setEnabled(true);
        frame_2->setMinimumSize(QSize(100, 100));
        frame_2->setMaximumSize(QSize(100, 100));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(2);
        frameLabel3 = new QLabel(frame_2);
        frameLabel3->setObjectName("frameLabel3");
        frameLabel3->setEnabled(true);
        frameLabel3->setGeometry(QRect(0, 0, 100, 100));
        frameLabel3->setMinimumSize(QSize(100, 100));
        frameLabel3->setMaximumSize(QSize(100, 100));

        horizontalLayout->addWidget(frame_2);

        frameLabel4 = new QLabel(horizontalLayoutWidget);
        frameLabel4->setObjectName("frameLabel4");
        frameLabel4->setMinimumSize(QSize(100, 100));
        frameLabel4->setMaximumSize(QSize(100, 100));

        horizontalLayout->addWidget(frameLabel4);

        frameLabel5 = new QLabel(horizontalLayoutWidget);
        frameLabel5->setObjectName("frameLabel5");
        frameLabel5->setMinimumSize(QSize(100, 100));
        frameLabel5->setMaximumSize(QSize(100, 100));

        horizontalLayout->addWidget(frameLabel5);

        frameRateSlider = new QSlider(mainWidget);
        frameRateSlider->setObjectName("frameRateSlider");
        frameRateSlider->setGeometry(QRect(650, 110, 101, 31));
        frameRateSlider->setMinimum(1);
        frameRateSlider->setMaximum(12);
        frameRateSlider->setSingleStep(2);
        frameRateSlider->setValue(1);
        frameRateSlider->setSliderPosition(1);
        frameRateSlider->setOrientation(Qt::Horizontal);
        deleteFrameButton = new QPushButton(mainWidget);
        deleteFrameButton->setObjectName("deleteFrameButton");
        deleteFrameButton->setGeometry(QRect(40, 460, 100, 32));
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
        canvasLabel->setText(QString());
        saveProjectButton->setText(QCoreApplication::translate("MainWindow", "Save Project", nullptr));
        loadProjectButton->setText(QCoreApplication::translate("MainWindow", "Load Project", nullptr));
        createProjectButton->setText(QCoreApplication::translate("MainWindow", "Create Project", nullptr));
        previewLabel->setText(QString());
        newFrameButton->setText(QCoreApplication::translate("MainWindow", "New Frame", nullptr));
        nextFrameButton->setText(QCoreApplication::translate("MainWindow", "Next Frame", nullptr));
        previousFrameButton->setText(QCoreApplication::translate("MainWindow", "Previous Frame", nullptr));
        frameLabel1->setText(QString());
        frameLabel2->setText(QString());
        frameLabel3->setText(QString());
        frameLabel4->setText(QString());
        frameLabel5->setText(QString());
        deleteFrameButton->setText(QCoreApplication::translate("MainWindow", "Delete Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
