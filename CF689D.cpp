#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],b[200005],sta[200005][25],stb[200005][25];
ll qmax(ll l,ll r){ll k=__lg(r-l+1);return max(sta[l][k],sta[r-(1<<k)+1][k]);}
ll qmin(ll l,ll r){ll k=__lg(r-l+1);return min(stb[l][k],stb[r-(1<<k)+1][k]);}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        sta[i][0]=a[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>b[i];
        stb[i][0]=b[i];
    }
    for(ll k=1;k<=20;k++)
        for(ll i=1;i+(1<<k)-1<=n;i++){
            sta[i][k]=max(sta[i][k-1],sta[i+(1<<(k-1))][k-1]);
            stb[i][k]=min(stb[i][k-1],stb[i+(1<<(k-1))][k-1]);
    }
    ll ans=0;
    for(ll l=1;l<=n;l++){
        ll L=l,R=n,rmin=n+1,rmax=l-1;
        while(L<=R){
            ll mid=(L+R)/2;
            if(qmax(l,mid)>=qmin(l,mid))
                rmin=mid,R=mid-1;
            else
                L=mid+1;
        }
        L=l,R=n;
        while(L<=R){
            ll mid=(L+R)/2;
            if(qmax(l,mid)<=qmin(l,mid))
                rmax=mid,L=mid+1;
            else
                R=mid-1;
        }
        if(rmin<=rmax)ans+=rmax-rmin+1;
    }
    cout<<ans;
}