#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,a[10000005],b[10000005],c[35];
ll t;
ll posa,posb;
void dfs1(ll step,ll sum){
    if(step==t+1){
        a[++posa]=sum;
        return;
    }
    dfs1(step+1,(sum+c[step])%m);
    dfs1(step+1,sum);
}
void dfs2(ll step,ll sum){
    if(step==n+1){
        b[++posb]=sum;
        return;
    }
    dfs2(step+1,(sum+c[step])%m);
    dfs2(step+1,sum);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>c[i];
    t=n/2;
    //cerr<<"<=============>\n";
    dfs1(1,0);
    //cerr<<"<=============>\n";
    dfs2(n/2+1,0);
    //cerr<<"<=============>\n";
    sort(a+1,a+posa+1);
    sort(b+1,b+posb+1);
    ll pos=posb;
    ll ans=0;
    //cerr<<"<=============>\n";
    for(ll i=1;i<=posa;i++){
        while(pos>0&&a[i]+b[pos]>=m)pos--;
        if(pos>0)ans=max(ans,a[i]+b[pos]);
        else ans=max(ans,a[i]+b[posb]);
    }
    //cerr<<"<=============>\n";
    cout<<ans<<"\n";
    return 0;  
}