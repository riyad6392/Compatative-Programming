#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll ar[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    ll psm[n+2];
    psm[0]=0;
    for(int i=1;i<=n;i++)
    {
        psm[i]=psm[i-1]+ar[i];
    }
    ll ans[n+2];
    for(int i=0;i<=n;i++)
    {
        ll pp=psm[i]%n;
        pp=(pp+n)%n;
        ans[i]=pp;
    }
    map<ll,int>mp;
    ll cnt=0;
    for(int i=0;i<=n;i++)
    {

        ll an=mp[ans[i]];
        if(an>0)
        {
            cnt+=an;
        }
         mp[ans[i]]++;

    }
    cout<<cnt<<endl;

}
