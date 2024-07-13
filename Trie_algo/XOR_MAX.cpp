// given some nn number and  query ,you have to find max xor value

//5
//3 4 8 13 6
//2
//4
//11
//Query 1: 3 12  4 xor 8= 12 which is maximum
//Query 2: 2 15  11 xor 4=15


#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=1e5;
int ar[N+5];
struct node
{
    int id=0;
    node* l=NULL;
    node* r=NULL;
};

bool is_set_bit(int num,int k)
{
    return (num&(1LL<<k));
}

void insert(node* head,int num,int indx)
{
   int pp;
   for(int i=30;i>=0;i--)
   {
       pp=is_set_bit(num,i);
       if(pp==0)
       {
           if(head->l == NULL) // jodi left a kono value na thake taila left a akta new node create korte hobe
           {
              head->l=new node();
           }
           head=head->l;   // head ke new left ar dika pointer kore rakbe
       }
       else
       {

        if(head->r == NULL)
        {
        head->r=new node();
        }
        head=head->r;
       }
       if(i==0) head->id=indx;
   }

}

pair<int ,ll>query(int num,node* head)
{
    ll ans=0;
    ll pp;
    int indx;
    for(int i=30;i>=0;i--)
    {
      pp=is_set_bit(num,i);
      if(pp==0)
      {
          if(head->r!=NULL) // jahato xor tai 0 hole 1 khojbo r 1 hole 0 khojbo
          {
              ans+=(1LL<<i);
              head=head->r;
          }
          else head=head->l; // jode right a keso na thake taila must lesta jaite hobe
      }
      else
      {
           if(head->l!=NULL)
          {
              ans+=(1LL<<i);
              head=head->l;
          }
          else head=head->r;
      }

      if(i==0)indx=head->id;

    }
    return {indx,ans};

}


int main()
{
    int n,m;
    cin>>n;
    node* head =new node();
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
        insert(head,ar[i],i);
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int a;
        cin>>a;
        auto ans=query(a,head);
        cout<<"Query "<<i<<": "<<ans.first<<" "<<ans.second<<endl;
    }



}
