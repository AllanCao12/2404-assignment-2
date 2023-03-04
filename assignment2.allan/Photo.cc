#include "Photo.h"

Photo::Photo(const string& title, const Date& date, const string& content){
    this->title = title;
    this->date.setDate(date.getYear(), date.getMonth(), date.getDay());
    //this->date.setDate(date);
    this->content = content; 
}

Photo::Photo(){
    this->title = "Photograph";
    this->date.setDate(2023, 2, 11);
    this->content = "Photograph content";
}

Photo::~Photo(){
    
}
Photo::Photo(const Photo &oldPhoto){
    this->title = oldPhoto.title;
    this->date.setDate(oldPhoto.date);
    this->content = oldPhoto.content;
}

bool Photo::equals(const string& title) const {
    if(this->title == title){
        return true;
    }else{
        return false; 
    }
}

void Photo::print() const {
    cout << "The date is:" << date.getMonthName() << " " << date.getDay() << " ," << date.getYear() << endl;
    cout << "The title of the photo is: " << title << endl;
}

const string& Photo::getTitle() const {
    return title; 
}
void Photo::display() const {
    print();
    cout << content << endl;
}
