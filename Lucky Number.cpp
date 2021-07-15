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
const int mx=4e5;
int arr[mx*4+5];
int seg_tree[4*4*mx+5];
void init(int node,int b,int e)
{
    if(b==e)
    {
        arr[b]=1;
        seg_tree[node]=arr[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    seg_tree[node]=seg_tree[left]+seg_tree[right];
}
void update(int node,int b,int e,int cnt)
{

    if(b==e)
    {

        arr[b]=0;
        seg_tree[node]=0;
        return;
    }

    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    if(seg_tree[left]>=cnt)
    {
         update(left,b,mid,cnt);
    }
    else
    {
         update(right,mid+1,e,cnt-seg_tree[left]);
    }
    seg_tree[node]=seg_tree[left]+seg_tree[right];
}
int query(int node,int b,int e,int cnt)
{

    if(b==e)
    {
        return b;
    }

    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    if(seg_tree[left]>=cnt)
    {
        return query(left,b,mid,cnt);
    }
    else
    {
        return query(right,mid+1,e,cnt-seg_tree[left]);
    }
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     init(1,1,mx*4);
     int a[5]={2,3,7};
     int x=4*mx;
     int occ=0;
     for(int i=2; i<=4*mx; i+=2)
     {
        update(1,1,4*mx,i-occ);
        ++occ;
     }
     x-=(x/2);
     for(int i=2; ; i++)
     {
          int num=query(1,1,4*mx,i);
          occ=0;
          if(num>x) break;
         for(int j=num; j<=x; j+=num)
            {
                update(1,1,4*mx,j-occ);
                ++occ;
            }
            x-=(x/num);
     }
     int t;
     cin>>t;
     int cnt=1;
     while(t--)
     {
         int n;
         cin>>n;
         cout<<"Case "<<cnt++<<": ";
         cout<<query(1,1,4*mx,n)<<endl;
     }
}
