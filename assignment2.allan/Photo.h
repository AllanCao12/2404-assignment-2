#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"
using namespace std;

class Photo {
		
	public:
		//constructor
        Photo();
		Photo(const string& title, const Date& date,  const string& content);
        Photo(const Photo &oldPhoto);
		~Photo();
		//setters
		//getters
		const string& getTitle() const;
		
		//other
        void print() const;
        void display() const;


		bool equals(const string& title) const;
	private:
		//functions
		//variables
        string title;
        string content;
        Date date; 
};
#endif
