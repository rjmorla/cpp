//--- Definition of class constructor
/*
 * Title: List.cpp
 * Author: Roy Morla
 * ID: 1534 
 * Date: 10/30/2019
 */
#include <iostream>
#include "List.h"
using namespace std;

List::List()     
: mySize(0), myCapacity(50) {
    myArray = new int[myCapacity];
}

List::List(int capacityValue)     
: mySize(0), myCapacity(capacityValue) {
    myArray = new int[myCapacity];
}

List & List::operator=(const List & rightSide) {
    // Check for self-assignment; do nothing if self-assignment
    if (this != &rightSide) {
        if (myCapacity != rightSide.myCapacity) {
            delete [ ] myArray;
            myArray = new int[rightSide.myCapacity];
        }
        myCapacity = rightSide.myCapacity;
        mySize = rightSide.mySize;
        for (int i = 0; i < mySize; i++) { // deep copy
            myArray[i] = rightSide.myArray[i];  
        }  
    }
    return *this;
}

List::List(const List& orig)
  :myCapacity(orig.myCapacity), mySize(orig.mySize) {
    myArray = new int[myCapacity];
    for (int i =0; i < mySize; i++)
        myArray[i] = orig.myArray[i];
}

List::~List() {
    delete [] myArray;
}

//--- Definition of empty()
bool List::empty() const {
    return mySize == 0;
}

//--- Definition of display()
void List::display() const {
    for (int i = 0; i < mySize; i++) {
        cout << myArray[i] << "  ";
    }
    cout << endl;
}


//--- Definition of insert()
void List::insert(int item, int pos) {
    if (mySize == myCapacity) {
        int* temp = new int[myCapacity];
        for (int i = 0; i < mySize; i++) {
            temp[i] = myArray[i];
        }
        myCapacity = pos;
        myArray = new int[myCapacity];
        for (int i = 0; i < mySize; i++) {
            myArray[i] = temp[i]; 
        }
        delete [] temp;


        if (pos < 0 || pos > mySize) {
            cerr << "*** Illegal location to insert -- " << pos 
                << ".  List unchanged. ***\n";
            return;
        }
        myArray[pos - 1] = item;
        mySize++;
    }

    if (pos < 0 || pos > mySize) {
        cerr << "*** Illegal location to insert -- " << pos 
            << ".  List unchanged. ***\n";
        return;
        }

    // First shift array elements right to make room for item
    for(int i = mySize; i > pos; i--) {
        myArray[i] = myArray[i - 1];
    }

    // Now insert item at position pos and increase list size  
    myArray[pos] = item;
    mySize++;
}


//--- Definition of erase()
void List::erase(int pos) {
    if (mySize == 0) {
        cerr << "*** List is empty ***\n";
        return;
    }
    if (pos < 0 || pos >= mySize) {
        cerr << "Illegal location to delete -- " << pos
            << ".  List unchanged. ***\n";
        return;
    }

    // Shift array elements left to close the gap
    for(int i = pos; i < mySize; i++) {
        myArray[i] = myArray[i + 1];
    }

    // Decrease list size
    mySize--;
}

void List::setCapacity(int num) {
    myCapacity = num;
}

void List::append(int num) {
    
    if (mySize == myCapacity) {
        int* temp = new int[myCapacity];
        for (int i = 0; i < mySize; i++) {
            temp[i] = myArray[i];
        }
        myCapacity++;
        myArray = new int[myCapacity];
        for (int i = 0; i < mySize; i++) {
            myArray[i] = temp[i]; 
        }
        delete [] temp;

        myArray[mySize] = num;
        mySize++;
    }
    else {
        myArray[mySize] = num;
        mySize++;
    }
}

bool List::removeLast() {
    if ( empty() ) {
        return false;
    }
    mySize--;
    return true;
}

