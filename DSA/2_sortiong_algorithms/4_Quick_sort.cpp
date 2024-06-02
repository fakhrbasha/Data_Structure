/*Time Complexity	 
Best	O(n*log n)
Worst	O(n2)    */

 #include<iostream>
using namespace std;

int partition(int arr[],  int l, int r)
{
	int p = arr[l];
	int i = l;
	int j = r;
	while (i < j){
		while (arr[i] <= p)
			i++;
		while (arr[j] > p)
			j--;
	
		if (i < j)
			swap(arr[i], arr[j]);
	}
	swap(arr[l], arr[j]);
	return j;
}

void quickSort(int arr[], int l, int r)
{
	if (l < r) {
		int piv = partition(arr, l, r);
		quickSort(arr, l, piv-1);
		quickSort(arr, piv + 1, r);
	}
}

void display(int arr[], int n){
	for (int i = 0; i < n; i++)
		cout << arr[i] << "  ";
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
	quickSort(arr, 0, n-1 );
    display(arr,n);

	return 0;
}

