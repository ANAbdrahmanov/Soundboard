#ifndef SOUNDBOARD_H
#define SOUNDBOARD_H

#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QTableWidget>
#include "playlist.h"

namespace Ui {
class Soundboard;
}

class Soundboard : public QWidget
{
    Q_OBJECT

    void initGui();//???
    Q_SLOT void addPlaylist();
    void saveSettings();
    void loadSettings();

public:
    explicit Soundboard(QWidget *parent = nullptr);
    ~Soundboard();



private:
    QTableView* tableView;
    QMediaPlayer* player;
    QPushButton* testPlay;
    QPushButton* testStop;
    QPushButton* addPlaylistButton;
    QPushButton* refreshPlaylistButton;
    Ui::Soundboard *ui;
};

#endif // SOUNDBOARD_H
