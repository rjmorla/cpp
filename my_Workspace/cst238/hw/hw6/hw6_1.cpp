/*
 * Title: hw6_1.cpp
 * Abstract: This program reads data from a user-specifed file and determines whether or not a list is
 * a palindrome and if not it will create one. Uses dynamic arrays to handle data.
 * Author: Roy Morla
 * ID: 1534 
 * Date: 10/23/2019
 */
#include <iostream>
#include <fstream>
using namespace std;

void printArray(int * a, int size);
bool isPalindrome(int * a, int size);
int* makePalindrome(int * a, int & size);

int main () {
    string file_name;
    cout << "Enter input file name: ";
    cin >> file_name;
    ifstream inputFile(file_name);
    
    if (inputFile.fail()) {
        cout << "Error input file open failed";
        return 0;
    }
    int root, curr_line = 0;
    int * a;

    while (!inputFile.eof()) {
        inputFile >> root;
        a = new int[root];
        curr_line++;

        for (int i = 0; i < root; i++) {
            inputFile >> a[i];
        }

        if (isPalindrome(a ,root)) {
            cout << "Line " << curr_line << " is a palindrome of " << root << " numbers: ";
            printArray(a, root);
            cout << "Freeing up the array!" << endl << endl;
            delete [] a;
        }
        else {
            cout << "Line " << curr_line << " is NOT a palindrome" << endl;
            cout << "Line " << curr_line << " made into a palindrome: " << endl;
            cout << "Freeing up the old array!" << endl;
            int *x = makePalindrome(a, root);
            printArray(x, root);
            cout << "Freeing up the array!" << endl << endl;
            delete [] x;
        }


    }
    return 0;
}

void printArray(int * a, int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool isPalindrome(int * a, int size) {
    int rev_a[size];
    int count = 0;
    for (int i = size - 1; i >= 0; i--) {
        rev_a[count] = a[i];
    }
    
    for (int i = 0; i < size; i++) {
        if (a[i] != rev_a[i]) {
            return false;
        }
    }
    return true;
}

int* makePalindrome(int * a, int & size) {
    int oldSize = size;
    size *= 2;
    int count;

    int * x = new int[size];
    if (oldSize % 2 == 0) {
        count = size+1;
    }
    else {
        count = size+2;
    }
    
    for (int i = 0; i < size/2; i++) {
        x[i] = a[i];
    }

    
    for (int i = size/2; i < size; i++) {
            x[i] = a[count];
            count--;
    }
    delete [] a;
    return x;
}
