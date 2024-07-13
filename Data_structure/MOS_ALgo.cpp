#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int rootN;
struct Q{
  int idx,l,r;
};
Q q[N];
bool cmp(Q q1, Q q2)
{
    if(q1.l/rootN==q2.l/rootN)
    {
        return q1.r>q2.r;
    }
    return q1.l/rootN<q2.l/rootN;

}
int main()
{

   int n;
   cin>>n;
   vector<int>v(n);
   for(int i=0;i<n;i++)
   {
       cin>>v[i];
   }
   int qrs;
   cin>>qrs;
   for(int i=0;i<qrs;i++)
   {
     int l,r;
     cin>>l>>r;
     q[i].l=l;
     q[i].r=r;
     q[i].idx=i;

   }
   sort(q,q+qrs,cmp);
   vector<int>ans(qrs);
   int curr_l=0,curr_r=-1,l,r;
   int curr_ans=0;
   for(int i=0;i<qrs;i++)
   {
       l=q[i].l;
       r=q[i].r;
       l--;
       r--;
       while(curr_r<r)
       {
           curr_r++;
           curr_ans+=v[curr_r];
       }
       while(curr_l>l)
       {
           curr_l--;
           curr_ans+=v[curr_l];

       }
          while(curr_l<l)
       {

           curr_ans-=v[curr_l];
           curr_l++;

       }
       while(curr_r>r)
       {
           curr_ans-=v[curr_r];
           curr_r--;
       }
       ans[q[i].idx]=curr_ans;

   }
   for(int i=0;i<qrs;i++)
   {
       cout<<ans[i]<<endl;
   }




}
