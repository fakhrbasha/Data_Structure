#include<iostream>
using namespace std;
class Linkedlist{

    struct Node
    {
        int item;
        Node* next;
    };
    Node * first;
    Node* last;
    int length;
public:
    Linkedlist(){
        first=last=NULL;
        length=0;
    }
    bool isempty(){ // check
        return length==0;
    }
    void insertfirst(int element){
        Node* newNode= new Node();
        newNode->item=element;
        if(length==0){
            first=last=newNode;
            newNode->next=NULL;
        } else{
            newNode->next=first;
            first=newNode;
        }
        length++;
    }
    void insertend(int element){
        Node* newNode=new Node();
        newNode->item=element;
        if(length==0){
            first=last=newNode;
            newNode->next=NULL;
        }else{
            last->next=newNode;
            newNode->next=NULL;
            last=newNode;
        }
        length++;
    }
    void insertatpos(int pos , int element){
        if(pos<0||pos>length){
            cout << "Out Of Range ";
        }else{
            Node* newNode =new Node();
            newNode->item=element;
            if(pos==0){
                insertfirst(element);
            }else if(pos==length){
                insertend(element);
            }else{
                Node* cur=first;
                for(int i=1;i<pos;i++){
                    cur=cur->next;
                }
                newNode->next=cur->next;
                cur->next=newNode;
                length++;
            }
        }
    }
    void reverse(){
        Node*prev,*next,*curr;
        prev=NULL;
        curr=first;
        next=curr->next;
        while(next!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        first=prev;

    }
    int search(int element){
        Node *curr=first;
        int pos=0;
        while(curr!=NULL){
            if(curr->item==element){
                return pos;
            }
            curr=curr->next;
            pos++;
            
        } 
        return -1;
    }
    void print(){
        Node* cur=first;
        while(cur!=NULL){
            cout << cur->item<<" ";
            cur=cur->next;

        }
    }


};
int main(){
    Linkedlist l;
    l.insertfirst(10);
    l.insertend(20);
    l.insertend(30);
    l.insertatpos(1,70);
    l.insertfirst(45);
    //l.reverse();
    cout << l.search(20) <<endl;
    
    l.print();

}