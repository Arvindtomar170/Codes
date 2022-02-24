#include <bits/stdc++.h>
using namespace std;

  vector<int> arr_heap;
  vector<int> arr_QSL;
  vector<int> arr_QSR;
/*------------------------------------------------------------ Heap_Sort-----------------------------------------------------------------*/

void heapipy(vector<int>&arr,int n,int i)
{
//place the element at index i to their actual position assumin_ig that all it's subtree is alrady in max heap 
    int l=2*i+1;
    int r=2*i+2;                
    int min_i=i;
    if(l<n && arr[min_i]<arr[l])
          min_i=l;
    if(r<n && arr[min_i]<arr[r])
            min_i=r;
    if(min_i!=i)
    {
      swap(arr[min_i],arr[i]);
      heapipy(arr,n,min_i);
    }        
}
/* ------------------------------------------------------convert array into max heap----------------------------------------------------*/
void buid_heap(vector<int>&arr,int n)
{
    //start from index n/2 since half element is alrady in max heap (only one element)
    for(int i=n/2;i>=0;i--)
    {
      heapipy(arr,n,i);
    }
}
void heap_sort(vector<int>&arr,int n)
{
    if(n>0)
      {
        // in one iteration place 1st (the max element of array) to the last in the array
        swap(arr[0],arr[n-1]);
        heapipy(arr,n-1,0);
        heap_sort(arr,n-1);
      }
      else
        return;
}

/*------------------------------------------------------------Heap_Sort_Ended------------------------------------------------------------*/





int partition(vector<int>&arr,int l,int h)
//divid array into two part one part contains elements less than equal to pivot and other greatet than or equal to pivot
{
    int i = l-1;
    for (int j = l; j <h; j++)
    {
        if (arr[j] < arr[h]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return (i + 1);
}
/*-------------------------------------------------quick Sort last element as pivot ---------------------------------------------------------------*/
void QS_Pivot_Last(vector<int>&arr,int l,int h)
{
    if(l>=h)
      return;
    int j=partition(arr,l,h);
    QS_Pivot_Last(arr,l,j-1);
    QS_Pivot_Last(arr,j+1,h);
}
/*-------------------------------------------------quick Sort  random element as element as pivot ------------------------------------------------------*/
void QS_Pivot_Random(vector<int>&arr,int l,int h)
{
    if(l>=h)
      return;
    int r= l+rand()%(h-l);
    swap(arr[r],arr[h]);
    int j=partition(arr,l,h);
    QS_Pivot_Random(arr,l,j-1);
    QS_Pivot_Random(arr,j+1,h);
}


/*----------------Quick Sort Ended  Note:- In both the cases( randamised quick sort and quick sort) same partition function is used---------------------------*/




int main()
{
   int num = 1e7;
   ofstream HS_time,QSL_time,QSR_time,Num_val;
   HS_time.open("HS_time.txt");
   QSL_time.open("QSL_time.txt");
   QSR_time.open("QRS_time.txt");
   Num_val.open("Num_val.txt");
    vector<bool>check(num,true);
    vector<int>prime_no;
    for(int i=2;i<num;i++){
        if(check[i]){
            prime_no.push_back(i);
            for(int j=i+i;j<=num;j+=i){
                check[j]=false;
            }
        }
    }
   for(int n=100;n<=500;n+=10){

        // creating random array of prime no's by picking random prime no's in prime_no array
        for(int i=0;i<n;i++){
          int t=rand()%prime_no.size();
          arr_QSL.push_back(prime_no[t]);
          arr_QSR.push_back(prime_no[t]);
          arr_heap.push_back(prime_no[t]);
        }

       // intialising clock variable used to store the time of that instant

        clock_t t1,t2,t3,t4;
        t1=clock();
        buid_heap(arr_heap,n);
        heap_sort(arr_heap,n);
        t2=clock();
        QS_Pivot_Last(arr_QSL,0,n-1);
        t3=clock();
        QS_Pivot_Random(arr_QSR,0,n-1); 
        t4=clock();

        //storing values of time taken for n in a file
        Num_val<<n<<" ";
        double time_taken_by_heap = double(t2- t1) / double(CLOCKS_PER_SEC);
        HS_time<<fixed<<time_taken_by_heap<<setprecision(8)<<" ";
        double time_taken_by_QSL = double(t3- t2) / double(CLOCKS_PER_SEC);
        QSL_time<<fixed<<time_taken_by_QSL<<setprecision(8)<<" ";
        double time_taken_by_QSR = double(t4- t3) / double(CLOCKS_PER_SEC);
        QSR_time<<fixed<<time_taken_by_QSR<<setprecision(8)<<" ";

        cout<<fixed<<time_taken_by_heap<<" "<<time_taken_by_QSL<<" "<<time_taken_by_QSR<<setprecision(30)<<endl;

        for(auto i:arr_heap)
            cout<<i<<" ";
        cout<<"\n";
        for(auto i:arr_QSL)
              cout<<i<<" ";
        cout<<"\n";
        for(auto i:arr_QSR)
              cout<<i<<" ";
        cout<<"\n\n\n";
        arr_heap.clear();
        arr_QSL.clear();
        arr_QSR.clear();
      
    }
    QSL_time.close();
    QSR_time.close();
    HS_time.close();
    Num_val.close();
}