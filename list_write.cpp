//Kadn Neal 1224794961
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "data_structures.h"
#include "list_write.h"
using namespace std;
 
void listInsert(LIST* list, double key) {
    NODE* newNode = new NODE{key, nullptr};

    if (list->head == nullptr || list->head->key >= key) {
        newNode->next = list->head;
        list->head = newNode;
        if (list->tail == nullptr) { 
            list->tail = newNode;
        }
    } 
    
    else {   
        NODE* current = list->head;
        while (current->next != nullptr && current->next->key < key) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (current == list->tail) { 
        }
    }
}

void listAppend(LIST* list, double key) {
    NODE* newNode = new NODE{key, nullptr};
    if (list->tail != nullptr) {
        list->tail->next = newNode;
        list->tail = newNode;
    } 
    
    else {
        list->head = list->tail = newNode;
    }
}

void listDelete(LIST* list, double key) {
    if (list->head == nullptr) {
        return; 
    }

    if (list->head->key == key) {
        NODE* temp = list->head;
        list->head = list->head->next;
        if (list->head == nullptr) { 
            list->tail = nullptr;
        }
        delete temp;
    } 
    else {
        NODE* current = list->head;
        while (current->next != nullptr && current->next->key != key) {
            current = current->next;
        }
        if (current->next != nullptr) { 
            NODE* temp = current->next;
            current->next = temp->next;

            if (temp == list->tail) { 
                list->tail = current;
            }
            
            delete temp;
        }
    }
}