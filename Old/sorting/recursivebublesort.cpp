#include <bits/stdc++.h>
using namespace std;
void recursivbublesorst(vector<int> &v, int n)
{
    if (n == 1)
        return;
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i + 1])
                swap(v[i], v[i + 1]);
        }
        recursivbublesorst(v, n - 1);
    }
}
int main()
{
    vector<int> v1{5,7,9,2,5,8,9};
    int n = v1.size();
    recursivbublesorst(v1,n);
    for(auto it:v1)
    {
        cout<<it<<" ";
    }
    return 0;
}