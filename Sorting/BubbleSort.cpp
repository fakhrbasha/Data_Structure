#include<iostream>
using namespace std;
//O(n*2)
void BubbleSort(int arr[] , int sz){
    // 0 1 2 3 4 5
    // 10 4 6 8 3
    bool flag=true; int c=0;
    for(int i=0 ; i<sz-1 ; i++){
        for(int j=0 ; j<sz-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j] , arr[j+1]);
                flag = false;
            }
        }
        c++;
    }
    cout << "# of round : "<<c<<endl;

}
void print(int arr[] , int sz){
    for(int i=0 ; i<sz ; i++){
        cout << arr[i]<< " ";
    }
    cout << endl;
}
int main(){
    int arr[] = {10 , 4 ,6 , 8 , 3};
    int sz = sizeof(arr)/sizeof(arr[0]);
    print(arr,sz) ; 
    BubbleSort(arr,sz);
    cout << "After : ";
    print(arr,sz);
}