#ifndef Client_H
#define Client_H
#include "PhotoGram.h"

class Client
{
  public:
    Client();
    ~Client();

    bool downloadAlbum(PhotoGram* pg, const string& albumTitle);
    bool displayOnlinePhoto(PhotoGram* pg, const string& albumTitle, const string& photoTitle) const;
    bool displayLocalPhoto(const string& albumTitle, const string& photoTitle) const;
    void printLocalAlbums() const;
    void displayLocalAlbums() const;

  private:
    AlbumArray* albums;
    int albumsSize;
   
};
#endif