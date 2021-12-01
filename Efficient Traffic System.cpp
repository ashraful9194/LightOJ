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
const int mx=2e4+5;
vector<int>adj[mx];
vector<int>v[mx];
int indeg[mx],outdeg[mx];

int vis[mx];
stack<int>st;
int on_stack[mx];
int in[mx];
int lo[mx];
int tme;
int cnt;
int scc_num[mx];
int n,m;
int ind,outd,cc;
void dfs(int node)
{
    in[node]=lo[node]=++tme;
    vis[node]=1;
    on_stack[node]=1;
    st.push(node);
    for(auto son:adj[node])
    {
        if(on_stack[son] && vis[son])
        {
            lo[node]=min(lo[node],in[son]);
        }
        else if(!vis[son])
        {
            dfs(son);
            if(on_stack[son])
                lo[node]=min(lo[node],lo[son]);
        }
    }
    if(in[node]==lo[node])
    {
        ++cnt;
        while(1)
        {
            int x=st.top();
            st.pop();
            scc_num[x]=cnt;
            on_stack[x]=0;
            if(x==node)
                break;
        }
    }
}
void dfs2(int node)
{
    vis[node]=1;
    ind+=indeg[node];
    outd+=outdeg[node];
    for(auto son:adj[node])
    {
        if(vis[son])
            continue;
        dfs2(son);
    }
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        cin>>n>>m;
        cnt=0;
        tme=0;
        for(int i=1; i<=n; i++)
        {
            adj[i].clear();
            v[i].clear();
            vis[i]=0;
            scc_num[i]=0;
            on_stack[i]=0;
            indeg[i]=0;
            outdeg[i]=0;
        }
        while(!st.empty())
            st.pop();

        for(int i=0; i<m; i++)
        {
            int x,y;
            cin>>x>>y;
            adj[x].pb(y);
        }
        for(int i=1; i<=n; i++)
        {
            if(vis[i])
                continue;
            dfs(i);
        }
        ///Graph condensation
        for(int i=1; i<=n; i++)
        {
            for(auto j:adj[i])
            {
                if(scc_num[i]==scc_num[j])
                    continue;

                indeg[scc_num[j]]=1;///entered
                outdeg[scc_num[i]]=1;///gone
            }
        }
        int ans=0;
        ind=0;outd=0;
        for(int i=1; i<=cnt; i++)
        {
            if(!indeg[i])///need ingoing edge
                ++ind;
            if(!outdeg[i])///need outgoing edge
                ++outd;
        }
        cout<<"Case "<<tc<<": ";
        if(cnt==1) cout<<0<<endl;
        else
        cout<<max(ind,outd)<<endl;
    }
}
