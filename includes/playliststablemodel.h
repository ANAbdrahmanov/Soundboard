#ifndef PLAYLISTSTABLEMODEL_H
#define PLAYLISTSTABLEMODEL_H

#include <QAbstractTableModel>
#include <vector>
#include "playlist.h"


class PlaylistsTableModel : public QAbstractTableModel
{
    Q_OBJECT
    
    enum Column{
        NAME = 0,
        HOTKEY,
        LAST
    };
    
    std::vector<Playlist> playlists;
    
public:
    explicit PlaylistsTableModel(QObject* parent = nullptr);
//    virtual ~PlaylistsTableModel() {}
    
    int rowCount(const QModelIndex&) const override;
    int columnCount(const QModelIndex&) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    //bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    bool appendPlaylist(Playlist); //true, если добавлено, если уже есть такой путь то
};

#endif // PLAYLISTSTABLEMODEL_H
