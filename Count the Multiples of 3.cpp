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
int n,q;
const int mx=100000;
int Lazy[4*mx+5];
int segtree[4*mx+5][5];
void LazYPropagrate(int node,int l,int r)
{
    if(Lazy[node]==1)
    {
         segtree[node][2]=segtree[node][1];
         segtree[node][1]=segtree[node][0];
         segtree[node][0]=(r-l+1)-(segtree[node][1]+segtree[node][2]);
    }
    if(Lazy[node]==2)
    {
         segtree[node][1]=segtree[node][2];
         segtree[node][2]=segtree[node][0];
         segtree[node][0]=(r-l+1)-(segtree[node][1]+segtree[node][2]);
    }
    if(l!=r)
    {
        Lazy[2*node]+=Lazy[node];
        Lazy[2*node+1]+=Lazy[node];
        Lazy[2*node]%=3;
        Lazy[2*node+1]%=3;
    }
    Lazy[node]=0;
}
void init(int node,int l,int r)
{
    Lazy[node]=0;
    if(l>r) return;
    if(l==r)
    {
        segtree[node][0]=1;
        return;
    }
    int lft=2*node;
    int rt=lft+1;
    int mid=(l+r)/2;
    init(lft,l,mid);
    init(rt,mid+1,r);
    segtree[node][0]=segtree[lft][0]+segtree[rt][0];
}
void update(int node,int l,int r,int b,int e)
{
    if(Lazy[node]) LazYPropagrate(node,l,r);
    if(l>e || r<b) return;
    if(l>=b && r<=e)
    {
        if(l!=r)
        {
             ++Lazy[2*node];
             ++Lazy[2*node+1];
             Lazy[2*node]%=3;
             Lazy[2*node+1]%=3;
        }
        segtree[node][2]=segtree[node][1];
        segtree[node][1]=segtree[node][0];
        segtree[node][0]=(r-l+1)-(segtree[node][1]+segtree[node][2]);
        return;
    }
    int lft=2*node;
    int rt=lft+1;
    int mid=(l+r)/2;
    update(lft,l,mid,b,e);
    update(rt,mid+1,r,b,e);
    for(int i=0; i<3; i++)
    {
         segtree[node][i]=segtree[lft][i]+segtree[rt][i];
    }
}
int query(int node,int l,int r,int b,int e)
{
     if(Lazy[node]) LazYPropagrate(node,l,r);
    if(l>e || r<b) return 0;
    if(l>=b && r<=e)
    {
       return segtree[node][0];
    }
    int lft=2*node;
    int rt=lft+1;
    int mid=(l+r)/2;
    int x=query(lft,l,mid,b,e);
    int y=query(rt,mid+1,r,b,e);
      for(int i=0; i<3; i++)
    {
         segtree[node][i]=segtree[lft][i]+segtree[rt][i];
    }
   return x+y;
}
int32_t main()
{
    /*
    If we update some node then just update its lazy value and not go further.
    If we encounter lazy value that is not 0 in a node then just update its summation and set the lazy as 0
    and update the lazy value of two children of that node....
    */
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     int tc=0;
     while(t--)
     {
         memset(Lazy,0,sizeof Lazy);
         memset(segtree,0,sizeof segtree);
         cin>>n>>q;
         cout<<"Case "<<++tc<<":"<<endl;
         init(1,0,n-1);
         while(q--)
         {
             int op,i,j;
             cin>>op>>i>>j;
             if(op==0)
             {
                 update(1,0,n-1,i,j);
             }
             else
             {
                 cout<<query(1,0,n-1,i,j)<<endl;
             }
         }
     }

}

