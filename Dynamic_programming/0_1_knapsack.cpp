#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=110;

ll wt[N],vl[N];
ll dp[N][100005];
int kl;
ll knapsack(ll n,ll w){
    if(w==0) return 0;
    if(n<0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];
    ll ans= knapsack(n-1,w);
    if(w-wt[n]>=0)
    {
        ans=max(ans, knapsack(n-1LL,w-wt[n])+vl[n]);
    }
    return dp[n][w]=ans;

}
int main()
{
    int n,w;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<100005;j++)
        {
            dp[i][j]=-1;
        }
    }
    cin>>n>>w;
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>vl[i];
    }
    ll ans=knapsack(n-1,w);
    cout<<ans<<endl;

}
