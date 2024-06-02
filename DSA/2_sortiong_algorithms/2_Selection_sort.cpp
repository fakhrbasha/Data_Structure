/* Selection Sort Complexity
Time Complexity	 
Best	O(n2)
Worst	O(n2)            */

#include<iostream>
using namespace std;

//selection sort function
void selection_sort(int arr[], int n){
	int min;
	for(int i=0; i<n-1 ;i++){
		min = i;
		for(int j=i+1; j<n ;j++)
			if(arr[j]<arr[min])
				min = j;
		swap(arr[i],arr[min]);			
	}
}

//print array
void display(int arr[], int n){
	for(int i=0; i<n; i++)
	   cout<<arr[i]<<"  ";
}

int main(){
	int n;
	cout << "enter the size of array: ";
	cin >> n;
	int arr[n];
	for(int i=0 ; i<n ;i++){	
		cout<<"enter the element "<< i+1 <<": ";
		cin>>arr[i];	
	}
	selection_sort(arr,n);
    display(arr,n);			
	return 0;
}
