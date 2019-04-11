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
    Playlist(QString); //хранит в себе путь ПЕРЕДЕЛАТЬ ПЛЕЙЛИСТ, ХРАНИТЬ ПУТЬ В НЕМ, А НЕ В ТРЕКЕ
    ~Playlist(); // !!!удаляет из ресурсников плейлист!!!(нет)
    size_t getSize();
};

#endif // PLAYLIST_H
