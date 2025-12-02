#include<iostream>
using namespace std;

class cqueue {
public:
    int size;
    int front;
    int rear;
    int *arr;

    cqueue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int v) {
        if (isFull()){
        	cout<<"queue full"<<endl;
        	return;
		}
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = v;
    }

    int dequeue() {
        if (isEmpty()){
        	cout<<"queue empty"<<endl;
        	return -1;
		} 
        int val = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return val;
    }

    void display() {
        if (isEmpty()) return;
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
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
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(50);
    q.enqueue(60);
    
    q.dequeue();
    q.enqueue(70);
    q.display();
    q.enqueue(80);
    return 0;
}
