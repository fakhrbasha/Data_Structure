`	 /*Binary Search Complexity -- list(array) must be sorted
Time Complexity:
Best    O(1)
worst   O(log n) */

#include<iostream>
using namespace std;

//binary search function
void binary_search(int arr[], int n, int value){
	int left = 0;
	int right = n-1;
	int mid ;
	while(left<=right){
		mid = (left+right)/2;
		if(value<arr[mid])
	    	right = mid - 1;
	    else if(value>arr[mid])
	        left = mid + 1;
	    else{
	    	cout<<"value existed at index : "<<mid;
			return;
		}
	}
	   	cout<<"value not existed ";
}

//________________________
int main(){
	int n, value;
	cout<<"enter the size of array : ";
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	cout<<"enter the value you want to search: ";
	cin >> value;
	binary_search(arr,n,value);
	return 0;
}
