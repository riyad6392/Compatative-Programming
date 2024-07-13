//https://toph.co/p/the-punishment

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct node
{
    node* ar[26],*next;
    string ss;
    int mx;

    node()
    {
        for(int i=0;i<26;i++)
        {
            ar[i]=NULL;
        }
          mx=0;

    }


};

void insert(node* head,string s,int fre)
{

  for(int i=0;i<s.size();i++)
  {
      int id=s[i]-'a';
      if(head->ar[id]==NULL)
      {
          head->ar[id]=new node();
      }
      head=head->ar[id];
      if(fre > head->mx)
      {
          head->mx=fre;
          head->ss=s;
      }
      else if(fre==head->mx && head->ss > s)
      {
          head->ss=s;
      }

  }

}

string search(node* head,string s)
{
    for(int i=0;i<s.size();i++)
    {
        int id=s[i]-'a';
        if(head->ar[id]==NULL)
        {
            return "-1";
        }
        head=head->ar[id];
    }
    return head->ss;


}

int main()
{
    int n;
     node* head=new node();
    cin>>n;
    string ss;
    unordered_map<string,int>mp;
    for(int i=1;i<=n;i++)
    {
        cin>>ss;
        int ln=ss.size();
        mp[ss]++;
        insert(head,ss,mp[ss]);
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        string ss;
        cin>>ss;
        int ln=ss.size();
        string ans=search(head,ss);
        if(ans=="-1")
        {
        cout<<"Case "<<i<<": "<<ans<<endl;
        }
        else
        {
        cout<<"Case "<<i<<": "<<ans<<" "<<mp[ans]<<endl;
        }
    }

}
