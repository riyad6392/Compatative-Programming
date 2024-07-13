#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const double eps=1e-6;
int main()
{
    ll n,k;
    cin>>n>>k;
    double ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    double l=0,r=1e7+10;
    while(r-l>eps)
    {
        double mid=(l+r)/2.0;
        ll pp=0;
        for(int i=0;i<n;i++)
        {
            ll kl=(ar[i]/mid);
            pp+=kl;
        }
        if(pp>=k)
        {
            l=mid;
        }
        else
        {
            r=mid;
        }

    }

    cout<<fixed<<setprecision(6)<<l<<endl;



}
