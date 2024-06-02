#include<iostream>
using namespace std;
struct Node
{
    int data ; 
    Node *next;
};
Node*top=NULL;

void push(int value);
int pop();
int getTop();
void display();

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    display(); // 40 30 20 10
    pop();
    display(); // 30 20 10
    cout << "Get Top : " <<getTop()<<endl;
}
void push(int value){
    Node* newNode=new Node();
    newNode->data=value;
    newNode->next=top;
    top=newNode;
}
int pop(){
    int value;
    // check top == NULL -> Stack Underflow
    if(top==NULL){
        cout << "Stack UnderFlow \n";
        return -1;
    }else{
        Node*first = top;
        top=first->next;
        value=first->data;
        delete(first);
        return value;
    }
}
int getTop(){
    if(top==NULL){
        cout << "Stack UnderFlow \n";
        return -1;
    }else{
        return top->data;
    }
}
void display(){
    Node * current;
    if(top==NULL){
        cout << "Stack UnderFlow \n";
    }else{
        current=top;
        while(current!=NULL){
            cout << current->data<<"\n";
            current=current->next;
        }
    }
    cout << endl;
}
