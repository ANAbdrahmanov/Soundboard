#include "track.h"

Track::Track(QString n, int v = 100){
    name = n;
    volume = v;
}

QString Track::getName(){
    return name;
}

//QString Track::getPath(){
//    return path;
//}

void Track::setName(QString n){ //\!!!!расширить до ренейма самого файла
    name = n;
}

void Track::setVolume(int v){
    volume = v;
}
