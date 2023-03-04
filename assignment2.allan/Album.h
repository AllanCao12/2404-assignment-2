#ifndef Album_H
#define Album_H
#include "PhotoArray.h"
class Album
{
  public:
    Album(const string& title, const string& description);
    Album(const Album& album);
    ~Album();


  //functions:

  const string& getTitle() const;
  bool equals(const string&) const;
  bool lessThan(const Album& alb) const;
  bool addPhoto(Photo*) ;
  bool addPhoto(const int index, Photo*);
  Photo* getPhoto(const string& title) const;
  Photo* getPhoto(const int index) const;
  Photo* removePhoto(const string& title);
  Photo* removePhoto(const int index);
  void print() const;
  void display() const;
  int size() const; 

  private:
    string title;
    string description;
    PhotoArray* photos;

};
#endif