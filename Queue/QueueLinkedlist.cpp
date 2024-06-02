#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node*front =NULL;
Node*rear=NULL;
void enqueue(int value);
void dequeue();
int getTop();
void display();
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40); // 10 20 30 40 
    display();
    cout << "POP\n";
    dequeue();
    display(); // 20 30 40
    cout <<"Top  : " <<getTop()<<endl; // 20
}
void enqueue(int value){
    Node * newNode =new Node;
    newNode->data=value;
    newNode->next=NULL;
    if(front==NULL) // first element
    {
        front=rear=newNode;
    }else{
        rear->next=newNode;
        rear=newNode;
    }
}
void dequeue(){
    // check empty 
    if(rear==NULL){
        cout << "Queue Is Empty\n";
    }else if(front==rear){ // only element in Q
        Node*ptr=front;
        front=rear=NULL;
        delete (ptr);
    } else{
        Node*ptr=front;
        front=front->next;
        delete(ptr);
    }
}
int getTop(){
    if(front==NULL){
        cout << "Queue Is Empty \n";
        return -1;
    }else{
        return front->data;
    }
}
void display(){
    if(front==NULL){
        cout << "Queue Is Empty \n";
    }else{
        Node*current=front;
        while(current!=NULL){
            cout << current->data <<endl;
            current=current->next;
        }
        cout<<endl;
    }
}