#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m;
ll a[200005];
ll u[200005],v[200005],w[200005];
ll id=0;ll minn=1e15;
struct node{
    ll u,v,w;
    bool operator<(const node &a)const{
        return w<a.w;
    }
};
vector<node>e;
//ll cnt;

ll fa[200005];
ll ans,k;
ll find(ll x){
	if(fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
}
void kruskal(){
	for(ll i=1;i<=n;i++){
		fa[i]=i;
	}
	for(ll i=0;i<e.size();i++){
		ll x=find(e[i].u),y=find(e[i].v);
		if(x!=y) {
			ans+=e[i].w;
			fa[x]=y;
			if(++k==n-1){
				break;
			}
		}
	}
	return;
}
    
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){cin>>a[i];if(a[i]<minn)minn=a[i],id=i;}
    for(ll i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
    for(ll i=1;i<=n;i++){
        e.push_back({id,i,a[i]+minn});
    }
    for(ll i=1;i<=m;i++){
        e.push_back({u[i],v[i],w[i]});
    }
    sort(e.begin(),e.end());
    kruskal();
    cout<<ans;
    return 0;
}