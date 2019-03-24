#ifndef SOUNDBOARD_H
#define SOUNDBOARD_H

#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>

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
    QMediaPlayer* player;
    QPushButton* testPlay;
    QPushButton* testPause;
    Ui::Soundboard *ui;
};

#endif // SOUNDBOARD_H
