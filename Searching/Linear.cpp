// C -> Worst case O(n) Best O(1)
#include <iostream>
using namespace std;
int linearsearch(int arr[] , int sz , int key){
    for(int i=0;i<sz;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={10,20,30,40,50};
    int n=sizeof(arr)/sizeof(arr[0]); // size 
    int num;
    cout << "Enter Key : ";
    cin >> num;
    int res=linearsearch(arr,n,num);
    if(res==-1){
        cout << "Number Not Found\n";
    }else{
        cout << "the Nubmer "<< arr[res] << " 1at idx "<< res<<endl;
    }
    
}