#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,l,r;
ll dfs(ll x,ll p){
    //cerr<<x<<" "<<p<<"\n";别忘删除调试输出！！！！！！
    ll mid=1,t=x;
    while(t>>1ll){
        mid<<=1ll;
        t>>=1ll;
    }
    if(p<mid)return dfs(x/2,p);
    else if(p==mid)return x%2;
    else return dfs(x/2,p-mid);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>l>>r;
    ll ans=0;
    for(ll i=l;i<=r;i++)ans+=dfs(n,i);
    cout<<ans;
    return 0;
}