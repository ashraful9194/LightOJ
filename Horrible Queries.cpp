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
struct lazy{
int sum,prop;
};
lazy segtree[4*mx+5];
void update(int node,int l,int r,int b,int e,int val)
{
    if(l>e || r<b) return;
    if(l>=b && r<=e)
    {
        segtree[node].prop+=val;
        return;
    }
    int lft=2*node;
    int rt=lft+1;
    int mid=(l+r)/2;
    update(lft,l,mid,b,e,val);
    update(rt,mid+1,r,b,e,val);
    segtree[node].sum=segtree[lft].sum+segtree[rt].sum+segtree[lft].prop*(mid-l+1)+segtree[rt].prop*(r-mid);
}
int query(int node,int l,int r,int b,int e,int s)
{
    if(l>e || r<b) return 0;
    if(l>=b && r<=e)
    {
        return segtree[node].sum+(segtree[node].prop+s)*(r-l+1);
    }
    int lft=2*node;
    int rt=lft+1;
    int mid=(l+r)/2;
   int x= query(lft,l,mid,b,e,s+segtree[node].prop);
   int y= query(rt,mid+1,r,b,e,s+segtree[node].prop);
   return  x+y;
}
int32_t main()
{
    /*
    In lazy propagation ,for update just add the value in the node as propagation and backtrack to
    previous node and also update the sum of prvious or parent node with childs' sum and propagation value*length

    For queries,while descending from the node just brag the value of its propagation sum and later
    while found the full segment just return the sum of that segment and (propagation sum+that segments propagation sum)*length.
    */
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     int tc=0;
     while(t--)
     {
         cin>>n>>q;
         cout<<"Case "<<++tc<<":"<<endl;
         for(int i=0; i<=4*mx; i++)
            segtree[i].prop=segtree[i].sum=0;
         while(q--)
         {
             int op,x,y,v;
             cin>>op;
             if(op==0)
             {
                 cin>>x>>y>>v;
                 update(1,0,n-1,x,y,v);
             }
             else
             {
                 cin>>x>>y;
                 cout<<query(1,0,n-1,x,y,0)<<endl;
             }
         }
     }

}

