#include<bits/stdc++.h>
using namespace std;

void bucketSort(vector<double>&arr,int noOfBuckets){
    if(arr.size()<=1) 
       return;
    double min_e=*min_element(arr.begin(),arr.end());
    double range=*max_element(arr.begin(),arr.end())-min_e;
    if(range==0)                                                    //all elements are equal
         return;

    double sizeOfBuckets =range/noOfBuckets;
    vector<double> buckets[noOfBuckets+1];
    for(int i=0;i<arr.size();i++){
         int index=(arr[i]-min_e)/sizeOfBuckets;
        buckets[index].push_back(arr[i]);
    }

    for(int i=0;i<=noOfBuckets;i++){                                         //sort all buckets again using any other methord
        // sort(buckets[i].begin(),buckets[i].end()); 
        bucketSort(buckets[i],noOfBuckets);   
    }

    int index = 0;
	for (int i = 0; i <= noOfBuckets; i++)                                   // combine all the sorted buckets again
		for (int j = 0; j < buckets[i].size(); j++)
			arr[index++] = buckets[i][j];
}


int main(){
        default_random_engine generator;                     
        vector<double>arr;
        int n;cout<<"Enter the size of the array : ";cin>>n;
        double a=0,b=1;
        uniform_real_distribution<double> distribution(a,b);        //used for gentration uniformly distributed random no's in the range [0,1];
        for(int i=0;i<n;i++){
            double ran=distribution(generator);
            if(ran==0){
                i--;
                continue;
            }
            arr.push_back(ran);
        }
        cout<<"Randomly genrated array is : ";
        for(int i=0;i<n;i++)                                               
            cout<<arr[i]<<"  ";
        cout<<"\n\n";
        
        cout<<"Array after bucket Sort : ";
        bucketSort(arr,10);

        for(int i=0;i<n;i++)
           cout<<arr[i]<<"  ";
        cout<<"\n";
       // cout<<distribution.a()<<" "<<distribution.b();                       //minimum and maximum possible values of the distribution
}