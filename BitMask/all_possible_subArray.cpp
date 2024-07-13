// https://atcoder.jp/contests/arc061/tasks/arc061_a
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    string s;
    cin>>s;
    ll ln=s.size();
    ln--;  // + string size thke 1 kom hobe  (1 + 2 + 3 + 4)
    ll ans=0;
    for(int i=0;i<(1<<ln);i++)
    {
        string sr="";
        for(int j=0;j<=ln;j++)
        {
            sr+=s[j];
            if(i&(1<<j)) // 00100010001100  portion =00 1000 1000 1 100
            {
                ll num=stoll(sr);
                ans+=num;
                sr="";   // string null kore deba
            }

        }
        ll num=stoll(sr);
        ans+=num;

    }
    cout<<ans<<endl;

}
