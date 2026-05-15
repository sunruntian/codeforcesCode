#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,k;
ll t[3005];
vector<ll>a[3005];
ll ans;
ll s[3005];
void solve(ll l,ll r,vector<ll> dp){
    if(l==r){
        ll sum=0;
        for(ll i=0;i<=min(t[l],k);i++){
            sum+=a[l][i];
            ans=max(ans,dp[k-i]+sum);
        }
        return;
    }
    vector<ll>ldp=dp,rdp=dp;
    ll mid=(l+r)/2;
    for(ll i=l;i<=mid;i++){
        for(ll j=k;j>=t[i];j--){
            ldp[j]=max(ldp[j],ldp[j-t[i]]+s[i]);
        }
    }
    solve(mid+1,r,ldp);
    for(ll i=mid+1;i<=r;i++){
        for(ll j=k;j>=t[i];j--){
            rdp[j]=max(rdp[j],rdp[j-t[i]]+s[i]);
        }
    }
    solve(l,mid,rdp);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>t[i];
        a[i].push_back(0);
        for(ll j=1;j<=t[i];j++){
            ll x;cin>>x;
            a[i].push_back(x);
            s[i]+=x;
        }
    }
    solve(1,n,vector<ll>(k+1,0));
    cout<<ans;
    return 0;
}
