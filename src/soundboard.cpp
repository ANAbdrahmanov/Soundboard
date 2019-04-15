#include "soundboard.h"
#include "ui_soundboard.h"
#include <QGridLayout>
#include <QDebug>
#include <QUrl>
#include <QStringList>
#include "playlist.h"
#include <QDir>
#include <QSettings>
#include <QFileDialog>

Soundboard::Soundboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Soundboard)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);        //весь этот хлам вынести в initGui();
    QGridLayout* layout = new QGridLayout(this);
    testPlay = new QPushButton("Play", this);
    testStop = new QPushButton("Stop", this);
    addPlaylistButton = new QPushButton("+", this);                 //где-т тут вкладки создать

    playlistsTable = new QTableWidget(3,3,this);
    playlistsTable->setHorizontalHeaderLabels(QStringList() << "name" << "size" << "hotkey");
    //растягивать саму таблицу вместе с виджетом таблицы !!! убрать цифры по вертикали
    layout->addWidget(testPlay,0,0);
    layout->addWidget(testStop,0,1);
    layout->addWidget(playlistsTable,1,0,1,3);
    layout->addWidget(addPlaylistButton,0,2);
    //player->setMedia(QUrl::fromLocalFile(QFileInfo("./sound/the-fuck.mp3").absoluteFilePath())); поковыряться еще тут
    player->setMedia(QUrl::fromLocalFile("C://Users//Aidar//Documents//Soundboard//sound//the-fuck.mp3"));
    player->setVolume(30);
    //qDebug()<<player->currentMedia().canonicalUrl().toDisplayString(); //этот дебаг не трогать


    QSettings settings(QDir::currentPath() + "/" + "settings.ini", QSettings::IniFormat, this);
    connect(testPlay, &QPushButton::clicked, player, &QMediaPlayer::play); //изменить обработчик плея, чтобы плей перезапускал уже играющий треk
    connect(testStop, &QPushButton::clicked, player, &QMediaPlayer::stop);
    connect(addPlaylistButton, &QPushButton::clicked, this, &Soundboard::addPlaylist);

}


//void Soundboard::initGui(){
//    player = new QMediaPlayer(this);        //весь этот хлам вынести в initGui(); собсна таковую и создать в h
//    QGridLayout* layout = new QGridLayout(this);         //ИНПУТ ЮЗЕРОМ В ЭДД
//    testPlay = new QPushButton("Play", this);
//    testStop = new QPushButton("Stop", this);
//    testAdd = new QPushButton("+", this);                 //где-т тут вкладки создать
//}

void Soundboard::saveSettings(){
    QSettings settings(QDir::currentPath() + "/" + "settings.ini", QSettings::IniFormat, this);
    //settings.setValue("playlists",)  СТОИТ ВЫДУМАТЬ КАК ВСЕ-ТАКИ СЕЙВИТЬ ПЛЕЙЛИСТЫ И ТРЕКИ В НИХ ВЛОЖЕННЫЕ, ХОТЯ ЭНИВЕЙ АПДЕТИТЬ СТОИТ МОЖЕТ И НЕ НАДО
}

void Soundboard::addPlaylist(){
    QString temp = QFileDialog::getExistingDirectory(nullptr,tr("Select Playlist"),"",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(!temp.isEmpty()){
        Playlist p(temp);
        //ЗДЕСЬ ВПОСЛЕДСТВИИ ДОБАВИТЬ ПОИСК ТРЕКОВ И ЭДД ИХ В ПЛЕЙЛИСТ НИЖЕ, РАСШИРИТЬ КОНСТРУКТОР ДЛЯ ЭТОГО
        playlists.push_back(p);
    }
}

Soundboard::~Soundboard()
{
    delete ui;
}
