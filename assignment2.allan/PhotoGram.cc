using namespace std;
#include "PhotoGram.h"

PhotoGram::PhotoGram(){
    albums = new AlbumArray();
}

PhotoGram::~PhotoGram(){
    Album* temp;
    while(albums->size() > 0){
        temp = albums->remove(0);
        delete temp; 
    }
    delete albums;
}

bool PhotoGram::addAlbum(const string& albumTitle, const string& description){
    if(albums->isFull()){
        cout<<"Album is full!"<< endl;
        return false; 
    }
    //not full
    albums->add(new Album(albumTitle, description));
    return true;
}

bool PhotoGram::removeAlbum(const string& albumTitle){
    Album* temp = albums->remove(albumTitle);
    if(temp == NULL){
        cout << "Album with title not found" << endl;
        return false; 
    }

    // Album was found

    delete temp; 
    return true; 
}

bool PhotoGram::addPhoto(const string& albumTitle, const Photo& photo){
    Album* temp = albums->get(albumTitle);
    if(temp == NULL){
        cout << "Album not found" << endl; 
        return false; 
    }

    // Album was found

    if(temp->addPhoto(new Photo(photo))) return true;

    return false; 
}

bool PhotoGram::removePhoto(const string& albumTitle, const string& photoTitle){
    Album* temp = albums->get(albumTitle);
    if(temp == NULL){
        cout << "Album not found" << endl; 
        return false; 
    }

    Photo* tempPhoto = temp->removePhoto(photoTitle); 
    if(!tempPhoto){
        cout << "Photo not found" << endl;
        return false;
    }

    delete tempPhoto; 
    return true; 
}

Album* PhotoGram::downloadAlbum(const string& albumTitle){
    Album* temp = albums->get(albumTitle);
    if(temp == NULL){
        cout << "Album not found" << endl; 
        return NULL; 
    }

    return temp; 
}

Photo* PhotoGram::downloadPhoto(const string& albumTitle, const string& photoTitle){
    Album* temp = albums->get(albumTitle);
    if(temp == NULL){
        cout << "Album not found" << endl; 
        return NULL; 
    }

    Photo* tempPhoto = temp->getPhoto(photoTitle); 
    if(!tempPhoto){
        cout << "Photo not found" << endl;
        return NULL;
    }

    return tempPhoto;
}

void PhotoGram::printAlbums(){
    for(int i = 0; i < albums->size(); i++){
        albums->get(i)->print();
    }
}

void PhotoGram::displayAlbums(){
    for(int i = 0; i < albums->size(); i++){
        albums->get(i)->display();
    }
}
