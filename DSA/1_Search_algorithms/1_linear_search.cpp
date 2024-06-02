/*Linear Search Complexity
Time Complexity:
Best    O(1)
worst   O(n)          */

// C++ code to linearly search s in arr[]. If s
// is present then return its location, otherwise
// return -1
 
#include <iostream>
using namespace std;
 
int search(int arr[], int n, int s)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == s)
            return i;
    return -1;
}
 
// Driver code
int main()
{
	int n , s;
	cout<<"enter size of array : ";
	cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
    	cout<<"Enter element "<<i+1<<" : ";
        cin>>arr[i];
	}
    cout<<"\nEnter a Number to Search: ";
    cin>>s;
   
    // Function call
    int result = search(arr, n, s);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}
