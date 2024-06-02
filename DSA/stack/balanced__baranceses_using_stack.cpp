#include<iostream>
using namespace std;
char stack[100], n=100, top=-1;

bool isempty(){
 if(top==-1)
	return true;
 else
	return false;
}

void push(char val) {
      top++;
      stack[top]=val;
}

void pop() {
   if(isempty())
   cout<<"notbalanced"<<endl;
   else {
      top--;
   }
}

void isbalanced(string str){
	for(int i=0;i<str.length();i++){
		if(str[i]=='('||str[i]=='{'||str[i]=='[')
			push(str[i]);
		else if(str[i]==')'||str[i]=='}'||str[i]==']'){
			if(isempty()){
				cout<<"not balanced ";
				return;
			}
			else if((str[i]==')'&&stack[top]=='(')||(str[i]=='}'&&stack[top]=='{')||(str[i]==']'&&stack[top]=='['))
				pop();
			else {
				cout<<"not balanced ";
				return;
			}
	  	}
		else
			continue;
	}
	if(isempty())
		cout<<"balanced ";
	else 
		cout<<"not balanced ";
}


int main(){
	string str = "([a+b]*c)/{a*c}";
	isbalanced(str);
}
