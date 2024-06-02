/* Bubble Sort Complexity
Time Complexity	 
Best	O(n)
Worst	O(n2)        */

#include<iostream>
using namespace std;
//Bubble sort function
void bubbleSort(int arr[], int n){
	bool swapped ;
    for(int i=0; i<n-1; i++) {
    	swapped = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
    	if (swapped == false)
      		break;
    }
}

//____________________
//print array function
void display(int arr[], int n){
	for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main()
{
	int n;
	cout<<"enter number of elements : ";
	cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
    	cout<<"Enter Element "<<i+1<<" : ";
    	cin>>arr[i];
	}
	
    bubbleSort(arr, n);
    display(arr, n);
    return 0;
}

