#include <iostream>
#include <queue>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int value){
        data=value;
        left=right=NULL;

    }
};
int main(){
    int x,one,two;
    queue<Node*>q;
    cout<<"enter the root element";
    cin>>x;
    Node *root = new Node (x);
    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        cout<<"enter the  left child of "<<temp->data<<":";
        cin>>one;
        if(one!=-1){
            temp->left=new Node(one);
            q.push(temp->left);
        }
        cout<<"enter the right child of "<<temp->data<<":";
        cin>>two;
        if(two!=-1){
            temp->right=new Node(two);
            q.push(temp->right);
        }
    }
}