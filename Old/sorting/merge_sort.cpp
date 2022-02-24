/* it folllow divide and con.. statigy 
  first dived the whole array in sorted array (as we know that one element is always sorted and then merge the sorted array)
  the main part of algothm is :
     merging two sorted array --> for that we creat an ectrat array 
                                  size  of the addition array created should be equal to the sum of the size of two merging array
                                  the copy the data from two sorted array to the new array such tha the new array is sorted 
                                  then copy back the data of the new array --



*/


#include <bits/stdc++.h>
using namespace std;
//function for merging two sorted arrays 
void merge(int arr[],int l,int m,int r)
{
  if(r-l<=1)
      return;
   int len=r-l;
   int *sorted_arr=new int[len];
   int i=l;
   int j=m;
   int k=0;
   while (i<m&&j<r) 
   {
       if(arr[i]<arr[j])
       {
           sorted_arr[k]=arr[i];
           i++;
       }
       else
       {
           sorted_arr[k]=arr[j];
           j++;
       }
       k++;
   }
   if(i<m)
   {
       while (i<m)
       {
           sorted_arr[k]=arr[i];
           i++;
           k++;
       }
   }
   else
   {
       while (j<r)
       {
           sorted_arr[k]=arr[j];
           j++;
           k++;
       }
    }
    for(int t=0;t<len;t++)
    {
        arr[l+t]=sorted_arr[t];
    }
    delete sorted_arr;
}
//recursive merse sort 
void merge_sort(int arr[],int left,int right)
{
    if(right-left<=1)
        return;
    int mid=(left+right)/2;
    merge_sort(arr,left,mid);
    merge_sort(arr,mid,right);
    merge(arr,left,mid,right);
         
}
//iterative merge sort 
void merge_sort_it(int arr[],int n)
{
    int len_pair=2;
    int mid;

    for(len_pair;len_pair<2*n;len_pair=len_pair*2)
    {
       int in_ind=0;
       mid =len_pair/2;
       int fi_ind=len_pair;
       for(fi_ind;fi_ind<n;fi_ind+=len_pair)
       {
           merge(arr,in_ind,mid,fi_ind);
           in_ind+=len_pair;
           mid=mid+len_pair;
       }
        merge(arr,in_ind,mid,n);
    }
}
int main()
{
int arr[]={9,8,7,6,5,4,3,2,1};
merge_sort(arr,0,9);
for(int i=0;i<9;i++)
  cout<<arr[i]<<" ";
return 0;
}