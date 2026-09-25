#include <iostream>
using namespace std;
class Queue 
{
    
    int *arr;
    int front,rear,size;
    public:
    Queue(int x) {
        front = rear = -1;
        size = x;
        arr = new int[x];
    }

 bool isEmpty(){
    return front == -1;
 }
 bool isFull(){
    return rear == size -1;
 }
 void push(int x) {
    if (isFull()) {
       front=rear=0;
       arr[0]=x;
    }
    else if(isFull()){
        cout <<"overflow"<<endl;
        return;
    }
      else {
        rear=rear+1;
        arr[rear] = x;
      }
 }
};
void display(Queue q) {
    if (q.isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    while (!q.isEmpty()) {
        cout << q.arr[q.front] << " ";
        q.front++;
    }
    cout << endl;
}
int main() {
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display(q);
   // q.push(60); // This will cause overflow
    return 0;
}