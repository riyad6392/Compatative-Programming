#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int ar[N],tree[N*4];
void build(int node,int st,int en)
{
    if(st==en)
    {
        tree[node]=ar[st];
        return ;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(st+en)/2;
    build(left,st,mid);
    build(right,mid+1,en);
    tree[node]=tree[left]+tree[right];

}
int query(int node,int st,int en,int l,int r)
{
    if(st>r || en<l)
    {
        return 0;  //বাইরে চলে গিয়েছে
    }
    if(st>=l && en<=r)
    {
        return tree[node];
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(st+en)/2;
    int q1=query(left,st,mid,l,r);
    int q2=query(right,mid+1,en,l,r);
    return q1+q2;


}
void update(int node,int st,int en,int idx,int vlu)
{
     if(idx > en || idx < st)
    {
        return;   //বাইরে চলে গিয়েছে
    }
    if(st==en) // lif node
    {
        ar[st]=vlu;
        tree[node]=vlu;
       // cout<<tree[node]<<endl;
        return;
    }
    int mid=(st+en)/2;
    int left=node*2; //আরো ভাঙতে হবে
    int right=node*2+1;

   if(idx<=mid) update(left,st,mid,idx,vlu); //index ta left a ase
   else update(right,mid+1,en,idx,vlu);

    tree[node]=tree[left]+tree[right];
    //উপরে উঠার সময় পথের নোডগুলো আপডেট হবে



}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    build(1,0,n-1);
    while(1)
    {
        int type;
        cin>>type;
        if(type==-1)
        {
            break;
        }
        if(type==1)
        {
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            int ans=query(1,0,n-1,l,r);
            cout<<ans<<endl;

        }
        if(type==2)
        {
            int idx,vl;
            cin>>idx>>vl;
            idx--;
            update(1,0,n-1,idx,vl);

        }

    }

}
