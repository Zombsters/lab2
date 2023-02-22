#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    string data = "";
    Node* next; Node* prev;
    int count = 0;
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList();
    ~LinkedList();
    bool IsEmpty();
    int GetSize();
    void AddAtHead(string value);
    void AddAtPosition(string value, int position);
    void DeleteValue(string value);
    void Print(ostream &out);
    void Search(string data);

    void InsertionSort();
    void swap(Node* left, Node* right);
};

LinkedList::LinkedList() {
    //cout << "constructor called" << endl;
    head = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    //cout << "destructor called" << endl;
    Node* current = head;
    while(current != nullptr){
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

bool LinkedList::IsEmpty() {
    return head == nullptr;
}

int LinkedList::GetSize() {
    return size;
}

void LinkedList::AddAtHead(string value) {
    Node* temp = new Node();
    temp->data = value;
    temp->count = 1;
    temp->next = nullptr;
    temp->prev = nullptr;
    
    if (head == nullptr) {
        head = temp;
    }
    else {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    size++;
}

void LinkedList::AddAtPosition(string value, int position) {
    Node* temp = new Node();
    temp->data = value;
    temp->count = 1;
    temp->next = nullptr;

    if(head == nullptr) {
        head = temp;
    }
    else if(position <= 0) {
        temp->next = head;
        head = temp;
    }
    else {
        Node* previous = head;
        int count = 1;
        while(count < position && previous->next != nullptr) {
            previous = previous->next;
            count++;
        }
        temp->next = previous->next;
        previous->next = temp;
    }
  size++;
}

void LinkedList::DeleteValue(string value){
    if(head == nullptr){
        cout << "Empty List!" << endl;
    }
    else if(head->data == value){
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Target Eliminated!" << endl;
    }
    else {
        Node* previous = head;
        Node* current = head->next;
        while(current != nullptr) {
            if(current->data == value){
                previous->next = current->next;
                cout << "Found it!" << endl;
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    
        cout << "Didn't find it!" << endl;
    }
}

void LinkedList::Print(ostream &out) {
    Node* current = head;
    while(current != nullptr) {
        out << current-> count << " " << current->data << endl;
        current = current->next;
    }
}

void LinkedList::Search(string data) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            current->count++;
            cout << "found " << data << " adding to count... count now: " << current->count << endl;
            return;
        }
        else {
            current = current->next;
        }
        
    }
    cout << "Unable to find " << data << " in linked list." << endl;
    cout << "adding " << data << " to head of linked list... " << endl;
    AddAtHead(data);
}


void LinkedList::InsertionSort() {
    //sort linked list...

    for (Node* j = head; j != NULL; j = j->next) { //for the size of the ll...
        for (Node* i = j; i != NULL; i = i->prev) {
            if (i->prev == NULL || i->next == NULL) {
                break;
            }
            
            if ((i->count) > (i->next->count)) { //if swapped-> keep going down the ll
                Node* next = i->next;
                swap(i, next);
            }
            else {
                break; //breaks out of most inner most loop
            }
            
        }
    }
}

void LinkedList::swap(Node* left, Node* right) {
    
    if (left->prev) {
        left->prev->next = right;
    }
    if (right->next) {
        right->next->prev = left;
    }

    left->next = right->next;
    right->prev = left->prev;

    right->next = left;
    left->prev = right;

}