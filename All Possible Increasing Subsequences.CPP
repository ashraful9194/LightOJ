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
const int p=1e9+7;
int n;
vector<pii>v;
int treee[400005];
struct cmp{
bool operator()(const pii &a,const pii &b)
{
    if(a.first!=b.first) return a.first<b.first;
    else return a.second>b.second;
}
};
int query(int node,int l,int r,int b,int e)
{
    if(r<b || l>e) return 0;
    if(l>=b && r<=e) return treee[node];
    int lft=node*2;
    int rt=lft+1;
    int mid=(l+r)/2;
    int x=query(lft,l,mid,b,e);
    int y=query(rt,mid+1,r,b,e);
    return (x+y)%p;
}
void update(int node,int l,int r,int idx,int val)
{
    if(l>idx || r<idx) return;
    if(l==r && l==idx)
        {
            treee[node]=val;
            return;
        }
        int lft=2*node;
        int rt=lft+1;
        int mid=(l+r)/2;
        update(lft,l,mid,idx,val);
        update(rt,mid+1,r,idx,val);
        treee[node]=(treee[lft]+treee[rt])%p;
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
         v.clear();
         memset(treee,0,sizeof treee);
         cin>>n;
         for(int i=1; i<=n; i++)
         {
             int x;
             cin>>x;
             v.pb({x,i});
         }
         sort(v.begin(),v.end(),cmp());
         int ans=0;
         for(auto i:v)
         {
             int idx=i.second;
             int cnt=query(1,1,n,1,idx);
             update(1,1,n,idx,cnt+1);
         }
         cout<<"Case "<<++tc<<": ";
         cout<<treee[1]<<endl;
     }
}

