//Kadn Neal 1224794961
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits>
#include "data_structures.h" 
#include "list_read.h"
using namespace std;

double listMax(LIST* list) {
    if (list == nullptr || list->head == nullptr) {
        cerr << "List is empty or null." << endl;
        return numeric_limits<double>::quiet_NaN(); 
    }

    double max = numeric_limits<double>::lowest(); 
    NODE* current = list->head;
    
    while (current != nullptr) {
        if (current->key > max) {
            max = current->key;
        }
        current = current->next;
    }

    return max;
}

void listPrint(LIST* list) {
    if (list == nullptr || list->head == nullptr) {
        cerr << "List is empty or null." << endl;
        return;
    }

    NODE* current = list->head;

    while (current != nullptr) {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}