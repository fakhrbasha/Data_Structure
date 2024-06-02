#include<iostream>
using namespace std;
#define size 5 
 int  stack[size] , top= -1;
void push(int value);
int pop();
int getTop();
void display();
int main(){
    push(10);  //  |     30   |
    push(20);  //  |    20    |
    push(30);  //  |   10     |  Frist In Last Out 
    display(); //  |________|
    cout << "POP \n";
    pop(); // 10 20 
    display();
    cout << "Top Element : " <<getTop()<<endl; // 20
}
void push(int value){ // if top == size -1 -> Stack Full
    if( top == size -1){
        cout<< "Stack OverFlow \n";
    }else{
        top++;
        stack[top]=value; // insert Value in top
    }
}
int pop(){ // if top == -1 -> Stack Empty Can't Delete
    if(top == -1){
        cout << "Stack IS Empty \n";
    }else{
        return stack[top--];
    }
}
int getTop(){
    if(top == -1){
        cout << "Stack IS Empty \n";
    }else{
        return stack[top];
    }
}
void display(){ // if top == -1 -> Stack Empty Can't Display Element
    if (top == -1){
        cout << "Stack Is Empty \n";
    }else {
        for(int i = top ; i>=0 ; i--){ // print reverse first in last out
            cout << stack[i]<<endl;
        }
    }

}