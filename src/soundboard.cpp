#include "soundboard.h"
#include "ui_soundboard.h"

Soundboard::Soundboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Soundboard)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    testPlay = new QPushButton(this);
}

Soundboard::~Soundboard()
{
    delete ui;
}
