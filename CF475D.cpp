#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,a[100005],q;
map<ll,ll>omp,ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        map<ll,ll>nmp;
        for(auto [og,cnt]:omp){
            ll ng=__gcd(og,a[i]);
            nmp[ng]+=cnt;
        }
        nmp[a[i]]++;
        for(auto [g,cnt]:nmp){
            ans[g]+=cnt;
        }
        omp=nmp;
    }
    cin>>q;
    for(ll i=1;i<=q;i++){
        ll t;
        cin>>t;
        cout<<ans[t]<<"\n";
    }
    return 0;
}