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
<<<<<<< HEAD
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
=======
#include <QtWidgets/QFrame>
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
<<<<<<< HEAD
#include <QtWidgets/QVBoxLayout>
=======
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
#include <QtWidgets/QWidget>
#include "canvaswidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *mainWidget;
    CanvasWidget *canvasWidget;
<<<<<<< HEAD
=======
    QLabel *transparentLabel;
    QLabel *onionLabel;
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
    QLabel *canvasLabel;
    QPushButton *saveProjectButton;
    QPushButton *loadProjectButton;
    QPushButton *createProjectButton;
<<<<<<< HEAD
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
    QWidget *verticalLayoutWidget;
    QVBoxLayout *colorPickerLayout;
    QPushButton *eraseButton;
    QPushButton *eraseScreen;
    QComboBox *brushSizeBox;
=======
    QPushButton *pushButton;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
<<<<<<< HEAD
        MainWindow->resize(1359, 962);
=======
        MainWindow->resize(800, 600);
        MainWindow->setAutoFillBackground(false);
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
        mainWidget = new QWidget(MainWindow);
        mainWidget->setObjectName("mainWidget");
        canvasWidget = new CanvasWidget(mainWidget);
        canvasWidget->setObjectName("canvasWidget");
<<<<<<< HEAD
        canvasWidget->setGeometry(QRect(200, 0, 400, 400));
=======
        canvasWidget->setGeometry(QRect(130, 30, 501, 501));
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
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
<<<<<<< HEAD
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
=======
        canvasWidget->setAutoFillBackground(true);
        canvasWidget->setStyleSheet(QString::fromUtf8(""));
        transparentLabel = new QLabel(canvasWidget);
        transparentLabel->setObjectName("transparentLabel");
        transparentLabel->setGeometry(QRect(0, 0, 501, 501));
        onionLabel = new QLabel(canvasWidget);
        onionLabel->setObjectName("onionLabel");
        onionLabel->setGeometry(QRect(0, 0, 501, 501));
        onionLabel->setAutoFillBackground(false);
        canvasLabel = new QLabel(canvasWidget);
        canvasLabel->setObjectName("canvasLabel");
        canvasLabel->setGeometry(QRect(0, 0, 500, 500));
        canvasLabel->setMinimumSize(QSize(500, 500));
        canvasLabel->setMaximumSize(QSize(500, 500));
        canvasLabel->setAutoFillBackground(false);
        saveProjectButton = new QPushButton(mainWidget);
        saveProjectButton->setObjectName("saveProjectButton");
        saveProjectButton->setGeometry(QRect(10, 30, 100, 32));
        saveProjectButton->setAutoFillBackground(false);
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
        loadProjectButton = new QPushButton(mainWidget);
        loadProjectButton->setObjectName("loadProjectButton");
        loadProjectButton->setGeometry(QRect(10, 60, 100, 32));
        createProjectButton = new QPushButton(mainWidget);
        createProjectButton->setObjectName("createProjectButton");
        createProjectButton->setGeometry(QRect(10, 90, 100, 32));
<<<<<<< HEAD
        previewLabel = new QLabel(mainWidget);
        previewLabel->setObjectName("previewLabel");
        previewLabel->setGeometry(QRect(650, 0, 100, 100));
        newFrameButton = new QPushButton(mainWidget);
        newFrameButton->setObjectName("newFrameButton");
        newFrameButton->setGeometry(QRect(40, 450, 101, 32));
        nextFrameButton = new QPushButton(mainWidget);
        nextFrameButton->setObjectName("nextFrameButton");
        nextFrameButton->setGeometry(QRect(40, 480, 101, 32));
        previousFrameButton = new QPushButton(mainWidget);
        previousFrameButton->setObjectName("previousFrameButton");
        previousFrameButton->setGeometry(QRect(40, 510, 101, 32));
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

        verticalLayoutWidget = new QWidget(mainWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 560, 511, 291));
        colorPickerLayout = new QVBoxLayout(verticalLayoutWidget);
        colorPickerLayout->setObjectName("colorPickerLayout");
        colorPickerLayout->setContentsMargins(0, 0, 0, 0);
        eraseButton = new QPushButton(mainWidget);
        eraseButton->setObjectName("eraseButton");
        eraseButton->setGeometry(QRect(570, 560, 80, 18));
        eraseScreen = new QPushButton(mainWidget);
        eraseScreen->setObjectName("eraseScreen");
        eraseScreen->setGeometry(QRect(660, 560, 80, 18));
        brushSizeBox = new QComboBox(mainWidget);
        brushSizeBox->setObjectName("brushSizeBox");
        brushSizeBox->setGeometry(QRect(570, 600, 55, 22));
        MainWindow->setCentralWidget(mainWidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1359, 17));
=======
        pushButton = new QPushButton(mainWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(700, 30, 80, 18));
        line = new QFrame(mainWidget);
        line->setObjectName("line");
        line->setGeometry(QRect(120, 30, 20, 501));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(mainWidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(620, 30, 20, 501));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(mainWidget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(130, 520, 501, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(mainWidget);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(130, 20, 501, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(mainWidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
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
<<<<<<< HEAD
#if QT_CONFIG(accessibility)
        canvasLabel->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        canvasLabel->setText(QString());
        saveProjectButton->setText(QCoreApplication::translate("MainWindow", "Save Project", nullptr));
        loadProjectButton->setText(QCoreApplication::translate("MainWindow", "Load Project", nullptr));
        createProjectButton->setText(QCoreApplication::translate("MainWindow", "Create Project", nullptr));
        previewLabel->setText(QCoreApplication::translate("MainWindow", "Preview Window", nullptr));
        newFrameButton->setText(QCoreApplication::translate("MainWindow", "New Frame", nullptr));
        nextFrameButton->setText(QCoreApplication::translate("MainWindow", "Next Frame", nullptr));
        previousFrameButton->setText(QCoreApplication::translate("MainWindow", "Previous Frame", nullptr));
        frameLabel1->setText(QString());
        frameLabel2->setText(QString());
        frameLabel3->setText(QString());
        frameLabel4->setText(QString());
        frameLabel5->setText(QString());
        eraseButton->setText(QCoreApplication::translate("MainWindow", "Erase", nullptr));
        eraseScreen->setText(QCoreApplication::translate("MainWindow", "Erase Screen", nullptr));
=======
        transparentLabel->setText(QCoreApplication::translate("MainWindow", "\n"
"\n"
"Transparent Layer", nullptr));
        onionLabel->setText(QCoreApplication::translate("MainWindow", "\n"
"Onion Laya", nullptr));
        canvasLabel->setText(QCoreApplication::translate("MainWindow", "There is text on this QLabel", nullptr));
        saveProjectButton->setText(QCoreApplication::translate("MainWindow", "Save Project", nullptr));
        loadProjectButton->setText(QCoreApplication::translate("MainWindow", "Load Project", nullptr));
        createProjectButton->setText(QCoreApplication::translate("MainWindow", "Create Project", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "onion", nullptr));
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
