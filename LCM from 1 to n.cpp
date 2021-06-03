#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, greater<T>,rb_tree_tag, tree_order_statistics_node_update>;
//#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
const int mx=1e8+9;
// int p=(1LL<<32);
bitset<mx>mark;
vector<unsigned int>primes;
unsigned int mult[5761455+6];
void sieve(int n)
{
    for(int i=4; i<=n; i+=2) mark[i]=1;
    for(int i=3; i<=n; i++)
    {
        if(mark[i]) continue;
        if(i<=sqrt(n))
        for(int j=i*i; j<=n; j+=i*2)
        {
            mark[j]=1;
        }
    }
    for(int i=2; i<=n; i++)
        {
            if(mark[i]==0)
            {
                primes.pb(i);
            }
        }
}
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     sieve(100000000);
     int sz=primes.size();
     mult[0]=2;
     for(int i=1; i<sz; i++)
        {
         mult[i]=(mult[i-1]*primes[i]);
        }
        int t;
        cin>>t;
        int tc=0;
        while(t--)
        {
            int n;
            cin>>n;
            int x=sqrt(n);
            int vis[x+5];
            memset(vis,0,sizeof vis);
            for(int i=2; i<=x; i++)
            {
                if(vis[i]) continue;
                for(int j=i*2; j<=x; j+=i)
                    vis[j]=1;
            }
            int idx=upper_bound(primes.begin(),primes.end(),n)-primes.begin();
            --idx;
        unsigned   int ans=mult[idx];
            for(int i=2; i<=x; i++)
            {
                if(vis[i]) continue;
                int y=n;
                int cnt=0;
                while(y>=i)
                {
                    y=y/i;
                    ++cnt;
                }

                ans=(ans*pow(i,cnt-1));
            }
            cout<<"Case "<<++tc<<": ";
           cout<<ans<<endl;
        }
}
