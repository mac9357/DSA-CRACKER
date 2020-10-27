//Given an array arr[] and a number K where K is smaller than size of array, 
//the task is to find the Kth smallest element in the given array. 
//It is given that all array elements are distinct.
//Expected Time Complexity: O(N).
//Expected Auxiliary Space: O(1).

#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int l,int r);
// This function returns k'th smallest element in arr[l..r] using 
// QuickSort based method.  ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT

int kthSmallest(int arr[],int l,int r,int k)
{
	//if k is smaller than the no. of elements in array
	if(k>0&&k<=r-l+1)
	{
		// Partition the array around last element and get 
        // position of pivot element in sorted array
		int pos=partition(arr,l,r);
		//if position is same as k
		if(pos-1==k-1)
			return arr[pos];
		if(pos-1>k-1)
			return kthSmallest(arr,l,pos-1,k);
		
		return kthSmallest(arr,pos+1,r,k-pos+l-1);
	}
	
	return INT_MAX;
}

void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
//partition process of Quick sort...last element=pivot element
//moves all smaller element to the left and grater to the right
int partition(int arr[],int l,int r)
{
	int x=arr[r],i=1;
	for(int j=1;j<=r-1;j++)
	{
		if(arr[j]<=x)
		{
			swap(&arr[i],&arr[j]);
			i++;
		}
	}
	swap(&arr[i],&arr[r]);
	return i;
}

int main()
{
	int arr[]={22,45,7,12,51,19,68};
	int n=sizeof(arr)/sizeof(arr[0]),k=3;
	cout<<"K th smallest element is-> "<<kthSmallest(arr,0,n-1,k);
	return 0;
}
