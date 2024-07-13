#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll ar[100005];
ll Dp[100005];

int dp(int n)
{
    if(n==1) return 0;
    if(n==2) return abs(ar[1]-ar[2]);
    if(Dp[n]!=-1) return Dp[n];
    return Dp[n]=min(abs(ar[n]-ar[n-1])+dp(n-1),abs(ar[n]-ar[n-2])+dp(n-2));

}

int main()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        Dp[i]=-1;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    ll ans=dp(n);
    cout<<ans<<endl;


}
