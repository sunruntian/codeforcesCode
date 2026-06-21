#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string s[100005];
ll n;
ll ans;
map<ll,ll>cnt;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>s[i];
    for(ll i=1;i<=n;i++){
        ll t=0;
        for(auto c:s[i]){
            ll bit=c-'a';
            t=t^(1<<bit);
        }
        ans+=cnt[t];
        for(ll bit=0;bit<26;bit++){
            ans+=cnt[t^(1<<bit)];
        }
        cnt[t]++;
    }
    cout<<ans;
    return 0;
}//