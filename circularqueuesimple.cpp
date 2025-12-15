#include <iostream>
using namespace std;

class cqueue {
public:
    int size;
    int front;
    int rear;
    int currs;   // current number of elements
    int *arr;

    cqueue(int s) {
        size = s;
        arr = new int[size];
        front = 0;    // front initialized to 0
        rear = -1;    // rear starts before first element
        currs = 0;    // initially queue is empty
    }

    bool isFull() {
        return currs == size;
    }

    bool isEmpty() {
        return currs == 0;
    }

    void enqueue(int v) {
        if (isFull()) {
            cout << "queue full" << endl;
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = v;
        currs++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "queue empty" << endl;
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % size;
        currs--;
        return val;
    }

    void display() {
        if (isEmpty()) return;
        int i = front;
        for (int count = 0; count < currs; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    cqueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();      // 10 20 30 40
    q.dequeue();
    q.display();      // 20 30 40
    q.enqueue(50);
    q.enqueue(60);    // queue full message if exceeds

    q.dequeue();
    q.enqueue(70);
    q.display();      // 30 40 50 70
    q.enqueue(80);    // queue full message
    return 0;
}
