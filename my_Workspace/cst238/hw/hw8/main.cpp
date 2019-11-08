/*
 * Title: main.cpp
 * Abstract: This program uses insertion sort to sort numbers from a file in a dynamic array and will print the numbers
 * in folded number format.
 * Author: Roy Morla
 * ID: 1534 
 * Date: 11/6/2019
 */
#include <iostream>
#include <fstream>

using namespace std;

void sort(int * a, int size);

void printFolded(int * a, int size);

int main () {

    string filename;
    cin >> filename;
    ifstream inputFile(filename);
    int size;
    inputFile >> size;

    int * a = new int[size];

    for (int i = 0; i < size; i++) {
        inputFile >> a[i];
    }

    sort(a, size);

    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    printFolded(a, size);

    return 0;
}

void sort(int * a, int size) {
    int * temp;
    for (int i = 0; i < size; i++) {
        for (int j = i; j > 0; j--) {
            if (j == 0) {
                continue;
            }
            else if (a[j-1] > a[j]) {
                temp = new int(a[j]);
                a[j] = a[j-1];
                a[j-1] = *temp;
                delete temp;
            }
        }
    }
}

void printFolded(int * a, int size) {
    for (int i = 0; i < size; i++) {

        int j, count = i;
        if (a[i] == a[i+1] - 1) {
            for (j = i+1; j <= size; j++) {
                if (a[count] == a[j] - 1) {
                    count++;
                    continue;
                }
                else {
                    cout << a[i] <<  "-" << a[count] << " ";
                    break;
                }
            }
            i = count;
        }
        else {
            cout << a[i] << " ";
        }
    }
}