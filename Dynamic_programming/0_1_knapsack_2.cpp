#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=110;

ll wt[N],vl[N];
ll dp[N][100002];
int kl;
ll knapsack(ll n,ll w){ // w=value_left
    if(w==0) return 0;
    if(n<0) return 1e15;
    if(dp[n][w]!=-1) return dp[n][w];
    ll ans= knapsack(n-1,w);
    if(w-vl[n]>=0)
    {
        ans=min(ans, knapsack(n-1LL,w-vl[n])+wt[n]);
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
    ll mx_vlu=1e5;

    for(int i=mx_vlu;i>=0;i--)
    {
        if(knapsack(n-1,i)<=w)
        {
            cout<<i<<endl;
            break;
        }

    }


}

