#ifndef PHOTOARRAY_H
#define PHOTOARRAY_H

#define MAX_ARR 64
#include "Photo.h"

class PhotoArray
{
  public:
    PhotoArray();
    ~PhotoArray();

    bool addPhoto(Photo*);
    bool addPhoto(const int index, Photo*);
    Photo* getPhoto(const string& title) const;
    Photo* getPhoto(const int index) const;
    Photo* remove(const string& title);
    Photo* remove(const int index);
    bool isFull() const;
    int size() const;
    

  private:
    Photo** elements;
    int elementSize;
   
};
#endif
