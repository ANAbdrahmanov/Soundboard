#include "playliststablemodel.h"

PlaylistsTableModel::PlaylistsTableModel(QObject* parent) : QAbstractTableModel (parent){}

int PlaylistsTableModel::rowCount(const QModelIndex &) const
{
    return playlists.size();
}

int PlaylistsTableModel::columnCount(const QModelIndex &) const
{

}

QVariant PlaylistsTableModel::data(const QModelIndex& index, int role) const {

    if(
        !index.isValid() ||
        playlists.size() <= index.row() ||
        ( role != Qt::DisplayRole && role != Qt::EditRole )
    ) {
        return QVariant();
    }
    return playlists[index.row()].getColumn(index.column());
}

bool PlaylistsTableModel::appendPlaylist(Playlist newPlaylist){
    for(Playlist p : playlists){
        if(p.getPath() == newPlaylist.getPath()){
            return false;
        }
    }
    playlists.push_back(newPlaylist);
    return true;
}
