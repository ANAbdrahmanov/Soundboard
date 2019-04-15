#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QString>
#include <QStringList>
#include <vector>
#include "track.h"

class Playlist
{
    std::vector<Track> trackList;
    QString path;
public:
    Playlist() = delete;
    Playlist(QString); //хранит в себе путь ПЕРЕДЕЛАТЬ ПЛЕЙЛИСТ, ХРАНИТЬ ПУТЬ В НЕМ, А НЕ В ТРЕКЕ
    //~Playlist(); // внести в файл настроек все пути либо тут, либо в деструкторе   ;  сам деструктор реализовать бы кста
    void updatePlaylist(); //обновляет треклист, прошерстив заново path, создать функцию сбора файлов
    QStringList toStringList();
    size_t getSize();
};

#endif // PLAYLIST_H
