/*
 * Title: recursivePow.cpp
 * Abstract: This program uses recursion to calculate a user specified base and power and prints out
 * a statement displaying the result.
 * Author: Roy Morla
 * ID: 1534 
 * Date: 11/11/2019
 */
#include <iostream>
using namespace std;

int getpower (int num, int pow) {

    if (pow != 0) {
        return (num*getpower(num, pow-1));
    }
    else { 
        return 1;        
    }
}

int main() {
    int x, n;

    cout << "Input x: ";
    cin >> x;
    cout << "Input n: ";
    cin >> n;
    cout << x << " to the power of " << n << " is " <<getpower(x,n)<< endl;
}