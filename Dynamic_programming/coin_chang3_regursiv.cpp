#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[100][2000];
vector<ll>ar(100);
 //given  n coins with weight.. how many different possible way to make with them n .
ll cncg(vector<ll>&ar,ll n,ll x)
{
   if(x==0) return 1;
   if(x<0) return 0;
   if(n<=0 && x>0) return 0;
   if(dp[n][x]!=-1) return dp[n][x];
   dp[n][x]=cncg(ar,n,x-ar[n-1])+cncg(ar,n-1,x);
   return dp[n][x];
}

int main()
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<2000;j++)
        {
            dp[i][j]=-1;
        }
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int x;
    cin>>x;
    ll ans = cncg(ar,n,x);
    cout<<ans<<endl;


}
