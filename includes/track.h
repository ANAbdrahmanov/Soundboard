#ifndef TRACK_H
#define TRACK_H

#include <QString>

class Track
{
    QString name;
    //QString path;
    int volume;  //внутренняя громкость трека для всякой перегруженной дичи
    int duration;//квесченабл на вид чо, но само поле длины нужно
public:
    Track() = delete;
    Track(QString, int);
    QString getName();
    QString getPath();
    void setName(QString);
    void setVolume(int);
};

#endif // TRACK_H
