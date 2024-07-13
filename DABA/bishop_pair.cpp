//https://codeforces.com/contest/621/problem/B
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    map<ll,ll>mp1,mp2;
    ll l,r;
    for(int i=0;i<n;i++)
    {
        cin>>l>>r;
        mp1[l+r]++;
        mp2[l-r]++;
    }
    ll ans=0;
    for(auto a: mp1)
    {
      ans+=a.second*(a.second-1)/2;
    }
     for(auto a: mp2)
    {
      ans+=a.second*(a.second-1)/2;
    }
    cout<<ans<<endl;


}
