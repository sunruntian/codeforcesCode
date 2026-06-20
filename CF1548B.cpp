#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll d[200005];
ll st[25][200005];
ll a[200005];
ll n;
ll lrst(ll l,ll r){
    ll k=__lg(r-l+1);
    return __gcd(st[k][l],st[k][r-(1<<k)+1]);
}
bool check(ll x){
    if(x==1)return true;
    for(ll i=1;i<=n-x-1;i++){
        ll j=i+x-2;
        if(lrst(i,j)>1)return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll T;cin>>T;
    while(T--){
        cin>>n;
        for(ll i=1;i<=n;i++)cin>>a[i];
        if(n==1){
            cout<<1<<"\n";
            continue;
        }
        for(ll i=1;i<=n;i++)d[i]=llabs(a[i]-a[i-1]);
        for(ll i=1;i<=n;i++)st[0][i]=d[i];
        ll len=__lg(n);
        for(ll i=1;i<=len;i++){
            for(ll j=1;j+(1<<i)-1<=n;j++){
                st[i][j]=__gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
            }
        }
        ll l=1,r=n;
        while(l<r){
            ll mid=(l+r+1)>>1;
            if(check(mid))l=mid;
            else r=mid-1;
        }
        cout<<l<<"\n";
    }
    return 0;
}