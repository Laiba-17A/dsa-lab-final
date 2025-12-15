#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() { head = nullptr; }

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node{val, nullptr, head};
        if(head != nullptr) head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node{val, nullptr, nullptr};
        if(head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Insert at position (1-based index)
    void insertAtPosition(int val, int pos) {
        if(pos == 1) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        for(int i = 1; i < pos-1 && temp != nullptr; i++) temp = temp->next;
        if(temp == nullptr) {
            cout << "Position out of bounds\n";
            return;
        }
        Node* newNode = new Node{val, temp, temp->next};
        if(temp->next != nullptr) temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Delete by value
    void deleteByValue(int val) {
        Node* temp = head;
        while(temp != nullptr && temp->data != val) temp = temp->next;
        if(temp == nullptr) {
            cout << "Value not found\n";
            return;
        }
        if(temp->prev != nullptr) temp->prev->next = temp->next;
        else head = temp->next;
        if(temp->next != nullptr) temp->next->prev = temp->prev;
        delete temp;
    }

    // Search
    bool search(int val) {
        Node* temp = head;
        while(temp != nullptr) {
            if(temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    // Display forward
    void displayForward() {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display backward
    void displayBackward() {
        Node* temp = head;
        if(temp == nullptr) return;
        while(temp->next != nullptr) temp = temp->next;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};
