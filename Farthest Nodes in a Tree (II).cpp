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
int dist[30006];
int ans[30005];
int n;
vector<pii>adj[30005];
void dfs(int node,int par)
{
    for(auto i:adj[node])
    {
        int son=i.first;
        int val=i.second;
        if(son==par) continue;
        dist[son]=dist[node]+val;
        dfs(son,node);

    }
}
int32_t main()
{
     ///The farthest node from every node will be one of the two nodes of the diameter..........

     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     int tc=0;
     while(t--)
     {
         cin>>n;
         for(int i=0; i<=n; i++)
            adj[i].clear();
        memset(dist,0,sizeof dist);
         for(int i=0; i<n-1; i++)
         {
             int x,y,z;
             cin>>x>>y>>z;
             adj[x].pb({y,z});
             adj[y].pb({x,z});
         }
         dfs(0,-1);
         int node;
         int mx=0;
         for(int i=0; i<n; i++)
         {
             if(dist[i]>mx)
             {
                 mx=dist[i];
                 node=i;
             }
         }
        memset(dist,0,sizeof dist);
         dfs(node,-1);
         mx=0;
         for(int i=0; i<n; i++)
           {
               ans[i]=dist[i];
           }
              for(int i=0; i<n; i++)
         {
             if(dist[i]>mx)
             {
                 mx=dist[i];
                 node=i;
             }
         }
         memset(dist,0,sizeof dist);
         dfs(node,-1);
           cout<<"Case "<<++tc<<":"<<endl;
             for(int i=0; i<n; i++)
           {
               ans[i]=max(ans[i],dist[i]);
               cout<<ans[i]<<endl;
           }


     }

}


