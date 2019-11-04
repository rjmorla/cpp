/*
 * Title: Student.h
 * Abstract: This program defines a class students and takes in a user specified file with student data including
 * ID and name and then uses insertion sort to sort the data in ascending order. It also uses dynamic array to store 
 * the Students in a Students object array.
 * Author: Roy Morla
 * ID: 1534 
 * Date: 10/30/2019
 */
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class Student {
    public:
        Student( );
        string getName() const {return myName;}
        int getID() const {return myID;}
        void setName(string name);
        void setID(int id);
        Student& operator =(const Student& rightSide);

    private:
        string myName;
        int myID;
};

#endif 