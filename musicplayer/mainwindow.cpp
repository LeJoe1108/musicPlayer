#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QWidget>
#include <QDialog>
#include <QUrl>
#include <QtGlobal>
#include <QtGui>
#include <QFileInfo>
#include <QMessageBox>
#include <QTextStream>
#include <QTextEdit>
#include <QSystemTrayIcon>
#include <QAction>
#include <QApplication>
#include <QMenu>

#define TIME_MS_DURATION 1000

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    music=new QMediaPlayer ;//创建媒体
    playlist = new QMediaPlaylist;
    music->setPlaylist(playlist);


    this->setWindowTitle("music");//标题
    this->setFixedSize(475, 400);  //窗口大小
    this->setWindowIcon(QIcon(":/res/img/player.png")); //图标
    ui->playButton->setIcon(QIcon(":/res/img/play1.png"));
    ui->pauseButton->setIcon(QIcon(":/res/img/pause1.png"));
    ui->leftButton->setIcon(QIcon(":/res/img/left1.png"));
    ui->rightButton->setIcon(QIcon(":/res/img/right1.png"));



    //新建QSystemTrayIcon对象
    systemTray = new QSystemTrayIcon(this);
    //新建托盘要显示的icon
    QIcon icon = QIcon(":/res/img/player.png");
    //将icon设到QSystemTrayIcon对象中
    systemTray->setIcon(icon);
    //当鼠标移动到托盘上的图标时，会显示此处设置的内容
    systemTray->setToolTip(QObject::trUtf8("musicplayer"));
    //在系统托盘显示此对象
    systemTray->show();
    minimumAct = new QAction("Minimum Window", this);
        //Note the differences between hide() and showMinimized().
        connect(minimumAct, SIGNAL(triggered()), this, SLOT(hide()));
        maximumAct = new QAction("Maximum Window", this);
        connect(maximumAct, SIGNAL(triggered()), this, SLOT(showMaximized()));
        restoreAct = new QAction("Restore Window", this);
        connect(restoreAct, SIGNAL(triggered()), this, SLOT(showNormal()));
        quitAct = new QAction("Quit Application", this);
        connect(quitAct, SIGNAL(triggered()), qApp, SLOT(quit()));
        stopAct = new QAction("stop music", this);
        connect(stopAct, SIGNAL(triggered()), this, SLOT(on_pauseButton_clicked()));
        pContextMenu = new QMenu(this);
        pContextMenu->addAction(minimumAct);
        pContextMenu->addAction(maximumAct);
        pContextMenu->addAction(restoreAct);
         pContextMenu->addAction(stopAct);
        pContextMenu->addSeparator();
        pContextMenu->addAction(quitAct);
        systemTray->setContextMenu(pContextMenu);
        systemTray->show();



    //初始化为列表循环播放
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    //设置滑动条控件的最小值
    ui->verticalSlider->setMinimum(0);
    //设置滑动条控件的最大值
    ui->verticalSlider->setMaximum(100);
    ui->verticalSlider->setValue(50);  //默认音量
    music->setVolume(ui->verticalSlider->value());

    timer=new QTimer;//定时器
    time1.setHMS(0,0,0);

    connect(timer,SIGNAL(timeout()),this,SLOT(setPosition()));
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    connect(ui->rightButton,SIGNAL(clicked()),this,SLOT(seekForward()));
    connect(ui->leftButton,SIGNAL(clicked()),this,SLOT(seekBackward()));
    connect(ui->musiclistWidget,SIGNAL(cellClicked(int,int)),this,SLOT(playTo(int,int))); //所调用的槽函数为playTo
    //点击按钮获取歌名
 //   connect(ui->rightButton,SIGNAL(clicked()),this,SLOT(playName(int,int)));
    //当单击某行单元格时，根据各歌曲名找到对应的歌词
    connect(ui->musiclistWidget,SIGNAL(cellClicked(int,int)),this,SLOT(geCi(int,int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//播放按钮
void MainWindow::on_playButton_clicked()
{
    music->play();

}

//暂停按钮
void MainWindow::on_pauseButton_clicked()
{
    music->pause();
}

//导入歌曲
void MainWindow::on_pushButton_clicked()
{
    //QString initialName=QDir::homePath();//返回一个用户的全路径
    QStringList pathList=QFileDialog::getOpenFileNames(this, "选择歌曲", "F:/CloudMusic", "*.mp3");
    for(int i=0; i<pathList.size(); ++i)
    {
        path=QDir::toNativeSeparators(pathList.at(i)); //把斜杠转化成反斜杠
        if(!path.isEmpty())
        {
            playlist->addMedia(QUrl::fromLocalFile(path));//加入到播放列表
            QString fileName=path.split("\\").last();//用斜杠分开，取最后一个名字
            int rownum=ui->musiclistWidget->rowCount();
            ui->musiclistWidget->insertRow(rownum);//为整个table插入一行行号为rownum，也就是说一首歌的信息占据一行的位置
            ui->musiclistWidget->setItem(rownum, 0, new QTableWidgetItem(fileName.split(".").front()));
            ui->musiclistWidget->setItem(rownum, 1, new QTableWidgetItem(fileName.split(".").last()));
            //    ui->musiclistWidget->setItem(rownum,2,new QTableWidgetItem(path));
            ui->musiclistWidget->item(rownum,1)->setFlags(Qt::NoItemFlags);
            // ui->musiclistWidget->item(rownum,2)->setFlags(Qt::NoItemFlags);

        }
    }
    ui->musiclistWidget->horizontalHeader()->setStretchLastSection(true);
    ui->musiclistWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->musiclistWidget->setStyleSheet("background-image:url(:/res/img/5.png;");
    //ui->musiclistWidget->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色
    ui->musiclistWidget->setShowGrid(false); //设置不显示格子线

    //    ui->musiclistWidget->verticalHeader()->setVisible(false); //设置垂直头不可见

}


/*播放条快进快退*/
void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if (qAbs(music->position() - value) > 10)
    {
        music->setPosition(value);
    }
}

qint64 current_position;

//设置播放进度条
void MainWindow::setPosition()
{
    int n=0;

    current_position=music->position();//获取音乐当前播放位置
       ui->horizontalSlider->setMaximum(music->duration());//获取音乐总长度(注意:这个长度是音乐大小)

       if(current_position >= ui->horizontalSlider->maximum())//播放完毕
        {
            music->stop();
            ui->horizontalSlider->setSliderPosition(0);
           time.setTime(time1);//重新把时间标签改为00:00
            return;
         }

       ui->horizontalSlider->setSliderPosition(current_position);//刷新滑块位置

}

 /*本函数与定时器相连,计算播放时间*/
void MainWindow::updateTime()
{
    ui->horizontalSlider->setValue(current_position);
    QTime duration(0, current_position / 60000, qRound((current_position % 60000) / 1000.0));
    ui->all_timelabel->setText(duration.toString(tr("mm:ss")));
}


//下一首
void MainWindow::seekForward()
{
    int currentIndex=playlist->currentIndex();
    if(++currentIndex==playlist->mediaCount())
     currentIndex=0;
    playlist->setCurrentIndex(currentIndex);
    music->play();

}

//上一首
void MainWindow::seekBackward()
{
    playlist->previous();
    music->play();
}

//点击列表播放音乐
void MainWindow::playTo(int i,int j)
{
    timer->start(1000);
    playlist->setCurrentIndex(i);
    music->play();

    ui->playButton->setEnabled(true);

    music_name="";
//    QFileInfo info();   //获取音乐名
    music_name+=ui->musiclistWidget->item(i,j)->text();
    ui->music_namelabel->setText(music_name);

    time.setTime(time1);

}


//控制音量
void MainWindow::on_verticalSlider_valueChanged(int value)
{
    music->setVolume(value);
}

//获取歌名
//void MainWindow::playName()
//{


//}

//显示歌词部分
void MainWindow::geCi(int i,int j)
{
//    if(ui->checkBox->isChecked()==true)
//    {
        QString str=ui->musiclistWidget->item(i,j)->text();
        qDebug()<<str;//打印歌名
        QFile file( "F:/CloudMusic/"+str+".lrc");
        /*if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            QMessageBox::information(this, tr("information"), "can not found");
        }
        else
        {
            QTextStream in(&file);
            QString result=in.readAll();
            ui->textEdit->setText(result);
            ui->textEdit->isReadOnly();
        }*/

}
/*void Widget::on_playstylecombox_currentIndexChanged(int index)
{
    if(index==0)
    {
        mediaList->setPlaybackMode(playlist::Sequential);//顺序播放
    }
    else
    {
        if(index==1)
         {
            mediaList->setPlaybackMode(playlist::Random); //随机播放
         }
        else
        {
           if(index==2)
           {
              mediaList->setPlaybackMode(playlist::Loop); //列表循环
           }
           else
           {
              mediaList->setPlaybackMode(playlist::CurrentItemInLoop); //单曲循环
           }
        }
    }
}
*/
