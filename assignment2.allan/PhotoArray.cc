#include <iostream>
using namespace std;

#include "PhotoArray.h"

PhotoArray::PhotoArray(){
    elements = new Photo*[MAX_ARRAY];
    elementSize = 0; 
}

/*
PhotoArray::PhotoArray(const PhotoArray& photoArray){
    elements = new Photo*[MAX_ARRAY];
    elementSize = photoArray.elementSize; 
    for(int i = 0; i < elementSize; i++){
        elements[i] = new Photo(*photoArray.elements[i]);
    }
}

*/
PhotoArray::~PhotoArray(){
    /*
    for(int i = 0; i < elementSize; i++){
        delete elements[i];
    }
   */ 
    delete [] elements;
    elementSize = 0;
}

bool PhotoArray::isFull() const {
    if(elementSize >= MAX_ARRAY){
        return true;
    }else{
        return false;
    }
}

bool PhotoArray::addPhoto(Photo* photo){
    if(isFull()) return false;

    elements[elementSize] = photo;
    elementSize++;
    return true; 
}

bool PhotoArray::addPhoto(const int index, Photo* photo){
    if(isFull() || index > elementSize || index < 0) return false; 

    for(int i = elementSize; i > index; i--){
        elements[i] = elements[i-1];
    }

    elements[index] = photo;
    elementSize++;
    return true;
}

Photo* PhotoArray::getPhoto(const string& title) const {
    for (int i = 0; i < elementSize; ++i){
        if (title == elements[i]->getTitle()){
            return elements[i];
        }
    }
    return NULL; //not found
}

Photo* PhotoArray::getPhoto(const int index) const {
    if (index < 0 || index >= elementSize) return NULL;
    return elements[index];
}

Photo* PhotoArray::remove(const string& title){
    int index = 0;
    Photo* temp;
    //we want to find the index of the element to remove
    while (title != elements[index]->getTitle() && index < elementSize){
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
    --elementSize;
    elements[index] = nullptr;
    return temp;
}

Photo* PhotoArray::remove(const int index){
    Photo* temp;
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

int PhotoArray::size() const {
    return elementSize; 
}