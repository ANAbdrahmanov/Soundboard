#include "soundboard.h"
#include "ui_soundboard.h"
#include <QGridLayout>
#include <QDebug>
#include <QUrl>
#include <QStringList>
#include "playlist.h"

Soundboard::Soundboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Soundboard)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    QGridLayout* layout = new QGridLayout(this);         //ИНПУТ ЮЗЕРОМ В ЭДД
    testPlay = new QPushButton("Play", this);
    testStop = new QPushButton("Stop", this);
    testAdd = new QPushButton("+", this);                 //где-т тут вкладки создать

    playlists = new QTableWidget(3,3,this);                        //менять на QTableWidget/View    пересмотреть необходимость Playlist класса
    playlists->setHorizontalHeaderLabels(QStringList() << "name" << "size" << "hotkey"); //ДОБАВИТЬ РЕСУРСНИК С НАСТРОЙКАМИ, ЗАПОМИНАЮЩИЙ ИНФУ О ПЛЕЙЛИСТАХ
    //растягивать саму таблицу вместе с виджетом таблицы !!! убрать цифры по вертикали
    layout->addWidget(testPlay,0,0);
    layout->addWidget(testStop,0,1);
    layout->addWidget(playlists,1,0,2,1);
    layout->addWidget(testAdd,1,1);
    //player->setMedia(QUrl::fromLocalFile(QFileInfo("./sound/the-fuck.mp3").absoluteFilePath()));//заменить на ресурсник
    player->setMedia(QUrl::fromLocalFile("C://Users//Aidar//Documents//Soundboard//sound//the-fuck.mp3"));
    player->setVolume(30);
    //qDebug()<<player->currentMedia().canonicalUrl().toDisplayString();
    connect(testPlay, &QPushButton::clicked, player, &QMediaPlayer::play); //изменить обработчик плея, чтобы плей перезапускал уже играющий треk
    connect(testStop, &QPushButton::clicked, player, &QMediaPlayer::stop);
}

Soundboard::~Soundboard()
{
    delete ui;
}
