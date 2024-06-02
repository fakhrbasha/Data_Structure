/* isertion Sort Complexity
Time Complexity	 
Best	O(n)
Worst	O(n2)           */

#include <iostream>
using namespace std;

//insertion sort function
void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
//_________________________________

// print arry
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 
int main()
{
	int n;
	cout << "enter the size of array: ";
	cin >> n;
	int arr[n];
	for(int i=0 ; i<n ;i++){	
		cout<<"enter the element "<< i+1 <<": ";
		cin>>arr[i];	
	}
    insertion_sort(arr, n);
    printArray(arr, n);
 
    return 0;
}
