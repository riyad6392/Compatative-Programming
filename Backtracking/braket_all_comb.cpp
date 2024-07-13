#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<string>ans;
void genarat(string &s ,int open ,int close)
{
    if(open==0 and close==0)
    {
        ans.push_back(s);
        return;
    }

    if(open>0)
    {
        s.push_back('(');
        genarat(s,open-1,close);
        s.pop_back();
    }
    if(close>0)
    {
        if(open<close)
        {
            s.push_back(')');
            genarat(s,open,close-1);
            s.pop_back();
        }
    }

}

int main()
{
    int n;
    cin>>n;
    string s;
    genarat(s,n,n);
    for(auto a : ans)
    {
        cout<<a<<endl;
    }


}
