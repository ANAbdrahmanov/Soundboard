#include "playlist.h"

Playlist::Playlist(QString p){
    path = p;
}

QStringList Playlist::toStringList(){
    QStringList result;
    for(Track x : trackList){
        result << x.getName();
    }
    return result;
}

size_t Playlist::getSize(){
    return trackList.size();
}
