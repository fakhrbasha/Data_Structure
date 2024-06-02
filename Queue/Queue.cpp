#include<iostream>
using namespace std;
#define Size 5
int Queue[Size];
int front = -1 , rear = -1 ; 
void enqueue(int value);
void dequeue();
int getTop();
void display(){ // check Queue full or no
    if(front!= -1 && rear != -1 && front <= rear){
        for(int i=front ; i<=rear ; i++){
            cout << Queue[i] << endl;
        }
        cout << endl;
    }else{
        cout << "Queue Is Empty \n";
    }

}

int main(){
    enqueue(5);
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40); 
    display(); // 5 10 20 30 40 
    cout << "Dequeue \n";
    dequeue(); // 10 20 30 40
    display();
    cout << "get Top : " <<getTop()<<endl;
}
void enqueue(int value){
    if(rear!= Size-1){ // queue have an element
        if(front == -1 && rear == -1 ){
            front ++;
            rear++;
            Queue[rear]=value; // insert frist value
        } else{
            Queue[++rear]=value; // if value don't be first value
        }       
    }else{
        cout << "Queue Is  Full \n";
    }
}
void dequeue(){ // check Queue full or no
    if(front != -1 && rear != -1 && front<=rear){
        front ++;
    }else{
        cout << "Queue Is Empty \n";
    }
}
int getTop(){ // check Queue full or no
    if(front != -1 && rear != -1 && front <= rear){
        return Queue[front];
    }else{
        cout << "Queue is empty \n";
        return -1;
    }
}