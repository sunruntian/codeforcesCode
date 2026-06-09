#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,q;
ll p[200005],a[200005];
ll nxt[200005];
ll lst[200005];
ll to[200005];
ll jp[200005][25];
ll ed[200005];
ll be[200005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>q;
    for(ll i=1;i<=n;i++){
        cin>>p[i];
    }
    for(ll i=1;i<=m;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        if(i<n){
            nxt[p[i]]=p[i+1];
        }else{
            nxt[p[i]]=p[1];
        }
    }
    memset(lst,0x3f,sizeof lst);
    for(ll i=m;i>=1;i--){
        ll t=nxt[a[i]];
        to[i]=lst[t];
        lst[a[i]]=i;
        jp[i][0]=to[i];
    }
    for(ll i=1;i<=20;i++){
        for(ll j=1;j<=m;j++){
            ll t=jp[j][i-1];
            if(t>m){
                jp[j][i]=lst[0];
            }else{
                jp[j][i]=jp[t][i-1];
            }
        }
    }
    for(ll i=1;i<=m;i++){
        ll t=i;
        ll tt=n-1;
        for(ll j=20;j>=0;j--){
            if(tt&(1ll<<j)){
                t=jp[t][j];
                if(t>=lst[0]){
                    break;
                }
            }
        }
        ed[i]=t;
    }
    be[m+1]=lst[0];
    for(ll i=m;i>=1;i--){
        be[i]=min(be[i+1],ed[i]);
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<(be[l]<=r);
    }
    return 0;
}