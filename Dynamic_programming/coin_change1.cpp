#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int ar[N+1];
int dp[N+1];
int n;
int Dp(int amount)
{
    if(amount==0) return 0;
    if(dp[amount]!=-1) return dp[amount];
    int rs=999999999;
    for(int i=0;i<n;i++)
    {

        if((amount-ar[i]) >=0)
        {
            //cout<<rs<<endl;
            rs=min(rs+0LL,Dp(amount-ar[i])+1LL);
        }

    }
    return dp[amount]=rs;

}

int main()
{
    int m;
    cin>>n>>m;
    for(int i=0;i<=10000;i++)
    {
        dp[i]=-1;
    }
    for(int i=0;i<n;i++)
    {

        cin>>ar[i];

    }
   int ans= Dp(m);
   if(ans==999999999)
   {
       cout<<-1<<endl;
   }
   else
   {
       cout<<ans<<endl;
   }


}
