#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
vector<int>v;
int n;
vector<int>ans;
void gen_lucky_num(int num)
{
    if(num>1e12)
        return;
    if(num)
        ans.pb(num);
    gen_lucky_num(num*10+4);
    gen_lucky_num(num*10+7);
}
void gen(int pos,int num)
{
    if(num>1)
        ans.pb(num);
    if(pos==n)
        return;
    int x=num*ans[pos];
    if(x>1e12 || x<=0)
        return;
    gen(pos,x);
    gen(pos+1,num);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    gen_lucky_num(0);

    n=ans.size();

    sort(ans.begin(),ans.end());
    gen(0,1);
    sort(ans.begin(),ans.end());
    auto x=unique( ans.begin(), ans.end() );
    ans.erase(x, ans.end() );
    int t;
    cin>>t;
    int tc=0;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int x=upper_bound(ans.begin(),ans.end(),b)-ans.begin();
        int y=lower_bound(ans.begin(),ans.end(),a)-ans.begin();
        cout<<"Case "<<++tc<<": ";
        cout<<x-y<<endl;
    }
}
