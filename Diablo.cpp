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
const int mx=100000+50000;
int segtree[4*mx+4];
int a[mx+5];
int sum[4*mx+5];
int n,q;
void init(int node,int l,int r,int idx)
{
    if(l>idx || r<idx) return;

    if(l==r)
    {
        segtree[node]=a[l];
        sum[node]=1;
        return;
    }
    int lft=2*node;
    int rt=lft+1;
    int mid=(l+r)/2;
    init(lft,l,mid,idx);
    init(rt,mid+1,r,idx);
    sum[node]=sum[lft]+sum[rt];
}
int query(int node,int l,int r,int idx)
{
    --sum[node];
    if(l==r)
    {
        return  segtree[node];
    }
    int lft=2*node;
    int rt=lft+1;
    int mid=(l+r)/2;
    if(sum[lft]>=idx)///then go to left
    {
        return query(lft,l,mid,idx);
    }
    else ///goto right
    {
        return query(rt,mid+1,r,idx-sum[lft]);
    }
}
int32_t main()
{
    ///Trivial segment tree problem.....Just storing the number of elements covered by every node
    ///will do......
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     int tc=0;
     while(t--)
     {
         memset(sum,0,sizeof sum);
         cin>>n>>q;
         for(int i=1; i<=n; i++)
         {
             cin>>a[i];
             init(1,1,mx,i);
         }
        cout<<"Case "<<++tc<<":"<<endl;
         while(q--)
         {
             char ch;
             int x;
             cin>>ch>>x;
             if(ch=='a')
             {
                 a[++n]=x;
                 init(1,1,mx,n);
             }
             else
             {
                 if(sum[1]<x)
                 {
                     cout<<"none"<<endl;
                 }
                 else
                 cout<<query(1,1,mx,x)<<endl;
             }
         }
     }

}

