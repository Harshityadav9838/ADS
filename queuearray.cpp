#include <iostream>
using namespace std;

#define MAX 5

class queue{
    private:
    int arr[MAX];
    int front;
    int rear;
    public:
    queue(){
        front = -1;
        rear = -1;
    }
    void enqueue(int x){
        if(rear == MAX-1){
            cout << "Queue is full" << endl;
            return;
        }
        if(front == -1){
            front = 0;
        }
        rear++;
        arr[rear] = x;
        cout << x << " enqueued to queue" << endl;
    } 
    void dequeue(){
        if(front == -1 || front > rear){
            cout << "Queue is empty" << endl;
            return;
        }
        cout << arr[front] << " dequeued from queue" << endl;
        front++;
    }
    void peek(){
        if(front == -1 || front > rear){
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element is: " << arr[front] << endl;
    }
    void display(){
        if(front == -1 || front > rear){
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements are: ";
        for(int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void menu(){
        int choice;
        do{
            cout << "\nQueue Menu:\n";
            cout << "1. Enqueue\n";
            cout << "2. Dequeue\n";
            cout << "3. Peek\n";
            cout << "4. Display\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch(choice){
                case 1:
                    int x;
                    cout << "Enter element to enqueue: ";
                    cin >> x;
                    enqueue(x);
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    peek();
                    break;
                case 4:
                    display();
                    break;
                case 5:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        }while(choice != 5);
    }
};
int main(){
    queue q;
    
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.peek();
    q.dequeue();
    q.peek();
    q.display();
    q.menu();
    return 0;
}
