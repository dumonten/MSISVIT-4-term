/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *lyTotal;
    QVBoxLayout *lyHeader;
    QHBoxLayout *lyButtons;
    QPushButton *btnStart;
    QPushButton *pushButton;
    QSpacerItem *btnSpacer;
    QLabel *startLabel;
    QHBoxLayout *lyTabel;
    QTableWidget *tableOperators;
    QTableWidget *tableOperands;
    QVBoxLayout *lyFooter;
    QLabel *resTextLabel;
    QHBoxLayout *lyResText;
    QPlainTextEdit *resText;
    QSpacerItem *resTextSpacer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(960, 1000);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(960, 1000));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lyTotal = new QVBoxLayout();
        lyTotal->setObjectName(QString::fromUtf8("lyTotal"));
        lyHeader = new QVBoxLayout();
        lyHeader->setObjectName(QString::fromUtf8("lyHeader"));
        lyButtons = new QHBoxLayout();
        lyButtons->setObjectName(QString::fromUtf8("lyButtons"));
        btnStart = new QPushButton(centralwidget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));

        lyButtons->addWidget(btnStart);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        lyButtons->addWidget(pushButton);

        btnSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lyButtons->addItem(btnSpacer);


        lyHeader->addLayout(lyButtons);

        startLabel = new QLabel(centralwidget);
        startLabel->setObjectName(QString::fromUtf8("startLabel"));

        lyHeader->addWidget(startLabel);


        lyTotal->addLayout(lyHeader);

        lyTabel = new QHBoxLayout();
        lyTabel->setObjectName(QString::fromUtf8("lyTabel"));
        lyTabel->setSizeConstraint(QLayout::SetDefaultConstraint);
        tableOperators = new QTableWidget(centralwidget);
        tableOperators->setObjectName(QString::fromUtf8("tableOperators"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableOperators->sizePolicy().hasHeightForWidth());
        tableOperators->setSizePolicy(sizePolicy);
        tableOperators->setMaximumSize(QSize(600, 16777215));
        tableOperators->horizontalHeader()->setStretchLastSection(false);

        lyTabel->addWidget(tableOperators);

        tableOperands = new QTableWidget(centralwidget);
        tableOperands->setObjectName(QString::fromUtf8("tableOperands"));
        sizePolicy.setHeightForWidth(tableOperands->sizePolicy().hasHeightForWidth());
        tableOperands->setSizePolicy(sizePolicy);
        tableOperands->setMaximumSize(QSize(600, 16777215));
        tableOperands->horizontalHeader()->setStretchLastSection(false);

        lyTabel->addWidget(tableOperands);

        lyTabel->setStretch(0, 2);
        lyTabel->setStretch(1, 2);

        lyTotal->addLayout(lyTabel);

        lyFooter = new QVBoxLayout();
        lyFooter->setObjectName(QString::fromUtf8("lyFooter"));
        resTextLabel = new QLabel(centralwidget);
        resTextLabel->setObjectName(QString::fromUtf8("resTextLabel"));

        lyFooter->addWidget(resTextLabel);

        lyResText = new QHBoxLayout();
        lyResText->setObjectName(QString::fromUtf8("lyResText"));
        resText = new QPlainTextEdit(centralwidget);
        resText->setObjectName(QString::fromUtf8("resText"));
        resText->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 71, 71);"));
        resText->setReadOnly(true);

        lyResText->addWidget(resText);

        resTextSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lyResText->addItem(resTextSpacer);

        lyResText->setStretch(0, 1);
        lyResText->setStretch(1, 1);

        lyFooter->addLayout(lyResText);

        lyFooter->setStretch(0, 1);
        lyFooter->setStretch(1, 10);

        lyTotal->addLayout(lyFooter);

        lyTotal->setStretch(0, 1);
        lyTotal->setStretch(1, 10);
        lyTotal->setStretch(2, 1);

        verticalLayout->addLayout(lyTotal);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\321\221\321\202 \320\274\320\265\321\202\321\200\320\270\320\272 \320\245\320\276\320\273\321\201\321\202\320\265\320\264\320\260", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\260\320\275\320\260\320\273\320\270\320\267 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\275\320\276\320\263\320\276 \320\272\320\276\320\264\320\260", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\270\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \320\272\320\276\320\264", nullptr));
        startLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\242\320\260\320\261\320\273\320\270\321\206\321\213 \321\200\320\260\321\201\321\207\321\221\321\202\320\260 \320\261\320\260\320\267\320\276\320\262\321\213\321\205 \320\274\320\265\321\202\321\200\320\270\320\272 \320\245\320\276\320\273\321\201\321\202\320\265\320\264\320\260:</p></body></html>", nullptr));
        resTextLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\240\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\275\321\213\320\265 \320\274\320\265\321\202\321\200\320\270\320\272\320\270 \320\245\320\276\320\273\321\201\321\202\320\265\320\264\320\260:</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
