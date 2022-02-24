#include <bits/stdc++.h>
using namespace std;
int partition(int arr[],int l,int h)
{
  int i=l-1,j=h;
 while (i<j)
     {
          do
          {
              i++;
          } while (arr[l]>arr[i]);
          do
          {
              j--;
          } while (arr[l]<arr[j]);
          if(i<j)
          swap(arr[i],arr[j]);
       }
       swap(arr[l],arr[j]);
       return j; 
   return 0;
}
void quickSort(int arr[],int l,int h)
{
    if(l>=h)
      return;
    int j=partition(arr,l,h);
    quickSort(arr,l,j);
    quickSort(arr,j+1,h);
}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the no's in the array : ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    quickSort(arr,0,n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    return 0;
}