#include "playlist.h"

Playlist::Playlist(QString n, QString p){
    name = n;
    path = p;
    //РАСШИРИТЬ ДЛЯ ТРЕКОВ, АУ
}

//QStringList Playlist::toStringList(){
//    QStringList result;
//    for(Track x : trackList){
//        result << x.getName();
//    }
//    return result;
//}  RESERVED

size_t Playlist::getSize(){
    return trackList.size();
}

QString
