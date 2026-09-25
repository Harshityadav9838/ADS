#include <iostream>
using namespace std;
class CircularQueue
{
    int *arr;
    int front, rear, size;
    public:
    CircularQueue(int x) {
        front = rear = -1;
        size = x;
        arr = new int[x];
    }
   bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return (rear + 1) % size == front;
    }
    void push(int x) {
        if (isFull()) {
            cout << "Overflow" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
            arr[rear] = x;
        } else {
            rear = (rear + 1) % size;
            arr[rear] = x;
        }
    }