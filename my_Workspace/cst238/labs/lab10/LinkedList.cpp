/*
 * Title: LinkedList.cpp
 * Abstract: This is the implementation of functions required for basic Linked list usage.
 * Author: Roy Morla
 * ID: 1534 
 * Date: 11/11/2019
 */
#include <iostream>
#include "LinkedList.h"
using namespace std;
/**
* Implement these functions IN ORDER
*/

bool LinkedList::empty() const {
    return (myFirst == nullptr);
}

bool Node::hasNext() const {
    return (myNext != nullptr);
}

void LinkedList::append(int data) {
    if (empty()) {
        myFirst = new Node(data);
    } 
    else {
        Node * np = getFirst();
        while (np -> hasNext()) {
            np = np -> getNext();
        }
        np -> setNext(new Node(data));
    }
}

void LinkedList::display() const {
    if (empty()) {
        cout << "Empty!" << endl;
    } 
    else {
        Node * np = getFirst();
        cout << np->getData() << " ";
        while (np -> hasNext()) {
            np = np -> getNext();
            cout << np->getData() << " ";
        }
        cout << endl;
    }
}

bool LinkedList::search(int data) const {
    if (empty()) {
        return false;
    } 
    else {
        Node * np = getFirst();
        if (np->getData() == data) {
            return true;
        }
        
        while (np -> hasNext()) {
            np = np -> getNext();
            if (np->getData() == data) {
                return true;
            }
        }
    }
    return false;
}
/**
* Implement the functions above, shouldn't need to change anything below,
but look at this for good examples!
*/

Node::Node(int data) {
    myData = data;
}

void Node::setNext(Node * next) {
    myNext = next;
}

LinkedList::LinkedList() {
    myFirst = nullptr; 
}