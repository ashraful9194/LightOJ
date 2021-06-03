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
const int mx=1e7+9;
bitset<mx>mark;
vector<int>primes;
void sieve(int n)
{
    primes.pb(2);
    for(int i=4; i<=n; i+=2) mark[i]=1;
    for(int i=3; i<=n; i++)
    {
        if(mark[i]) continue;
        primes.pb(i);
        if(i<=sqrt(n))
        for(int j=i*i; j<=n; j+=i)
            mark[j]=1;
    }
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     sieve(10000000);
    // cout<<primes.size()<<endl;
     int t;
     cin>>t;
     int tc=0;

     while(t--)
     {
         int n;
         cin>>n;
         int ans=1;
         for(auto i:primes)
         {
               if(i*i>n) break;
               int cnt=0;
               while(n%i==0)
               {
                   n=n/i;
                   ++cnt;
               }
               ans=ans*(2*cnt+1);
         }
         if(n>1) ans=ans*3;
         ans=(ans+1)/2;
         cout<<"Case "<<++tc<<": ";
         cout<<ans<<endl;
     }

}

