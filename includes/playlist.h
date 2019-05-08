#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QString>
//#include <QStringList>
#include <vector>
#include "track.h"

class Playlist
{
    std::vector<Track> trackList;
    QString path;
    QString name;
public:
    Playlist() = delete;
    Playlist(QString,QString);
    QString getColumn(int) const;
    QString getPath() const;
    //~Playlist(); // внести в файл настроек все пути либо тут, либо в деструкторе   ;  сам деструктор реализовать бы кста
    void updatePlaylist(); //обновляет треклист, прошерстив заново path, создать функцию сбора файлов
    //QStringList toStringList(); //RESERVED
    size_t getSize();
};

#endif // PLAYLIST_H
