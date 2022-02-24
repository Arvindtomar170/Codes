#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int>&v,int place){
    int n=v.size();
    vector<int>count(10,0);              //initialising the count of each element ans 0
    vector<int>sorted(n);
    for(auto it : v)
        count[(it/place)%10]++;
    for(int i=1;i<10;i++)
        count[i]=count[i]+count[i-1];    //calculating cummlative frequency

    for(int i=n-1;i>=0;i--){
        sorted[count[(v[i]/place)%10]-1]=v[i];
        count[(v[i]/place)%10]--;
    }
    v=sorted;                             //copying the sorted array back
}

void radixSort(vector<int>&v){
        int n=v.size();
        int max_e=0;                      //finding max element
        for(auto it:v)
            max_e=max(max_e,it);
        for(int place=1;max_e/place>0;place=place*10){   //sorting each palce digit using count sort from least singnificant place to most significant place
            countSort(v,place);  
        }
    }

int main(){
    cout<<"Enter the no of random input : ";
    int n;cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int r=rand()%90000+10000;
        v.push_back(r);
    }
    cout<<"Unsorted array: ";
    for(auto it : v)
         cout<<it<<" ";
    cout<<"\n";

    radixSort(v);
    cout<<"Sorted array  : ";
    for(auto it :v)
        cout<<it<<" ";
    cout<<endl;
}