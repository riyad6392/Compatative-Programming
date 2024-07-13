#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>vt;
void generate(vector<int> &subset,int i, vector<int>& nums)
{
    if(i==nums.size())
    {
        vt.push_back(subset);
        return;
    }
  generate(subset,i+1,nums);

  subset.push_back(nums[i]);
  generate(subset,i+1,nums);
  subset.pop_back();


}
int main()
{
    int n;
    cin>>n;
   vector<int>nums(n);
   for(int i=0;i<n;i++)
   {
       cin>>nums[i];
   }
   vector<int>emt;
   generate(emt,0,nums);
   for(auto a: vt)
   {
       for(auto b: a)
       {
           cout<<b<<" ";
       }
       cout<<endl;
   }

}
