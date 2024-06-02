#include<iostream>
using namespace std;
int Binarysearch(int arr[], int last , int end , int key){
    while(last<=end){
        int mid=(last+end)/2;
        if(arr[mid]==key){
            return mid; // best case
        }
        if(arr[mid]>key){
            end=mid-1;
        }else{
            last=mid+1;
        }
    }
    return -1;
}
/*
int BinarySearchRec(int arr[] , int last , int end , int key){
    while(last<=end){
        int mid=(last+end)/2
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]>key)
            BinarySearchRec(arr,last,mid-1,key);
        
        BinarySearchRec(arr,mid+1,end,key);
    }
    return -1;
}

*/
int main(){
    int arr[]= {10,3,4,5,87,4};
    int n=sizeof(arr)/sizeof(arr[0]); // size
    int key;
    cout << "Enter Number : ";
    cin >> key;
    int res=Binarysearch(arr,0,n-1,key);
    if(res==-1){
        cout << "Number Not Found \n";
    }else{
        cout << "Number is : "<< arr[res] << " In IDX : "<< res<<endl;
    }
}