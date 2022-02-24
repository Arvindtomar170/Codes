/* 
 as the name suggest insertion sort 
  we divide the array in two parts 
           1. sorted arrays   --> initially sorted array contain only on elemenr array[0]
           2. unsorted arrays 
    then we try to increase the length of the sorted arr by picking up one-one elment form the unsorted array 
    and inserting that element in the sorted array 

    ex ;
         6 4 5 9 8     --> here  sorted array is    6   and unsorted is   4 5 9 8 
      6     4 5 9  8
after first iteration   (pic first element from unsorted and insert it in sorted array)
    4 6     5 9 8
then 
    4 5 6     9 8
    4 5 6 9     8
    4 5 6 8 9

    outer loop run n-1 time since one element i.e array[0] is always in sorted position 
 */

#include <iostream>
using namespace std;

//insertion sort itterative
void insertion_sort_it(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int j = i + 1;
            while (j > 0 && arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                j--;
            }
        }
    }
}
// insertion sort recursive code
void insertion_sort(int arr[], int n, int ind = 1)
{
    if (ind == n)
        return;
    if (arr[ind - 1] > arr[ind])
    {
        int j = ind;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j], arr[j - 1]);
                j--;
        }
    }
    ind++;
    insertion_sort(arr, n, ind);
}
int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the no in the array to be sorted : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertion_sort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}