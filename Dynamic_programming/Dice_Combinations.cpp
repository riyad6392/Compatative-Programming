#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod=1e9+7;
const int N=1e6+10;
ll dp[N];
ll ans;
ll deck(ll n)
{
    if(n<0)
    {
        return 0;
    }
    if(n==0)
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    ll res=0;
    for(int i=1;i<=6;i++)
    {
        res+=deck(n-i);
        res=res%mod;
    }
    res=res%mod;
    return dp[n]=res;

}
int main()
{
    for(int i=0;i<N;i++)
    {
        dp[i]=-1;
    }
    ll n;
    cin>>n;
    ans=deck(n);
    ans=ans%mod;
    cout<<ans<<endl;

}
