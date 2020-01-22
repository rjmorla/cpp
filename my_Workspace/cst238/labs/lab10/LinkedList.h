/**
This is base code for Lab 10 for CST238 Fall 2019
Sections 2 & 3
It does not need to be modified or turned in
*/
#include<iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class Node {
public:
    Node();
    Node(int data);
    Node * getNext() const { return myNext; };
    bool hasNext() const;
    int getData () const { return myData; };
    void setNext(Node * next);
private:
    int myData;
    Node * myNext;
};

class LinkedList {
public:
    LinkedList();
    Node * getFirst() const { return myFirst; };
    bool empty() const;
    void append(int data);
    void display() const;
    bool search(int data) const;
private:
    Node * myFirst;
};


#endif