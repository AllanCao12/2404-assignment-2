using namespace std;

#include "AlbumArray.h"

AlbumArray::AlbumArray(){
    elements = new Album*[MAX_ARRAY];
    elementSize = 0;
}

AlbumArray::AlbumArray(const AlbumArray& albumArray){
    elements = new Album*[MAX_ARRAY];
    elementSize = albumArray.elementSize; 
    for(int i = 0; i < elementSize; i++){
        elements[i] = new Album(*albumArray.elements[i]);
    }
}

AlbumArray::~AlbumArray(){
    /*
    for(int i = 0; i < elementSize; i++){
        delete elements[i];
    }
    */
    delete [] elements;
    elementSize = 0;
}

bool AlbumArray::isFull() const {
	return elementSize>=MAX_ARRAY? true: false;
}
bool AlbumArray::add(Album* album){
    if(isFull()) return false; 

    int index = 0;
    while (index < elementSize){
        if(album->lessThan(*elements[index])){
            break;
        }
        ++index;
    }

    for (int i = elementSize; i > index; --i){
        elements[i] = elements[i-1];
    }
    elements[index] = album;
    ++elementSize;
    return true;
}

Album* AlbumArray::get(const string& title) const{
    for (int i = 0; i < elementSize; ++i){
        if (title == elements[i]->getTitle()){
            return elements[i];
        }
    }
    return NULL; //not found
}

Album* AlbumArray::get(const int index) const {
    if (index < 0 || index >= elementSize) return NULL;
    return elements[index];
}

Album* AlbumArray::remove(const string& title){
    int index = 0;
    Album* temp;
    //we want to find the index of the element to remove
    while (index < elementSize && title != elements[index]->getTitle()){
        ++index;
    }

    //did we fall off the end of the List?
    if (index == elementSize) return NULL;

    //we have found what we wanted to remove,
    //assign the output value
    temp = elements[index];

    //copy everything after index left one position
    while (index < elementSize - 1){
        elements[index] = elements[index + 1];
        ++index;
    }
    elements[index] = nullptr;
    --elementSize;
    return temp;
}

Album* AlbumArray::remove(const int index){
    Album* temp;
    int i = index;
    if (index < 0 || index >= elementSize) return NULL;
    temp = elements[index];

    //copy everything after index left one position
    while (i < elementSize-1){
        elements[i] = elements[i+1];
        ++i;
    }
    --elementSize;
    elements[i] = nullptr;
    return temp;
}

int AlbumArray::size() const {
    return elementSize; 
}