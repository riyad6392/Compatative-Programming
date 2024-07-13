#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,q;
  cin>>n>>q;
  int ar[n];
  for(int i=0;i<n;i++)
  {
      cin>>ar[i];
  }
  int k=log2(n);
  int dp[k+1][n+1];
  for(int i=0;i<n;i++)
  {
      dp[0][i]=ar[i];
  }
  for(int i=1;i<=k;i++)
  {
      for(int j=0;j+(1<<i)<= n; j++)
      {
          dp[i][j]=min(dp[i-1][j],dp[i-1][j+(1<<(i-1))]);
      }
  }
  while(q--)
  {
      int a,b;
      cin>>a>>b;
      a--;
      b--;
      int ln=b-a+1;
      int mx=log2(ln);
      int ans=min(dp[mx][a],dp[mx][b-(1<<mx)+1]);
      cout<<ans<<endl;

  }

}
