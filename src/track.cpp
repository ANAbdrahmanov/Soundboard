#include "track.h"

Track::Track(QString n, QString p){
    name = n;
    path = p;
}

QString Track::getName(){
    return name;
}

QString Track::getPath(){
    return path;
}

void Track::setName(QString n){
    name = n;
}
