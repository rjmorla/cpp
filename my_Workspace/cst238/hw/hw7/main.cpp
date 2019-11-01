/*
 * Title: main.cpp
 * Author: Roy Morla
 * ID: 1534 
 * Date: 10/30/2019
 */
#include <iostream>
#include "List.h"
using namespace std;

int main() {
    List orgList;
    
    for (int i = 0; i < 9; i++) {
        orgList.insert(i, i);
    }
    cout << "========== Original orgList ==========\n   ";
    orgList.display();
    
    List copyList(orgList);  // Copy constructor
    copyList.insert(400, 0);
    copyList.insert(500, 1);
    
    cout << "\nCopy Constructor Test:\n";
    cout << "========== orgList ==========\n   ";
    orgList.display();
    
    cout << "========== copyList ==========\n   ";
    copyList.display(); 
    
    // Assignment operation
    copyList = orgList;
    orgList.insert(77, 2);
    orgList.insert(88, 5);
    
    cout << "\nAssignment Operator Test:\n";
    cout << "========== orgList ==========\n   ";
    orgList.display();
    
    cout << "========== copyList ==========\n   ";
    copyList.display(); 
    
    return 0;
}
