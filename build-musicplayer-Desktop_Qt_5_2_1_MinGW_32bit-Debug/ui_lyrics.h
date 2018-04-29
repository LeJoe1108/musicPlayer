/********************************************************************************
** Form generated from reading UI file 'lyrics.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LYRICS_H
#define UI_LYRICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Lyrics
{
public:
    QLineEdit *lineEdit;

    void setupUi(QDialog *Lyrics)
    {
        if (Lyrics->objectName().isEmpty())
            Lyrics->setObjectName(QStringLiteral("Lyrics"));
        Lyrics->resize(400, 300);
        lineEdit = new QLineEdit(Lyrics);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 20, 221, 251));

        retranslateUi(Lyrics);

        QMetaObject::connectSlotsByName(Lyrics);
    } // setupUi

    void retranslateUi(QDialog *Lyrics)
    {
        Lyrics->setWindowTitle(QApplication::translate("Lyrics", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class Lyrics: public Ui_Lyrics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LYRICS_H
