#include<bits/stdc++.h>
using namespace std;
void merge(int ar[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++)
    {
        a[i]=ar[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i]=ar[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            ar[k]=a[i];
            k++;
            i++;
        }
        else{
        ar[k]=b[j];
        k++;
        j++;
    }

}

    while(i<n1)
    {
        ar[k]=a[i];
        k++;
        i++;

    }
    while(j<n2)
    {
        ar[k]=b[j];
        k++;
        j++;
    }
}
void merge_sort(int ar[],int l,int r)
{
  if(l<r)
  {


  int mid=(l+r)/2;
  merge_sort(ar,l,mid);
  merge_sort(ar,mid+1,r);
  merge(ar,l,mid,r);
  }


}
int main()
{
        int t;
        int n;
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        merge_sort(ar,0,n-1);
        for(int i=0;i<n;i++)
        {
            cout<<ar[i]<<" ";
        }
        cout<<endl;



}

