/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *read;
    QTextEdit *write;
    QHBoxLayout *horizontalLayout;
    QPushButton *listen;
    QPushButton *send;
    QPushButton *stop;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *sendcomboBox;
    QComboBox *stopcomboBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(394, 353);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        read = new QTextEdit(centralWidget);
        read->setObjectName(QStringLiteral("read"));

        gridLayout->addWidget(read, 0, 0, 1, 1);

        write = new QTextEdit(centralWidget);
        write->setObjectName(QStringLiteral("write"));

        gridLayout->addWidget(write, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listen = new QPushButton(centralWidget);
        listen->setObjectName(QStringLiteral("listen"));

        horizontalLayout->addWidget(listen);

        send = new QPushButton(centralWidget);
        send->setObjectName(QStringLiteral("send"));

        horizontalLayout->addWidget(send);

        stop = new QPushButton(centralWidget);
        stop->setObjectName(QStringLiteral("stop"));

        horizontalLayout->addWidget(stop);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        sendcomboBox = new QComboBox(centralWidget);
        sendcomboBox->setObjectName(QStringLiteral("sendcomboBox"));

        horizontalLayout_2->addWidget(sendcomboBox);

        stopcomboBox = new QComboBox(centralWidget);
        stopcomboBox->setObjectName(QStringLiteral("stopcomboBox"));

        horizontalLayout_2->addWidget(stopcomboBox);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 394, 23));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        listen->setText(QApplication::translate("MainWindow", "listen", 0));
        send->setText(QApplication::translate("MainWindow", "send", 0));
        stop->setText(QApplication::translate("MainWindow", "stop", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
