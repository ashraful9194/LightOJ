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
int X[]= {-1,1,0,0};
int Y[]= {0,0,1,-1};
const int mx=1e5;
int n,q;
int segtree[4*mx+5];
int Lazy[4*mx+5];

void LazYPropagrate(int node,int l,int r)
{
    segtree[node]=Lazy[node]*(r-l+1);
    if(l!=r)
    {
        Lazy[2*node]=Lazy[node];
        Lazy[2*node+1]=Lazy[node];
    }
    Lazy[node]=-1;
}
void update(int node,int l,int r,int b,int e,int v)
{

    if(Lazy[node]!=-1)
        LazYPropagrate(node,l,r);
    if(l>e || r<b)
        return;
    if(l>=b && r<=e)
    {
        segtree[node]=v*(r-l+1);
        if(l!=r)
        {
            Lazy[2*node]=v;
            Lazy[2*node+1]=v;
        }
        return;
    }
    int lft=2*node;
    int rt=lft+1;
    int mid=(l+r)/2;
    update(lft,l,mid,b,e,v);
    update(rt,mid+1,r,b,e,v);
    segtree[node]=segtree[lft]+segtree[rt];
}
int query(int node,int l,int r,int b,int e)
{
    if(Lazy[node]!=-1)
        LazYPropagrate(node,l,r);
    if(l>e || r<b)
        return 0;
    if(l>=b && r<=e)
    {
        return segtree[node];
    }
    int lft=2*node;
    int rt=lft+1;
    int mid=(l+r)/2;
    int x=query(lft,l,mid,b,e);
    int y=query(rt,mid+1,r,b,e);
    return x+y;
}
void all_clear()
{
    for(int i=1; i<=4*n; i++)
    {
        segtree[i]=0;
        Lazy[i]=-1;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int tc=1;
    cin>>t;
    while(t--)
    {

        cin>>n>>q;
        all_clear();

        vector<pii>v;
        while(q--)
        {
            int op;
            cin>>op;
            if(op==1)
            {
                int i,j,v;
                cin>>i>>j>>v;
                ++i,++j;
                update(1,1,n,i,j,v);
            }
            else
            {
                int i,j;
                cin>>i>>j;
                ++i,++j;
                int x=query(1,1,n,i,j);
                int y=j-i+1;
                int g=__gcd(x,y);
                x/=g,y/=g;
                v.pb({x,y});
            }
        }
        cout<<"Case "<<tc++<<":"<<endl;
        for(auto i:v)
        {
            if(i.second==1) cout<<i.first<<endl;
            else cout<<i.first<<"/"<<i.second<<endl;
        }
    }
}
