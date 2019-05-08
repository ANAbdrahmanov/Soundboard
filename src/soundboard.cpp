#include <QGridLayout>
#include <QDebug>
#include <QUrl>
#include <QStringList>
#include <QDir>
#include <QSettings>
#include <QFileDialog>
#include <QHeaderView>
#include <QAbstractItemView>
#include "soundboard.h"
#include "ui_soundboard.h"
#include "playlist.h"

Soundboard::Soundboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Soundboard)
{
    ui->setupUi(this);
    //РЕАЛИЗОВАТЬ АПДЕЙТ ЧЕРЕЗ СЕТЬ, А ТО ЧО КАК ЛОХ
    player = new QMediaPlayer(this);        //весь этот хлам вынести в initGui();
    QGridLayout* layout = new QGridLayout(this); //в трей сворачивать
    testPlay = new QPushButton("Play", this);
    testStop = new QPushButton("Stop", this);
    refreshPlaylistButton = new QPushButton("Refresh", this);
    addPlaylistButton = new QPushButton("+", this);                 

    tableView = new QTableView(this);//сетап таблицы тоже в инитгуи по идее, потому что верхушка (хоризонтал лейблз) в треках уже нужна
    //playlistsTable->setHorizontalHeaderLabels(QStringList() << "name" << "path" << "hotkey"); //для плейлистов мож и не надо
    tableView->verticalHeader()->hide();
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);       //??
    //растягивать саму таблицу вместе с виджетом таблицы !!!
    
    layout->addWidget(testPlay,0,0);
    layout->addWidget(testStop,0,1);
    layout->addWidget(tableView,1,0,1,3);
    layout->addWidget(addPlaylistButton,0,2);
    layout->addWidget(refreshPlaylistButton,0,3);
    //player->setMedia(QUrl::fromLocalFile(QFileInfo("./sound/the-fuck.mp3").absoluteFilePath())); поковыряться еще тут
    player->setMedia(QUrl::fromLocalFile("C://Users//Aidar//Documents//Soundboard//sound//the-fuck.mp3"));
    player->setVolume(30);
    //qDebug()<<player->currentMedia().canonicalUrl().toDisplayString(); //этот дебаг не трогать


    QSettings settings(QDir::currentPath() + "/" + "settings.ini", QSettings::IniFormat, this);
    connect(testPlay, &QPushButton::clicked, player, &QMediaPlayer::play); //изменить обработчик плея, чтобы плей перезапускал уже играющий треk
    connect(testStop, &QPushButton::clicked, player, &QMediaPlayer::stop); //плеер заменить на девайc по идее впоследствии
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

    //settings.setValue("playlists",)  //СТОИТ ВЫДУМАТЬ КАК ВСЕ-ТАКИ СЕЙВИТЬ ПЛЕЙЛИСТЫ И ТРЕКИ В НИХ ВЛОЖЕННЫЕ, ХОТЯ ЭНИВЕЙ АПДЕТИТЬ СТОИТ МОЖЕТ И НЕ НАДО
}

void Soundboard::addPlaylist(){
    QString tempPathHolder = QFileDialog::getExistingDirectory(nullptr,tr("Select Playlist"),"",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(!tempPathHolder.isEmpty()){
        //int tempTableSizeHolder = playlistsTable->rowCount();
        //Playlist p(QString("playlist%1").arg(tempTableSizeHolder + 1) ,tempPathHolder);
        //ЗДЕСЬ ВПОСЛЕДСТВИИ ДОБАВИТЬ ПОИСК ТРЕКОВ И ЭДД ИХ В ПЛЕЙЛИСТ НИЖЕ, РАСШИРИТЬ КОНСТРУКТОР ДЛЯ ЭТОГО
        //playlists.push_back(p);

 //       playlistsTable->
    }
}

Soundboard::~Soundboard()
{
    delete ui;
}
