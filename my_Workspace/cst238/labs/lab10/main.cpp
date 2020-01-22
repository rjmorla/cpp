/**
This is base code for Lab 10 for CST238 Fall 2019
Sections 2 & 3
It does not need to be modified or turned in
*/
#include <iostream>
#include "LinkedList.h"
using namespace std;
int main() {
    LinkedList ll;
    ll.display();
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.display();
    cout << "Is 2 in the linked list? " << boolalpha << ll.search(2) << endl; 
    cout << "Is 3 in the linked list? " << boolalpha << ll.search(3) << endl; 
    cout << "Is 5 in the linked list? " << boolalpha << ll.search(5) << endl; 

}