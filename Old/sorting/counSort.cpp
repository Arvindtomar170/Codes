#include<bits/stdc++.h>
using namespace std;

void CountSort(vector<int>&v){   //code for stable count sort 
		int n=v.size();
		vector<int>sorted(n);//creating a new vector of same size to store the sorted array
		int max_e=0;

		for(auto it:v)
			max_e=max(max_e,it);     //finding max element

		vector<int>count(max_e+1,0);  //intialising count of every vector with zero
		for(auto it: v)
			count[it]++;
		for(int i=1;i<=max_e;i++)
			count[i]=count[i]+count[i-1];  //calculation cummalative frequency

        for(int i=n-1;i>=0;i--){
			sorted[count[v[i]]-1]=v[i];
			count[v[i]]--;
		}
		v=sorted;  //copying the element of sorted array back
    }

int main(){
    cout<<"Enter max range : ";
	int k;cin>>k;
	vector<int>v;
	int n=2*k;
	for(int i=0;i<n;i++){
		int r=rand()%(k+1);
		v.push_back(r);
	}
	CountSort(v);
	for(auto it :v)
	    cout<<it<<" ";
	cout<<endl;
    return 0;
}