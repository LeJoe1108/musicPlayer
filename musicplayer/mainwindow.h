#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFileDialog>
#include <QSystemTrayIcon>
#include <QAction>
#include <QTime>
#include<QComboBox>
#include <QTimer>
#include <QFileInfo>
#include <QSlider>
#include <QTime>
#include <QSystemTrayIcon>
#include <QAction>
#include <QApplication>
#include <QMenu>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    QString path,music_name;
    QMediaPlayer *music;
    QSlider *positionSlider;
    QTimer *timer;
    QTime time1;
    QDateTime time;
    QMediaPlaylist *playlist;
    QComboBox *playstylecombox;
    QSystemTrayIcon *systemTray;
    QAction* minimumAct;
    QAction* maximumAct;
    QAction* restoreAct;
    QAction* quitAct;
    QAction* stopAct;
    QMenu* pContextMenu;
     // int currentIndex;
    void timeout(void);void on_pushButton_2_clicked();


private slots:

    void on_playButton_clicked();

    void on_pauseButton_clicked();

    void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void setPosition(void);
    void updateTime(void);
    void seekForward(void);
    void seekBackward(void);
    void playTo(int i,int j);
    void on_verticalSlider_valueChanged(int value);
//    void playName(int i,int j);
    void geCi(int i,int j);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
