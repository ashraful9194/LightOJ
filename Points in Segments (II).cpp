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
const int mx=50000;
int n,q;
vector<pii>segs;
int points[mx+5];
vector<int>v;
int mini[4*mx+5],maxi[4*mx+5];
int ans[mx+4];
int res[mx+5];
struct cmp{
bool operator()(int a,int b)
{
     if(points[a]<=points[b])
        return  1;
     return 0;
}
};
void init(int node,int l,int r)
{
    if(l>r) return;
    if(l==r)
    {
        mini[node]=v[l];
        maxi[node]=v[l];
        return;
    }
    int lft=2*node;
    int rt=lft+1;
    int mid=(l+r)/2;
    init(lft,l,mid);
    init(rt,mid+1,r);
    if(points[mini[lft]]<=points[mini[rt]])
    {
        mini[node]=mini[lft];
    }
    else mini[node]=mini[rt];
      if(points[maxi[lft]]>=points[maxi[rt]])
    {
        maxi[node]=maxi[lft];
    }
    else maxi[node]=maxi[rt];
}
void query(int node,int l,int r,int b,int e)
{
    if(l>r) return;
    if(points[mini[node]]>e || points[maxi[node]]<b) return;
    if(points[mini[node]]>=b && points[maxi[node]]<=e)
    {
        ++ans[l];
        --ans[r+1];
        return;
    }
    int lft=2*node;
    int rt=lft+1;
    int mid=(l+r)/2;
    query(lft,l,mid,b,e);
    query(rt,mid+1,r,b,e);
}
int32_t main()
{
     ///just create a segment tree using those points and by iterating on segments find out
     ///on how many elements and in which range does it  contribute.
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     int tc=0;
     while(t--)
     {
         segs.clear();
         v.clear();
         memset(ans,0,sizeof ans);
         cin>>n>>q;
         for(int i=0; i<n; i++)
         {
             int x,y;
             cin>>x>>y;
             segs.pb({x,y});
         }
         for(int i=1; i<=q; i++)
         {
             v.pb(i);
             cin>>points[i];
         }
         sort(v.begin(),v.end(),cmp());
         init(1,0,q-1);
         for(auto i:segs)
         {
             int x=i.first,y=i.second;
             query(1,0,q-1,x,y);
         }
         int sum=0;
         for(int i=0; i<q; i++)
         {
             sum+=ans[i];
             ans[i]=sum;
             res[v[i]]=ans[i];
         }
         cout<<"Case "<<++tc<<":"<<endl;
         for(int i=1; i<=q; i++)
            cout<<res[i]<<endl;
     }
}
