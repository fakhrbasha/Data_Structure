#include<iostream>
using namespace std;
void selectionsort(int arr[] , int n){
    int minidx;              // 0  1  2  3  4 
    for(int i=0;i<n-1;i++){ // 10 3 55  6  4 
        minidx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minidx]){
                swap(arr[minidx] , arr[j]);
            }
        }

    }
}
void print(int arr[] , int sz){
    for(int i=0;i<sz;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
} 
int main(){
    int arr[]={10,3,55,6,4};
    int n=sizeof(arr)/sizeof(arr[0]); //size
    selectionsort(arr,n);
    cout << "After \n";
    print(arr,n); 
}