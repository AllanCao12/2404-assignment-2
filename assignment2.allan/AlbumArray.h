#ifndef ALBUMARRAY_H
#define ALBUMARRAY_H

#include "Album.h"

class AlbumArray
{
  public:
    AlbumArray();
    AlbumArray(const AlbumArray& albumArray);
    ~AlbumArray();

    bool add(Album*);
    //bool lessThan(Album&);
    Album* get(const string& title) const;
    Album* get(const int index) const;
    Album* remove(const string& title);
    Album* remove(const int index);
    bool isFull() const;
    int size() const;
    

  private:
    Album** elements;
    int elementSize;
   
};
#endif
