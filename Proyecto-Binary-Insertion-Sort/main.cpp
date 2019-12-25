// C program for implementation of binary insertion sort 
#include <stdio.h> 
#include <bits/stdc++.h> 
using namespace std; 

// A binary search based function to find the position 
// where item should be inserted in a[low..high] 
int binarySearch(int a[], int item, int low, int high) 
{ 
	if (high <= low) 
		return (item > a[low])? (low + 1): low; 

	int mid = (low + high)/2; 

	if(item == a[mid]) 
		return mid+1; 

	if(item > a[mid]) 
		return binarySearch(a, item, mid+1, high); 
	return binarySearch(a, item, low, mid-1); 
} 

// Function to sort an array a[] of size 'n' 
void insertionSort(int a[], int n) 
{ 
	int i, loc, j, k, selected; 

	for (i = 1; i < n; ++i) 
	{ 
		j = i - 1; 
		selected = a[i]; 

		// find location where selected sould be inseretd 
		loc = binarySearch(a, selected, 0, j); 

		// Move all elements after location to create space 
		while (j >= loc) 
		{ 
			a[j+1] = a[j]; 
			j--; 
		} 
		a[j+1] = selected; 
	} 
} 

void randArray(int arr[], int size, int order)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        arr[i] = rand() % order + 1;
    
}  

// Driver program to test above function 
int main() 
{ 
	int order = 1000000;
    
    
    int arr[order]; 
    int n = sizeof(arr)/sizeof(arr[0]);  
	randArray(arr, n, order);

	insertionSort(arr, n); 

	//printf("Sorted array: \n"); 
	//for (int i = 0; i < n; i++) 
	//	printf("%d ",arr[i]); 

	return 0; 
} 

