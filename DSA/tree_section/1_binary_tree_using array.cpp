// insert & traverse
#include<iostream>
using namespace std;
char tree[100];

void rootnode(char key){
   if(tree[0] != '\0')
      cout<<"Tree already had root";
   else
      tree[0] = key;
}

void leftchild(char key, int parent){
   if(tree[parent] == '\0')
      cout <<"\n Can't set child at "<<(parent * 2) + 1<<" , no parent found";
   else
      tree[(parent * 2) + 1] = key;
}

void rightchild(char key, int parent){
   if(tree[parent] == '\0')
      cout<<"\n Can't set child at "<<(parent * 2) + 2<<" , no parent found";
   else
      tree[(parent * 2) + 2] = key;
}

//breadth first traverse
void traversetree(){
   cout << "\n";
   for(int i = 0; i < 100; i++){
      if(tree[i] != '\0')
         cout<<tree[i]<<" ";
      else
         continue;
   }
}

int main(){
   rootnode('A');
   rightchild('B', 2);
   leftchild('C', 0);
   rightchild('D', 0);
   rightchild('E', 1);
   rightchild('F', 2);
   traversetree();
   return 0;
}


