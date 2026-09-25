#include <iostream>
using namespace std;
class Node{
    
    public:
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
class Queue{
    Node* front;
    Node* rear;
    public:
    Queue(){
        front=rear=NULL;
    }
   
    void push(int x){
        if(isEmpty()){
            front=rear=new Node(x);
        }
        else{
            rear->next=new Node(x);
            rear=rear->next;
        
        }
       
    }
    bool isEmpty(){
        return front==NULL;
    }

};
void display(Queue q) {
    if (q.isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    
};
int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    display(q);
   
    return 0;
}