#include<bits/stdc++.h>
#define ll long long int
ll dp[100][1000];
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n+2];
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    int x;
    cin>>x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(j>=ar[i])
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-ar[i]];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }

        }
    }
    cout<<dp[n][x]<<endl;


}
