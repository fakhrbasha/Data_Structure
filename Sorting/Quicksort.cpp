#include<iostream>
using namespace std;
int partition(int arr[], int start , int end){
    int pivot=arr[start];
    int i=start;
    int j= end;
    while(i<j){
        do{
            i++;
        }while(arr[i]<=pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[start],arr[j]);
    return j;
}
void quicksort(int arr[],int start , int end){
    if(start<end){
        int piv=partition(arr,start,end);
        quicksort(arr,start,piv);
        quicksort(arr,piv+1,end);
    }
}
int main(){
    int arr[]={10 , 30 ,40, 50, 7,79};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    for(int i=0 ; i<n ; i++){
        cout << arr[i] <<" ";
    }
}