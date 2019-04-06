#ifndef SOUNDBOARD_H
#define SOUNDBOARD_H

#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QListWidget>

namespace Ui {
class Soundboard;
}

class Soundboard : public QWidget
{
    Q_OBJECT

public:
    explicit Soundboard(QWidget *parent = nullptr);
    ~Soundboard();



private:
    //QString soundsDirectory;???
    QListWidget* playlists;
    QMediaPlayer* player;
    QPushButton* testPlay;
    QPushButton* testStop;
    QPushButton* testAdd;
    QPushButton* testRemove;
    Ui::Soundboard *ui;
};

#endif // SOUNDBOARD_H
