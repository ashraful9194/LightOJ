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
int solve(string s)
{
    int sum=0;
    for(int i=0; i<s.size(); i++)
    {
        sum=sum*10+(s[i]-'0');
        sum%=9;
    }
    return sum;
}
int solve2(string s)
{
    int sum=0;
    for(int i=0; i<s.size(); i++)
    {
        sum=sum*10+(s[i]-'0');
        sum%=6;
    }
    return sum;
}
int power(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=res*a;
        b=b/2;
        a=(a*a);
    }
    return res%9;
}
int32_t main()
{
    ///It can be proven that the repeated digit sum of N is  N%9 & if N%9==0 then ans is 9.
    ///so what we basically need to calculate a^b % 9.
    ///A less known fact is a^b ≡ a^(φ(M) + b mod φ(M)) (mod M), for any a, M and b ≥ log2(M).
    /// Using this and some case walk we can solve the problem.
    ///Here in this problem phi(9)=6..and log2(9)=3.....
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int tc=0;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        cout<<"Case "<<++tc<<": ";
        if(a=="0")
        {
            cout<<0<<endl;
            continue;
        }
        if(b=="0")
        {
            cout<<1<<endl;
            continue;
        }
        int x=solve(a);
        if(b=="1")
        {
            if(x==0)
                x=9;
            cout<<x<<endl;
            continue;
        }
        if(b=="2")
        {
            x=(x*x);
            x%=9;
            if(x==0)
                x=9;
            cout<<x<<endl;
            continue;
        }
        int y=solve2(b)+6;
        int ans=power(x,y);
        if(ans==0)
            ans=9;
        cout<<ans<<endl;
    }
}
