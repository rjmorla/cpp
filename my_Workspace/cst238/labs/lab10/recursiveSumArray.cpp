/*
 * Title: recursiveSumArray.cpp
 * Abstract: This program uses recursion to show the calculation and result of an array having all it values
 * summed up and uses a vector for the built in empty() function to test if no data is inputted.
 * Author: Roy Morla
 * ID: 1534 
 * Date: 11/11/2019
 */
#include <iostream>
#include <vector>
using namespace std;

int sumArray(vector<int> arr, int size);
int main() {
  vector<int> base;
  base.push_back(3);
  base.push_back(4);
  base.push_back(5);
  cout << sumArray(base, base.size()) << endl;
}

int sumArray(vector<int> arr, int size) {
    if (arr.empty()) {
        return 0;
    }
    if(size > 0) {
        if (size > 1) {
            cout << arr[size-1] << " + ";
            return arr[size-1] + sumArray(arr, size-1);
        }
        else {
            cout << arr[size-1];
            return arr[size-1] + sumArray(arr, size-1);
        }
    } else {
        cout << " = ";
        return 0;
    }
}