#include <iostream>
using namespace std;

int main () {
    int size = 5;
    int a[size] = {1, 3, 2, 4, 5};
    int rev_a[size];
    int count = 0;
    for (int i = size - 1; i >= 0; i--) {
        rev_a[count] = a[i];
        count++;
        
    }
    
    for (int i = 0; i < size; i++) {
        cout << "a: " << a[i] << " b: " << rev_a[i] << endl;
    }
}