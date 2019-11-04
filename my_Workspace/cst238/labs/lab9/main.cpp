/*
 * Title: main.cpp
 * Author: Roy Morla
 * ID: 1534 
 * Date: 11/3/2019
 */

#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;

Student* readStudents(string filename, int & size) {
    ifstream inputFile(filename);

    int newsize, id;
    string name;
    inputFile >> size;

    Student* arr = new Student[size];

    for (int i = 0; i < size; i++) {
        inputFile >> name;
        arr[i].setName(name);
        inputFile >> id;
        arr[i].setID(id);
    }
    return arr;
}

void printStudents(Student* sa, int size){
    cout << "Student roster: " << endl;
    for (int i = 0; i < size; i++) {
        cout << i+1 << ". " << sa[i].getName() << " " << sa[i].getID() << endl;
    }
}

bool isSorted(Student*sa, int size) {
  for (int i = 0; i < size; i++) {
    if(i+1 == size) {
      return true;
    }
    if (sa[i].getID() < sa[i+1].getID()){
      continue;
    }
    else {
      return false;
    }
  }
  return true;
}

void sort (Student* sa, int size) {
    int swaps = 0, comparisons = 0;
    Student * temp;

    for (int i = 0; i < size; i++) {
        for (int j = i; j > 0; j--) {
            if (isSorted(sa, size)) {
              break;
            }
            if (j == 0) {
                continue;
            }
            else if (sa[j-1].getID() > sa[j].getID()) {
                swaps++;
                comparisons++;
                temp = new Student(sa[j]);
                sa[j] = sa[j-1];
                sa[j-1] = *temp;
                delete temp;
            }
            else {
                comparisons++;
            }
        }
    }
    cout << "Comparisons: " << comparisons << " Swaps: " << swaps << endl;
}

int main () {
    int size = 0;
    string file_name;
    cout << "Enter input file name: ";
    cin >> file_name;

    Student* x = readStudents(file_name, size);
    sort(x, size);
    printStudents(x, size);

    delete [] x;
    return 0;
}