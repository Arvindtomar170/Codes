#include <iostream>
#include <random>
using namespace std;
  
int main()
{
    default_random_engine generator;
    double a = 1000, b = 9999;
    uniform_real_distribution<double> distribution(a, b);
    for(int i=0;i<10 ;i++)
        cout<<distribution(generator)<<endl;
    return 0;
}