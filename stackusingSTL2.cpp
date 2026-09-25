#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    int choice,value;
     
    do {
        cout<<"\n1. push";
        cout<<"\n2. pop";
        cout<<"\n3. peek(top)";
        cout<<"\n4. display";
        cout<<"\n5. size";
        cout<<"\n6. exit";
        cout<<"enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"enter value to push: ";
                cin>>value;
                s.push(value);
                cout<<" element inserted successfully:"<<endl;
                break;
            case 2:
                if(s.empty()) {
                    cout<<"stack underflow"<<endl;
                } else {
                    cout<<"deleted element"<<s.top()<<endl;
                    s.pop();
                }
                break;
            case 3:
                if(s.empty()) {
                    cout<<"stack is empty" ;
                } else {
                    cout<<"top element:"<<s.top()<<endl;
                }
                break;
            case 4:
                if(s.empty()) {
                    cout<<"stack is empty ";
                }
                else{
                    stack<int>temp=s;
                    cout<<"stack element (top to bottom):"<<endl;
                    while(!temp.empty()){
                        cout<<temp.top()<<" "<<endl;
                        temp.pop();
                    }
                }
                break;
            case 5:
                cout<<"size of stack: " << s.size() << endl;
                break;
            case 6:
                cout<<"program terminated"<<endl;
                break;
            default:
                cout<<"invalid choice."<<endl;
        }
    } while(choice != 6);
    return 0;
}