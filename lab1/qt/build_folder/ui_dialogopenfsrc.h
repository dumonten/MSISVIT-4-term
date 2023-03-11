/********************************************************************************
** Form generated from reading UI file 'dialogopenfsrc.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOPENFSRC_H
#define UI_DIALOGOPENFSRC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogOpenFSrc
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *centralwidget;
    QPlainTextEdit *initFSrcField;
    QHBoxLayout *lyButtons;
    QSpacerItem *btSpacer;
    QPushButton *btnSave;

    void setupUi(QDialog *DialogOpenFSrc)
    {
        if (DialogOpenFSrc->objectName().isEmpty())
            DialogOpenFSrc->setObjectName(QString::fromUtf8("DialogOpenFSrc"));
        DialogOpenFSrc->resize(800, 562);
        verticalLayout_2 = new QVBoxLayout(DialogOpenFSrc);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        centralwidget = new QVBoxLayout();
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        initFSrcField = new QPlainTextEdit(DialogOpenFSrc);
        initFSrcField->setObjectName(QString::fromUtf8("initFSrcField"));

        centralwidget->addWidget(initFSrcField);

        lyButtons = new QHBoxLayout();
        lyButtons->setObjectName(QString::fromUtf8("lyButtons"));
        btSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lyButtons->addItem(btSpacer);

        btnSave = new QPushButton(DialogOpenFSrc);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        lyButtons->addWidget(btnSave);


        centralwidget->addLayout(lyButtons);


        verticalLayout_2->addLayout(centralwidget);


        retranslateUi(DialogOpenFSrc);

        QMetaObject::connectSlotsByName(DialogOpenFSrc);
    } // setupUi

    void retranslateUi(QDialog *DialogOpenFSrc)
    {
        DialogOpenFSrc->setWindowTitle(QCoreApplication::translate("DialogOpenFSrc", "\320\236\320\272\320\275\320\276 \321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        btnSave->setText(QCoreApplication::translate("DialogOpenFSrc", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogOpenFSrc: public Ui_DialogOpenFSrc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOPENFSRC_H
