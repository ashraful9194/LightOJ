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
vector<int>primes;
const int mx=1e6+8;
bitset<mx>mark;
void sieve(int n)
{
    primes.pb(2);
    for(int i=4; i<=n; i+=2) mark[i]=1;
    for(int i=3; i<=n; i++)
    {
        if(mark[i]) continue;
        primes.pb(i);
        if(i*i<=n)
        for(int j=i*i; j<=n; j+=i*2)
            mark[j]=1;
    }
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     sieve(1000000);

     int t;
     cin>>t;
     int tc=0;
     while(t--)
     {
         int a,b,l;
         cin>>a>>b>>l;
         int lcm=(a*b)/(__gcd(a,b));
         cout<<"Case "<<++tc<<": ";
         if(l%lcm)
         {
             cout<<"impossible"<<endl;
             continue;
         }
         int need=l/lcm;
         int temp=need;
         int c=1;
         for(auto i:primes)
         {
           if(temp%i) continue;
             while(temp%i==0)
             {
                 temp/=i;
                 c=c*i;
             }
             while(lcm%i==0)
             {
                 lcm/=i;
                 c=c*i;
             }
         }
         if(temp>1) c=c*temp;
         cout<<c<<endl;
     }
}
