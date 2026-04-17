#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
ll a[2000005],b[2000005]; 
ll d[4000005];
ll s[4000005];
ll ans[2000005]; 
unordered_map<ll,ll>mp;
ll t[4000005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(ll i=1;i<=n;i++){
        t[i]=a[i];
        t[i+n]=b[i]+1;
    }
    t[2*n+1]=1e15;
    sort(t+1,t+2*n+2);
    ll pos=unique(t+1,t+2*n+2)-t-1;
    for(ll i=1;i<=pos;i++){
        mp[t[i]]=i;
    }
    for(ll i=1;i<=n;i++){
        d[mp[a[i]]]++;
        d[mp[b[i]+1]]--;
    }
    for(ll i=1;i<pos;i++){
        s[i]=s[i-1]+d[i];
        //cout<<s[i]<<" ";
        ans[s[i]]+=(t[i+1]-t[i]);
    }
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}