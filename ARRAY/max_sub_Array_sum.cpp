//Kadane’s algorithm
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll max_sum=INT_MIN;
    ll cur_sum=0;
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        cur_sum=cur_sum+ar[i];
        if(cur_sum>max_sum)
        {
            max_sum=cur_sum;
        }
        if(cur_sum<0)
        {
            cur_sum=0;
        }


    }
    cout<<max_sum<<endl;

}

