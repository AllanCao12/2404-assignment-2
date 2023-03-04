#include <iostream>
using namespace std;

#include "Album.h"

Album::Album(const string& title, const string& description){
    this->title = title; 
    this->description = description;
    this->photos = new PhotoArray();
}

Album::Album(const Album& album){ //deep copy
    this->title = album.title;
    this->description = album.description;
    this->photos = new PhotoArray();

    for(int i = 0; i < album.size(); i++){
        this->photos->addPhoto(new Photo(*album.getPhoto(i)));
    }
}

Album::~Album(){
    Photo* temp;
    while(photos->size() > 0){
        temp = photos->remove(0);
        delete temp; 
    }
    delete photos;
}

const string& Album::getTitle() const {
    return title; 
}

bool Album::equals(const string& s) const {
    if(title == s) return true;

    return false;
}

bool Album::lessThan(const Album& alb) const {
    if(alb.title.compare(title) < 0) return true;

    return false;
}

bool Album::addPhoto(Photo* photo){
    if(photos->addPhoto(photo) == false) return false;
    return true; 
}

bool Album::addPhoto(const int index, Photo* photo){
    if(photos->addPhoto(index, photo) == false) return false;
    return true; 
}

Photo* Album::getPhoto(const string& curTitle) const{
    return photos->getPhoto(curTitle);
}

Photo* Album::getPhoto(const int index) const{
    return photos->getPhoto(index);
}

Photo* Album::removePhoto(const string& curTitle){
    return photos->remove(curTitle);
}

Photo* Album::removePhoto(const int index){
    return photos->remove(index);
}
void Album::print() const {
    cout<<"Album title: " << title << ", description: " << description << endl;
}
int Album::size() const {
    return photos->size();
}
void Album::display() const {
    print();
    cout << "Printing out all photos from current album:" << endl;
    for(int i = 0; i < photos->size(); i++){
        photos->getPhoto(i)->display();
    }
}




