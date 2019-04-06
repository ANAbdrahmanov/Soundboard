#ifndef TRACK_H
#define TRACK_H

#include <QString>

class Track
{
    QString name;
    QString path;
public:
    Track() = delete;
    Track(QString, QString);
    QString getName();
    QString getPath();
    void setName(QString);
};

#endif // TRACK_H
