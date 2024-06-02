#include<iostream>
using namespace std;

int queue[5],size=5,front=-1,rear=-1;
void enqueue(int val){
	if((front==0 && rear==size-1)||front==rear+1)
		cout<<"Queue is full \n";
	else{
		rear=(rear+1)%size;
		queue[rear]=val;
		
		if(front==-1)
			front=0;
	}
}

void dequeue(){
	if(front==-1)
		cout<<"queue is empty \n";
	else if(front==rear){
		cout<<queue[front]<<"deleted \n";
		front=rear=-1;
	}
	else{
		cout<<queue[front]<<"deleted \n";
		front=(front+1)%size;
	}
}

void display(){
	if(front==-1)
		cout<<"queue is empty \n";
	else{
		cout<<"queue elements are \n";
		if(front<=rear){
			for(int i=front ;i<=rear ;i++)
				cout<<queue[i]<<" ";
			cout<<"\n";
		}
		else{
			for(int i=front ;i<size ;i++)
				cout<<queue[i]<<" ";
			for(int i=0 ;i<=rear ;i++)
				cout<<queue[i]<<" ";
			cout<<endl;
		}
	}
}

int main(){
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	display();
	dequeue();
	dequeue();
	display();
	enqueue(6);
	enqueue(7);
	display();
	return 0;
}
