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
#define ull unsigned long long
ull phi[3000005];
ull ans[3000006];
void euler_phi(int n)
{
    phi[0]=0;
    phi[1]=1;
    for(int i=2; i<=n; i++) phi[i]=i;
    for(int i=2; i<=n; i++)
    {
        if(phi[i]!=i) continue;
        for(int j=i; j<=n; j+=i)
            phi[j]-=(phi[j]/(ull)i);
    }
}
void pre_calc(int n)
{
    int ok=0;
    for(int i=2; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i)
            {
                ans[j]+=((phi[i]*i)/2)*j;
                /*
                In Euler's totient function if n>2 then phi[n] is always even.
                Because for any k if gcd(n,k)=1 then also gcd(n,n-k)=1.
               So its obvious that value of phi[n] is always even.
               thats why we can divide by 2...........
                */
            }
    }
  /*
    for(int i=1; i<=n; i++)
       {
          ans[i]=(ans[i]*i)/2;
      }
 */
    for(int i=1; i<=n; i++)
       {
           ans[i]+=ans[i-1];
       }
}
int32_t main()
{
    /*
    
    https://forthright48.com/spoj-lcmsum-lcm-sum/
    
    SUM–n=LCM(1,n)+LCM(2,n)+…+LCM(n−1,n)  (eq1)
SUM–n=LCM(n−1,n)+LCM(n−2,n)+…+LCM(1,n) ( eq2 Add them )

2(SUM−n)=n^2/gcd(1,n)+n^2/gcd(2,n)+…n^2/gcd(n−1,n)
2(SUM−n)=∑n^2/gcd(i,n)  -->(i>=1 && i<n)
2(SUM−n)=n∑n/gcd(i,n)


2(SUM−n)=n∑d|n,d≠nϕ(nd)×nd  (but, nd is also a divisor of n )
2(SUM−n)=n∑d|n,d≠1ϕ(d)×d ( when d=1, we get ϕ(1)times1 )///Till now this is enough


2(SUM−n)=n(∑d|n(ϕ(d)×d)−1)
2(SUM−n)=n∑d|n(ϕ(d)×d)–n
2SUM–2n+n=n∑d|nϕ(d)×d
2SUM–n=n∑d|nϕ(d)×d

    */
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     euler_phi(3000000);
     pre_calc(3000000);
     int t;
     cin>>t;
     int tc=0;
     while(t--)
     {
         int n;
         cin>>n;
         cout<<"Case "<<++tc<<": ";
         cout<<ans[n]<<endl;
     }
}
