#include<bits/stdc++.h>
#define ll long long int
using namespace std;
map<ll,ll>mp,mp1;
int p,q;
ll Hash(const string &s,int m,ll B,ll M)
{
    ll power=1;
    ll has=0;
    for(int i=m-1;i>=0;i--)
    {
        has=(has+(s[i]*power)%M);
        has=has%M;
        power=(power*B);
    }
    return has;
}
void solve1(const string &s,const string &s1,int m)
{
    ll B=347,M=1000000007;
    int n=s.size();
    ll first=Hash(s,m,B,M);
    ll second=Hash(s1,m,B,M);
    mp[first]++;
    p=0;
    vector<ll>vt1;
    vt1.push_back(second);
    ll power=1;
    for(int i=1;i<=m-1;i++)
    {
        power=(power*B)%M;
    }
    for(int i=m;i<n;i++)
    {
        ll pp=0;
        ll qq=0;
        first=(first-(power*s[i-m])%M)%M;
        first=(first+M)%M;
        first=(first*B)%M;
        first=(first+s[i])%M;
        mp[first]++;

        second=(second-(power*s1[i-m])%M)%M;
        second=(second+M)%M;
        second=(second*B);
        second=(second+s1[i])%M;
         vt1.push_back(second);

    }
    for(auto a: vt1)
    {
        if(mp[a]>0)
        {
            p=1;
            break;
        }
    }



}


void solve2(const string &s,const string &s1,int m)
{
    ll B=277,M=987654319;
    int n=s.size();
    ll first=Hash(s,m,B,M);
    ll second=Hash(s1,m,B,M);
    mp1[first]++;
    q=0;
    ll power=1;
    for(int i=1;i<=m-1;i++)
    {
        power=(power*B)%M;
    }
    vector<ll>vt;
    vt.push_back(second);
    for(int i=m;i<n;i++)
    {
        ll pp=0;
        ll qq=0;
        first=(first-(power*s[i-m])%M)%M;
        first=(first+M)%M;
        first=(first*B)%M;
        first=(first+s[i])%M;
        mp1[first]++;

        second=(second-(power*s1[i-m])%M)%M;
        second=(second+M)%M;
        second=(second*B);
        second=(second+s1[i])%M;
        vt.push_back(second);
    }
    for(auto a:vt)
    {
        if(mp1[a]>0)
        {
            q=1;
            break;
        }
    }
    if(p==1 && q==1)
    {
        cout<<"Accept"<<endl;
    }
    else
    {
        cout<<"Reject"<<endl;

    }


}



int main()
{
    int n,m;
    cin>>n>>m;
    string s,s1;
    cin>>s;
    s1=s;
    reverse(s1.begin(),s1.end());
    solve1(s,s1,m);
    solve2(s,s1,m);



}

