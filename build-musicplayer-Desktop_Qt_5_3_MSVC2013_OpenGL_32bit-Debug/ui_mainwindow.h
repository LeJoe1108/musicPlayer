/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSlider *verticalSlider;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *music_namelabel;
    QGridLayout *gridLayout;
    QToolButton *pauseButton;
    QToolButton *playButton;
    QToolButton *leftButton;
    QToolButton *rightButton;
    QSpacerItem *horizontalSpacer_5;
    QTableWidget *musiclistWidget;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QFrame *line_3;
    QSlider *horizontalSlider;
    QFrame *line_2;
    QLabel *all_timelabel;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(465, 452);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(40, 100, 391, 25));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(horizontalLayoutWidget_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_3->addWidget(comboBox);

        pushButton = new QPushButton(horizontalLayoutWidget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label = new QLabel(horizontalLayoutWidget_3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        verticalSlider = new QSlider(horizontalLayoutWidget_3);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setMaximumSize(QSize(60, 80));
        verticalSlider->setLayoutDirection(Qt::LeftToRight);
        verticalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(verticalSlider);

        horizontalLayoutWidget_5 = new QWidget(centralWidget);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(40, 10, 391, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        music_namelabel = new QLabel(horizontalLayoutWidget_5);
        music_namelabel->setObjectName(QStringLiteral("music_namelabel"));

        horizontalLayout_4->addWidget(music_namelabel);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, 0, -1, 0);
        pauseButton = new QToolButton(horizontalLayoutWidget_5);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/img/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pauseButton->setIcon(icon);

        gridLayout->addWidget(pauseButton, 0, 2, 1, 1);

        playButton = new QToolButton(horizontalLayoutWidget_5);
        playButton->setObjectName(QStringLiteral("playButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/res/img/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        playButton->setIcon(icon1);

        gridLayout->addWidget(playButton, 0, 1, 1, 1);

        leftButton = new QToolButton(horizontalLayoutWidget_5);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/res/img/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftButton->setIcon(icon2);

        gridLayout->addWidget(leftButton, 0, 0, 1, 1);

        rightButton = new QToolButton(horizontalLayoutWidget_5);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/res/img/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        rightButton->setIcon(icon3);

        gridLayout->addWidget(rightButton, 0, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 4, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);

        musiclistWidget = new QTableWidget(centralWidget);
        if (musiclistWidget->columnCount() < 2)
            musiclistWidget->setColumnCount(2);
        musiclistWidget->setObjectName(QStringLiteral("musiclistWidget"));
        musiclistWidget->setGeometry(QRect(30, 140, 161, 251));
        musiclistWidget->setColumnCount(2);
        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(39, 50, 391, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        line_3 = new QFrame(horizontalLayoutWidget_2);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        horizontalSlider = new QSlider(horizontalLayoutWidget_2);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        line_2 = new QFrame(horizontalLayoutWidget_2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        all_timelabel = new QLabel(horizontalLayoutWidget_2);
        all_timelabel->setObjectName(QStringLiteral("all_timelabel"));

        horizontalLayout->addWidget(all_timelabel);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(210, 140, 231, 251));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 465, 23));
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
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\241\272\345\272\217\346\222\255\346\224\276", 0)
         << QApplication::translate("MainWindow", "\351\232\217\346\234\272\346\222\255\346\224\276", 0)
         << QApplication::translate("MainWindow", "\345\210\227\350\241\250\345\276\252\347\216\257", 0)
         << QApplication::translate("MainWindow", "\345\215\225\346\233\262\345\276\252\347\216\257", 0)
        );
        pushButton->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\346\255\214\346\233\262", 0));
        label->setText(QApplication::translate("MainWindow", "\351\237\263\351\207\217", 0));
        music_namelabel->setText(QApplication::translate("MainWindow", "\346\255\214\346\233\262\345\220\215\345\255\227", 0));
        pauseButton->setText(QApplication::translate("MainWindow", "...", 0));
        playButton->setText(QString());
        leftButton->setText(QString());
        rightButton->setText(QString());
        all_timelabel->setText(QApplication::translate("MainWindow", "00\357\274\23200", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
