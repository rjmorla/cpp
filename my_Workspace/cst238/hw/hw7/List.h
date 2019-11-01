/*
 * Title: List.h
 * Abstract: This program uses a dynamic array and has the big 3 defined and uses a list data structure to contain
 * data. The program is also split into their appropriate files.
 * Author: Roy Morla
 * ID: 1534 
 * Date: 10/30/2019
 */

#ifndef LIST_H
#define LIST_H

using namespace std;

class List {
public:
    List();    // Constructor. Default 50
    List(int capacityValue);
    ~List( );              // Destructor
    List(const List& org); // Copy constructor
    List& operator =(const List& rightSide);  // Assignment operator
    bool empty() const; 
    void insert(int item, int pos);
    void erase(int pos);  
    void display() const; 
    
    //task3
    int getCapacity() const {return myCapacity; }
    int getSize() const { return mySize; }

    void append(int num);
    bool removeLast();
    void setCapacity(int num);

private:
   int mySize;     // current size of list
   int myCapacity; // capacity of array
   int * myArray;  // pointer to dynamic array
}; 

#endif LIST_H