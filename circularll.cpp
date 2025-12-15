
#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
};

class CircularLinkedList {
public:
    CNode* tail;
    CircularLinkedList() { tail = nullptr; }

    // Insert at end
    void insertEnd(int val) {
        CNode* newNode = new CNode{val, nullptr};
        if(tail == nullptr) {
            tail = newNode;
            tail->next = tail; // circular
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    // Insert at beginning
    void insertBeginning(int val) {
        CNode* newNode = new CNode{val, nullptr};
        if(tail == nullptr) {
            tail = newNode;
            tail->next = tail;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
    }

    // Delete by value
    void deleteByValue(int val) {
        if(tail == nullptr) {
            cout << "List empty\n";
            return;
        }
        CNode* curr = tail->next;
        CNode* prev = tail;
        do {
            if(curr->data == val) {
                if(curr == tail) {
                    if(curr->next == curr) { // only one node
                        delete curr;
                        tail = nullptr;
                        return;
                    }
                    prev->next = curr->next;
                    tail = prev;
                    delete curr;
                    return;
                } else {
                    prev->next = curr->next;
                    if(curr == tail->next) tail->next = curr->next; // head
                    delete curr;
                    return;
                }
            }
            prev = curr;
            curr = curr->next;
        } while(curr != tail->next);
        cout << "Value not found\n";
    }

    // Search
    bool search(int val) {
        if(tail == nullptr) return false;
        CNode* curr = tail->next;
        do {
            if(curr->data == val) return true;
            curr = curr->next;
        } while(curr != tail->next);
        return false;
    }

    // Display
    void display() {
        if(tail == nullptr) return;
        CNode* curr = tail->next;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while(curr != tail->next);
        cout << endl;
    }
};
