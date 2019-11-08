/*
 * Title: mysort.cpp
 * Abstract: Implementations of bubblesort, insertion sort, and selection sort that tracks speed, swaps, and comparisons.
 * Author: Roy Morla
 * ID: 1534 
 * Date: 11/6/2019
 */
#include <time.h>
#include <iostream>
#include "mysorts.h"
using namespace std;

bool isSorted(int * values, int size) {
    for (int i = 0; i < size-1; i++) {
      if (values[i] > values[i+1]) {
        return false;
      }
    }
    return true;
}

int * copyArray(int * source, int size) {

    int * copy = new int[size];

    for (int i = 0; i < size; i++) {
      copy[i] = source[i];
    }
    return copy;
}
void bubble_sort (int * values, int size) {
    int comps = 0;
    int swaps = 0;
    clock_t startClock;
    clock_t elapsedTime;
    
    cout << "Start the bubble sorting..." << endl;
    // Measure the starting clock and conduct the bubble sorting
    startClock = clock();
    // sorting code goes here

  
      for (int i = 0; i < size - 1; i++) {     
        
        for (int j = 0; j < size - i - 1; j++){  
            comps++;
            if (values[j] > values[j+1])   {
                int * temp = new int(values[j]);  
                values[j] = values[j+1];  
                values[j+1] = * temp;
                swaps++;
                delete temp; 
            }
        }
    }    

    elapsedTime = clock() - startClock;
    cout << "Bubble sort completed. Is sorted: " << boolalpha <<
        isSorted(values, size) << endl;
    cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) 
        << " seconds" << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Comps: " << comps << endl << endl;

    // cout << "sorted list: ";
    // for (int i = 0; i < size; i++) {
    //   cout << values[i] << " ";
    // }
    // cout << endl;
}
void insertion_sort (int * values, int size) {
    int comps = 0;
    int swaps = 0;
    clock_t startClock;
    clock_t elapsedTime;
    
    cout << "Start the insertion sorting..." << endl;
    // Measure the starting clock and conduct the insertion sorting
    startClock = clock();
    // sorting code goes here
    int j;
    for (int i = 1; i < size; i++) {
        for (j = i; j > 0 && values[j - 1] > values[j]; j--) {
            int *temp = new int(values[j]);
            values[j] = values[j - 1];
            values[j - 1] = *temp;
            delete temp;
            swaps++;
        }
    }
    comps = swaps + j; 

    elapsedTime = clock() - startClock;
    cout << "Insertion sort completed. Is sorted: " << boolalpha <<
        isSorted(values, size) << endl;
    cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) 
        << " seconds" << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Comps: " << comps << endl << endl;

    cout << "sorted list: ";
}
void selection_sort (int * values, int size) {
    int comps = 0;
    int swaps = 0;
    clock_t startClock;
    clock_t elapsedTime;
    
    cout << "Start the selection sorting..." << endl;
    // Measure the starting clock and conduct the bubble sorting
    startClock = clock();
    // sorting code goes here

    int min; 
    bool found = false; 
   
    for (int i = 0; i < size-1; i++)  {  

        min = i;  
        for (int j = i + 1; j < size; j++) { 
          comps++;
          if (values[j] < values[min]) {  
              min = j;  
              found = true;
          } 
        }
        if (found == true) {
          int * temp = new int(values[min]);
          values[min] = values[i];  
          values[i] = * temp;
          swaps++;
          delete temp;
          found = false;
        }
    }  
    elapsedTime = clock() - startClock;
    cout << "Selection sort completed. Is sorted: " << boolalpha <<
        isSorted(values, size) << endl;
    cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) 
        << " seconds" << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Comps: " << comps << endl << endl;
}