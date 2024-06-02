#include<iostream>
using namespace std;
void insertionSort(int arr , int sz){
    int key , j;
    // 0     1  2  3  4  5  6 
    // 80 | 90 70 60 30 50 40 
    for(int i=1 ; i<sz ; i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] =arr[j];
            j--;
            
            
        }
        arr[j+1] = key;

    }
}