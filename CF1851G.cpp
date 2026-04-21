#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll f[2000010],ht[2000010];
ll n,m;
ll Find(ll k){
    if(f[k]==k) return k;
    else{
        f[k]=Find(f[k]);
        return f[k];
	}
}
void Union(ll a,ll b){
	a=Find(a),b=Find(b);
	if(ht[a]>ht[b]) swap(a,b);
	ht[b]=max(ht[b],ht[a]+1);
	f[a]=b;
}
bool check(ll a,ll b){
	if(Find(a)==Find(b)) return true;
	return false;
}
struct Node{
    ll h,id;
};

Node d[2000010];
ll u[2000010],v[2000010];
struct query{
    ll a,b,e,id;
};
vector<ll>E[2000010];
query q[2000010];
ll que;
ll ans[2000010];
ll h[2000010];
void solve(){
    
    cin>>n>>m;
    for(ll i=1;i<=n;i++)E[i].clear();
    for(ll i=1;i<=n;i++)f[i]=i;
    for(ll i=1;i<=n;i++){cin>>h[i];d[i].h=h[i],d[i].id=i;}
    for(ll i=1;i<=m;i++){
        ll u,v;cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    cin>>que;
    for(ll i=1;i<=que;i++){
        cin>>q[i].a>>q[i].b>>q[i].e;q[i].id=i;
    }
    sort(d+1,d+n+1,[](Node a,Node b){return a.h<b.h;});
    sort(q+1,q+que+1,[](query a,query b){return a.e+h[a.a]<b.e+h[b.a];});
    ll pos=1;
    for(ll i=1;i<=que;i++){
        while(pos<=n&&d[pos].h<=q[i].e+h[q[i].a]){
            ll u=d[pos].id;
            for(auto v:E[u]){
                if(h[v]<=d[pos].h)Union(u,v);
            }
            pos++;
        }
        ans[q[i].id]=check(q[i].a,q[i].b);
    }
    for(ll i=1;i<=que;i++)if(ans[i])cout<<"YES\n";else cout<<"NO\n";
    return ;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}