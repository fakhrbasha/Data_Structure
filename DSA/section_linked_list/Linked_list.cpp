// some functions --linked list --
#include<iostream>
using namespace std;
struct Node{
	int data;
    Node* link;
};
Node *first = NULL, *last=NULL, *newnode;


void insert_back(){ //forward
	int info;
	cout<<"enter data to insert in linked list : ";
	cin>>info;
	newnode=new Node;
	newnode->data = info;
	newnode->link=NULL;
	
	if(first==NULL)
		first=newnode;
	else
		last->link=newnode;
	last=newnode;
}


void insert_front(){ // backword 
	int info;
	cout<<"enter data to insert in linked list : ";
	cin>>info;
	newnode=new Node;
	newnode->data = info;
	newnode->link=first;
	if(first==NULL){
		last=newnode;
	}
    first = newnode;
}

void display(){
	Node* current = first;
	if(current==NULL)
    	cout<<"empty list"<<endl;
    else{
    	cout<<"data in the list : ";
	    while(current!=NULL){
	    	cout<<(current->data)<<"    ";
	    	current=current->link;
    	}
	}
	cout<<endl;
}

void search(){
	int num, count=0;
	cout<<"enter the number to search in the list: ";
	cin>>num;
	Node* current = first;
    while(current!=NULL){
    	count++;
	    if(current->data==num){
	    	cout<<"founed at location : "<<count<<endl;
	    	return;
		}
	    current=current->link;
	}
	cout<<"not founded"<<endl;
}

void sort_linkedlist(){
	if (first->link == NULL)
		return;
	Node * current = first, *min, *temp;
	while(current->link != NULL){
		min = current;
		temp = current->link;
		while(temp != NULL){
			if(temp->data < min->data)
				min = temp;
			temp=temp->link;
		}
		swap(current->data,min->data);
		current=current->link;
	}
}

void count(){
	int count = 0;
	Node* current = first;
	    while(current!=NULL){
	    	count++;
	    	current=current->link;
    	}
    	cout<<"number of elements : "<<count<<endl;
}

void delete_front(){
	if(first == NULL)
		cout<<"empty list \n";
	else if(first->link == NULL)
		last = first = NULL;
    else
		first = first->link;
}

void delete_last(){
	if(first == NULL)
		cout<<"empty list \n";
	else if(first->link == NULL)
		last = first = NULL;
    else{
    	Node *current = first;
   		while(current->link->link != NULL)
	    	current=current->link;
	    current->link = NULL;
	    last = current;
    	}
}

void delete_sp(){
	int num;
	cout<<"enter the number to delete : ";
	cin>>num;
	Node* current = first;
	if(first->data==num){
      cout<<"The element : "<< first->data <<" deleted";
      first = first->link;
      return ;
	}
    while(current->link!=NULL){
	    if(current->link->data==num){
	    	Node *d = current->link;
	    	current->link = current->link->link;
	    	delete d;
	    	cout<<num<<" deleted"<<endl;
	    	return;
		}
	    current=current->link;
	}
	cout<<"not founded"<<endl;
}


int main(){
	int num;
	while(true){
		cout<<" 1:insert_back  2:insert_front   3:search data   4:display   5:delete_front   6:delete_back  7:delete_specific   8:count  9:sort\n ";
		cin>>num;
		if(num==1)
			insert_back();
		else if(num==2)
		    insert_front();
		else if(num==3)
		    search();
		else if(num==4)
		    display();
		else if(num==5)
		    delete_front();
		else if(num==6)
		    delete_last();
		else if(num==7)
		    delete_sp();
		else if(num==8)
		    count();
		else if(num==9)
		    sort_linkedlist();
		else
			break;
		cout<<"______________________ \n";
	}
	
		return 0;
}
