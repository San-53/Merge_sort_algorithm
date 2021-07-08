//Merge Sort
#include<iostream>
using namespace std;
void print_array(int arr[],int n)
{
	for (int i=0; i < n; i++) 
        cout << arr[i] <<" ";
}
void merge(int arr[],int lb,int mid,int ub)
{
	int i,j,k;
	int b[ub];
	i=lb;
	j=mid+1;
	k=lb;
	while(i<=mid && j<=ub)
	{
		if(arr[i]<=arr[j])
		{
			b[k]=arr[i];
			i++;
			k++;
		}
		else
		{
			b[k]=arr[j];
			j++;
			k++;
		}
	}
	if(i>mid)
	{
		while(j<=ub)
		{
			b[k]=arr[j];
			k++;
			j++;
		}
	}
	else
	{
		while(i<=mid)
		{
			b[k]=arr[i];
			k++;
			i++;
		}
	}
	for(int m=lb;m<=ub;m++)
	{
		arr[m]=b[m];
	}
}
void merge_sort(int arr[],int lb,int ub)
{
	if(lb<ub)
	{
		int mid=(lb+ub)/2;
		merge_sort(arr,lb,mid);
		merge_sort(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
	}
}
int main()
{
	int n;
	cout<<"Enter the number of elements : ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of the array : ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	merge_sort(arr,0,n-1);
	cout<<"Sorted array : ";
	print_array(arr,n);
	return 0;
}
