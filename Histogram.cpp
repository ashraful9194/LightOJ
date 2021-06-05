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
int a[30005];
int mn_idx[150005];
int n;
void init(int node,int l,int r)
{
    if(l==r)
    {
        mn_idx[node]=l;
        return;
    }
    int lft=node*2;
    int rt=node*2+1;
    int mid=(l+r)/2;
    init(lft,l,mid);
    init(rt,mid+1,r);
   if(a[mn_idx[lft]]<a[mn_idx[rt]]) mn_idx[node]=mn_idx[lft];
   else mn_idx[node]=mn_idx[rt];
}
int query(int node,int l,int r,int b,int e)
{
    if(l>=b && r<=e) return mn_idx[node];
    if(r<b || l>e) return  -1;
    int lft=node*2;
    int rt=lft+1;
    int mid=(l+r)/2;
   int idx1= query(lft,l,mid,b,e);
   int idx2= query(rt,mid+1,r,b,e);
   if(idx1==-1) return idx2;
   else if(idx2==-1) return idx1;
   else if(a[idx1]>a[idx2]) return idx2;
   else return idx1;
}
int ans;
///Divide and conquer O(n)....take the minimum value  value index or, check left and right....
void find_max_area(int l,int r)
{
    if(l>r) return;
    int idx=query(1,1,n,l,r);///mn idx
    ans=max(ans,a[idx]*(r-l+1));
    find_max_area(l,idx-1);
    find_max_area(idx+1,r);
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
         cin>>n;
         for(int i=1; i<=n; i++)
            cin>>a[i];
          init(1,1,n);
         ans=0;
         find_max_area(1,n);
         cout<<"Case "<<++tc<<": ";
         cout<<ans<<endl;
     }
}

