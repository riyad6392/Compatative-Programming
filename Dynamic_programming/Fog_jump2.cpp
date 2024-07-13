#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll ar[100005];
ll Dp[100005];
ll k;
ll dp( ll n)
{
    if(n==1) return 0;
    if(Dp[n]!=-1) return Dp[n];
    ll cost=999999999999;

        for(int i=1;i<=k;i++)
        {
            if(n-i>0)  cost=min(cost,abs(ar[n]-ar[n-i])+dp(n-i));
        }
       return Dp[n]=cost;


}

int main()
{
  ll n;
  cin>>n>>k;
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
