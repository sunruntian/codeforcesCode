#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,k,ne[40][100005],mn[40][100005],sum[40][100005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    memset(mn,0x3f,sizeof mn);
    for(ll i=1;i<=n;i++){
        cin>>ne[0][i];
        ne[0][i]++;
    }
    for(ll i=1;i<=n;i++){cin>>mn[0][i];sum[0][i]=mn[0][i];}
    for(ll j=1;j<=40;j++){
        for(ll i=1;i<=n;i++){
            ne[j][i]=ne[j-1][ne[j-1][i]];
            mn[j][i]=min(mn[j-1][i],mn[j-1][ne[j-1][i]]);
            sum[j][i]=sum[j-1][i]+sum[j-1][ne[j-1][i]];
        }
    }
    for(ll j=1;j<=n;j++){
		ll ans=0,minn=1e18;
        ll l=j,r=k;
		for(ll i=40;i>=0;i--)
			if(1ll<<i<=r){
                ans+=sum[i][l];
                minn=min(minn,mn[i][l]);
                r-=1ll<<i;
                l=ne[i][l];
            }
        cout<<ans<<" "<<minn<<"\n";
    }
    return 0;
}