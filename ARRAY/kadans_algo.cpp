//https://codeforces.com/contest/1373/problem/D
#include<bits/stdc++.h>
#define ll long long int
#define     INF                             (ll)1e15
using namespace std;
ll kadans(vector<ll>vr)
{
    ll max_sum=INT_MIN;
    ll cur_sum=0;
     int n=vr.size();
     for(int i=0;i<n;i++)
    {
        cur_sum=cur_sum+vr[i];
        if(cur_sum>max_sum)
        {
            max_sum=cur_sum;
        }
        if(cur_sum<0)
        {
            cur_sum=0;
        }



    }
   // cout<<max_sum<<endl;
   return max_sum;


}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ar[n];
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];

        }
        for(int i=0;i<n;i+=2)
        {
            sum+=ar[i];
        }
        //cout<<"sm "<<sum<<endl;
        vector<ll>v_ev,v_od;
        for(int i=0;i<n;i++)
        {
            if(i%2==0 and i+1<n)
            {
                v_ev.push_back(ar[i+1]-ar[i]);
            }
            if(i%2==1 and i+1<n)
            {
                v_od.push_back(ar[i]-ar[i+1]);
            }
        }
        ll ans=0;
        ans=max(ans,kadans(v_ev));
        ans=max(ans,kadans(v_od));
        ans+=sum;
        cout<<ans<<endl;

    }

}
