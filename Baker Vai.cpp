/**Failing is always better than never trying*/
/**Winners never quit and quitters never win.*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define endl '\n'
int grid[105][105];
///c2 will always be constant for every triplet of (r1,c1,r2).....
int dp[105][105][105];
int n,m;
int solve(int r1,int c1,int r2,int c2)
{
    if(r1==r2 && c1==c2) return grid[r1][c1];
    if(r1>=n || r2>=n || c1>=m || c2>=m) return 0;
    int &ans=dp[r1][c1][r2];
    if(ans!=-1) return ans;
    int add=grid[r1][c1]+grid[r2][c2];
    ans=max(ans,solve(r1+1,c1,r2+1,c2)+add);
    ans=max(ans,solve(r1+1,c1,r2,c2+1)+add);
    ans=max(ans,solve(r1,c1+1,r2+1,c2)+add);
    ans=max(ans,solve(r1,c1+1,r2,c2+1)+add);
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int tc=0;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
               cin>>grid[i][j];
        memset(dp,-1,sizeof dp);
        int ans=solve(0,1,1,0)+grid[0][0];
        cout<<"Case "<<++tc<<": ";
        cout<<ans<<endl;
    }
}
///Debug tips : Look for corner logic that is not handled.
