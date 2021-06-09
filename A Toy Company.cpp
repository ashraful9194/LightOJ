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
int X[]={0,0,0,0,1,-1};
int Y[]={0,0,1,-1,0,0};
int Z[]={1,-1,0,0,0,0};
unordered_map<string,int>vis;
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     int tc=0;
     while(t--)
     {
         string a,b;
         cin>>a>>b;
         int n;
         cin>>n;
         vis.clear();
         for(int i=0; i<n; i++)
         {
             string x,y,z;
             cin>>x>>y>>z;
             for(auto i:x)
             {
                 string s;
                 s.pb(i);
                 for(auto j:y)
                 {
                     s.pb(j);
                     for(auto k:z)
                     {
                         s.pb(k);
                         vis[s]=1e10;
                         s.pop_back();
                     }
                     s.pop_back();
                 }
                 s.pop_back();
             }
         }
         cout<<"Case "<<++tc<<": ";
         if(vis[a] || vis[b])
         {
             cout<<-1<<endl;
             continue;
         }
         if(a==b)
         {
             cout<<0<<endl;
             continue;
         }
         queue<string>q;
         q.push(a);
         int ok=0;
         while(!q.empty())
         {
             string s=q.front();
             q.pop();
             for(int i=0; i<6; i++)
             {
                 string str;
                 str.pb('a'+(s[0]-'a'+X[i]+26)%26);
                 str.pb('a'+(s[1]-'a'+Y[i]+26)%26);
                 str.pb('a'+(s[2]-'a'+Z[i]+26)%26);
                 if(vis[str]) continue;
                 vis[str]=vis[s]+1;
                 if(str==b)
                 {
                     ok=1;
                     break;
                 }
               q.push(str);
             }
             if(ok) break;
         }
         if(!ok) cout<<-1<<endl;
         else cout<<vis[b]<<endl;
     }
}
