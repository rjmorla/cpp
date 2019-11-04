/*
 * Title: Student.cpp
 * Author: Roy Morla
 * ID: 1534 
 * Date: 11/3/2019
 */
#include <iostream>
#include "Student.h"

using namespace std;

Student::Student() : myID(0), myName("UNKNOWN") {}

void Student::setName(string name) {
    myName = name;
}

void Student::setID(int id) {
    myID = id;
}

Student & Student::operator=(const Student& rightSide) {
    // Check for self-assignment; do nothing if self-assignment
    if (this != &rightSide) {
        
        myID = rightSide.myID;
        myName = rightSide.myName;
  
    }
    return *this;
}