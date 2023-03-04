using namespace std;
#include "Client.h"

Client::Client(){
    albums = new AlbumArray();
}

Client::~Client(){
    Album* temp;
    while(albums->size() > 0){
        temp = albums->remove(0);
        delete temp; 
    }
    delete albums; 
}

bool Client::downloadAlbum(PhotoGram* pg, const string& albumTitle){
    Album* temp = pg->downloadAlbum(albumTitle);

    if(!temp){
        return false; //cout already in download album
    }

    Album* newAlbum = new Album(*temp); // deep copy

    if(!albums->add(newAlbum)){
        cout << "AlbumArray is full" << endl; 
        delete newAlbum;
        return false;
    }
    return true; // added sucessfully 
}

bool Client::displayOnlinePhoto(PhotoGram* pg, const string& albumTitle, const string& photoTitle) const {
	
    Photo* temp = pg->downloadPhoto(albumTitle, photoTitle);
    if(!temp){
        return false; //cout in downloadPhoto
    }

    temp->display();
    return true; 
}

bool Client::displayLocalPhoto(const string& albumTitle, const string& photoTitle) const {
    Album* temp = albums->get(albumTitle);
    if(!temp){
        cout << "Album not found" << endl; 
        return false; 
    }

    Photo* tempPhoto = temp->getPhoto(photoTitle); 
    if(!tempPhoto){
        cout << "Photo not found" << endl;
        return false;
    }

    //We found the photo in the given album

    tempPhoto->display();
    return true;
}

void Client::printLocalAlbums() const {
    for(int i = 0; i < albums->size(); i++){
        albums->get(i)->print();
    }
}

void Client::displayLocalAlbums() const {
    for(int i = 0; i < albums->size(); i++){
        albums->get(i)->display();
    }
}
