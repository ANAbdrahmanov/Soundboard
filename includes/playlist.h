#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QString>
#include <vector>
#include "track.h"

class Playlist
{
    std::vector<Track> trackList;
public:
    Playlist() = delete;
    Playlist(QString); //есть путь возвращает в ресурсник новую папку/плейлист !!!!!!!outdated
    ~Playlist(); // !!!удаляет из ресурсников плейлист!!!(нет)
    size_t getSize();
};

#endif // PLAYLIST_H
