#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, greater<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
int n,m;
int light[10];
int dp[10][1<<8][1<<8];
///Broken profile DP......
///If we do something on a particular place of a 2D grid
///then it will affect the adjecent positions
///Thats why we need to keep track of the mask of particular row or, column
///The mask itself is called broken profile.............
int solve(int pos,int curr_msk,int prev_msk)
{
    if(pos==n)
    {
        if(prev_msk==(1<<m)-1) return 0;
        else return 1e17;
    }
    int &ans=dp[pos][curr_msk][prev_msk];
    if(ans!=-1) return ans;
    int res=1e17;
    for(int i=0; i<(1<<m); i++)
    {
         int cnt=0;
         int row[3]={prev_msk,curr_msk,light[pos+1]};
         for(int j=0; j<m; j++)
         {
             if(!(i>>j &1)) continue;
             ///else toggle the curr_mask
             ++cnt;
             for(int k=0; k<3; k++) row[k]^=(1<<j);
             if(j-1>=0) for(int k=0; k<3; k++) row[k]^=(1<<(j-1));
             if(j+1<m) for(int k=0; k<3; k++) row[k]^=(1<<(j+1));
         }
         if(pos==0) res=min(res,solve(pos+1,row[2],row[1])+cnt);
         else
         {
             if(row[0]==(1<<m)-1) res=min(res,solve(pos+1,row[2],row[1])+cnt);
         }
    }
    return  ans=res;
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     for(int tc=1; tc<=t; tc++)
     {
         memset(dp,-1,sizeof dp);
         memset(light,0,sizeof light);
         cin>>n>>m;
         for(int i=0; i<n; i++)
         {
             string s;
             cin>>s;
             for(int j=0; j<m; j++)
                if(s[j]=='*') light[i]^=(1<<j);
         }
         int ans=solve(0,light[0],0);
         cout<<"Case "<<tc<<": ";
         if(ans>=1e17) cout<<"impossible"<<endl;
         else
         cout<<ans<<endl;

     }

}

