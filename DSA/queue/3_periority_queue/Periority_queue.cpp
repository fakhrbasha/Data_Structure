#include <iostream>
using namespace std;
struct node{ // node declaration 
   int info;
   int periority;
   node *link;
};
    node *first = NULL , *new_node ;
    void insert(int info, int per) {
         new_node = new node;
         new_node->info = info;
         new_node->periority = per;
         if (first == NULL || per < first->periority) {
            new_node->link= first;
            first = new_node; 
		 } 
		 else {
            node *current = first;
            while (current->link != NULL && current->link->periority <= per)
               current = current->link;
               
            new_node->link = current->link;
            current->link = new_node;
         }
      }
      void del() {
         if(first == NULL) //if queue is empty
            cout<<"Queue Underflow\n";
         else {
            node *d = first;
            cout<<"Deleted item is: "<<first->info<<endl;
            first = first->link;
            delete d;
         }
      }
      void show(){ //print queue 
         node *current = first;
         if (first == NULL)
            cout<<"Queue is empty\n";
         else {
            cout<<"Queue item"<<"  "<<"Priority \n";
            while(current != NULL) {
               cout<<current->info<<"\t\t"<<current->periority<<endl;
               current = current->link;
            }
         }
      }
int main() {
   int ch , data, per;
   do{  //perform switch opeartion 
      cout<<"1.Insert\n";
      cout<<"2.Delete\n";
      cout<<"3.Display\n";
      cout<<"4.Exit\n";
      cout<<"Enter your choice : ";
      cin>>ch;
      switch(ch) {
         case 1:
            cout<<"Input the item value to be added in the queue : ";
            cin>>data;
            cout<<"Enter its priority : ";
            cin>>per;
            insert(data, per);
            break;
         case 2:
            del();
            break;
         case 3:
            show();
            break;
         case 4:
            break;
         default:
         cout<<"Wrong choice\n";
      }
   }
   while(ch != 4);
   return 0;
}
