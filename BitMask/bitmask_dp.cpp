#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll ar[16][16];
ll dp[16][1<<16];
int n;

ll solve_dp(int i,int mask)
{
    if(mask==(1<<n)-1)return 0;

    if(dp[i][mask]!=-1)
    {
        return dp[i][mask];
    }

    ll res=-1;

    for(int j=0;j<n;j++)
    {
        if((mask&(1<<j))==0)
        {
            res=max(res,ar[i][j]+solve_dp(i+1,mask|(1<<j)));
        }

    }

    return dp[i][mask]=res;


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>ar[i][j];
            }
        }


    memset(dp,-1,sizeof(dp));
    ll ans=solve_dp(0,0);
    cout<<"Case "<<c<<": "<<ans<<endl;

    }

}
