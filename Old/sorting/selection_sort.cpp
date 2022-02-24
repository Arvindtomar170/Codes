/*  
we always find the minimum element and the replce it but the element at the first postion 
 5 4 3 2 1
 after first iteration it will look like
             1 4 3 2 5
        then 1 2 3 4 5
        then 1 2 3 4 5
        then 1 2 3 4 5
    

    finding minimum from the sorted array and put it in the end of the sorted array 
      outer loop run n-1 run n-1 times in the worse worse case
        since the last elment is alrady at its position
*/
#include <bits/stdc++.h>
using namespace std;
//selection sort iterative 
void selection_sort_it(int arr[],int n)
{
     for (int i = 0; i < n-1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
                minIndex = j;
        }
        if (i != minIndex)
            swap(arr[i], arr[minIndex]);
    }
}
//selection sort recursive
void selection_sort(int arr[],int size,int index=0)
{
  if(index==size-1)
      return;
  int min=index;
  for(int i=index;i<size;i++)
  {
      if(arr[min]>arr[i])
          min=i;      
  }
  swap(arr[index],arr[min]);
  index++;
  selection_sort(arr,size,index);
}
int main()
{
    int arr[] = {5, 4, 1, 2, 1};
    selection_sort(arr,5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}