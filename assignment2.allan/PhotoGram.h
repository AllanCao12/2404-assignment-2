#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include "AlbumArray.h"

class PhotoGram
{
  public:
    PhotoGram();
    ~PhotoGram();

    bool addAlbum(const string& albumTitle, const string& description);
    bool addPhoto(const string& albumTitle, const Photo& photo);
    bool removeAlbum(const string& albumTitle);
    bool removePhoto(const string& albumTitle, const string& photoTitle);
    Album* downloadAlbum(const string& albumTitle);
    Photo* downloadPhoto(const string& albumTitle, const string& photoTitle);
    void printAlbums();
    void displayAlbums();
    

  private:
    AlbumArray* albums;
   
};
#endif