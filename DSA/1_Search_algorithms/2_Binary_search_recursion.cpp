#include<iostream>
using namespace std;

//binary search function using recursion 
int binarysearch(int arr[] ,int l ,int r ,int s){
	if(r>=l) {
		int mid = (l+r)/2;  //or	int mid = l + (r - l)/2;
		if(arr[mid] == s) 
			return mid;
		else if(arr[mid] > s) 
			return binarysearch(arr ,l ,mid-1 ,s);
		else 
			return binarysearch(arr ,mid+1 ,r ,s); }
	else 
		return -1;
}

//________________________
int main(){
	int n, s;
	cout<<"enter the size of array : ";
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cout<<"enter element "<<i+1<<" : ";
		cin>>arr[i];
	}
	cout<<"enter the value you want to search: ";
	cin >> s;
	int re = binarysearch(arr , 0 , n-1 , s); 
    (re != -1)? cout <<"existed at index "<< re :cout<<"not existed " ;
	return 0;
}
