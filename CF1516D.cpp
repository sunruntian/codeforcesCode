#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,q;
ll a[100005];
ll lst[100005],f[20][100005];
ll nxt[100005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    nxt[n+1]=n+1;
    memset(lst,0x3f,sizeof lst);
    for(ll i=0;i<=18;i++)
        for(ll j=1;j<=n+1;j++)
            f[i][j]=n+1;
    for(ll i=n;i>=1;i--){
        ll r=nxt[i+1];
        ll t=a[i];
        for(ll j=2;j*j<=t;j++){
            if(t%j==0){
                if(lst[j]<=n)
                    r=min(r,lst[j]-1);
                lst[j]=i;
            }
            while(t%j==0)
                t/=j;
        }
        
        if(t>1){
            if(lst[t]<=n)
                r=min(r,lst[t]-1);
            lst[t]=i;
        }
        f[0][i]=r+1;
        nxt[i]=r;
    }
    for(ll i=1;i<=18;i++)
        for(ll j=1;j<=n;j++)
            if(f[i-1][j]<=n+1)
                f[i][j]=f[i-1][f[i-1][j]];
    while(q--){
		ll l,r;cin>>l>>r;
		if(l>r)swap(l,r);
		ll ans=0;
		for(ll i=18;i>=0;i--)
			if(f[i][l]<=r)l=f[i][l],ans+=1ll<<i;
		cout<<ans+1<<'\n';
	}
    return 0;
}