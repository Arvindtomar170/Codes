/* 
it compare every element by its adjecent element and then swap according to the condition 
    in the first iteration the largest element go to the last 
    ex 
      3 4 6 1 2 7 2
after first loop 
         3 4 1 2 6 2 7
         3 1 2 4 2 6 7
         1 2 3 2 4 6 7
         1 2 2 3 4 6 7 
         1 2 2 3 4 6 7
it run n-1 times .. 
  why  outer loop run should run n-1 time in worse case 
     becouse after placing n-1 element to its postion smallest element automatically get at first position 
*/
#include <bits/stdc++.h>
using namespace std;
// bubble sort recursive  
void bubble_sort(int arr[],int n)
{
    if(n==1)
        return;
    for(int i=0;i<n-1;i++)
      if(arr[i]>arr[i+1])
         swap(arr[i],arr[i+1]);
    bubble_sort(arr,n-1);
}
//bubble sort iterative
void bubble_sort_it(int arr[],int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main()
{
    int arr[] = {9,8,7,6,5,4,3};
    bubble_sort_it(arr,7);
     for (int i = 0; i < 7; i++)
            cout << arr[i] << " ";
        cout << endl;
    return 0;
}