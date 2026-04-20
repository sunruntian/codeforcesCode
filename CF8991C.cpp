#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,q,ec,pc,fa[500005],sz[500005];
struct E{ll u,v,w;}e[500005];
struct Q{ll u,v,w,id;}p[500005];
bool ans[500005];
ll sx[500005],sy[500005],stop;
bool szb[500005];
ll find(ll x){while(fa[x]!=x)x=fa[x];return x;}
void merge(ll x,ll y){
    x=find(x),y=find(y);
    if(x==y){sx[++stop]=0;sy[stop]=0;szb[stop]=0;return;}
    if(sz[x]<sz[y])swap(x,y);
    sx[++stop]=x;sy[stop]=y;szb[stop]=(sz[x]==sz[y]);
    fa[y]=x;if(sz[x]==sz[y])sz[x]++;
}
void rb(ll k){
    while(k--){
        ll x=sx[stop],y=sy[stop];
        bool z=szb[stop];stop--;
        if(x)fa[y]=y,sz[x]-=z;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
    cin>>q;
    for(ll i=1;i<=q;i++){
        ll k,x;cin>>k;
        while(k--)cin>>x,p[++pc]={e[x].u,e[x].v,e[x].w,i};
    }
    sort(e+1,e+m+1,[](E a,E b){return a.w<b.w;});
    sort(p+1,p+pc+1,[](Q a,Q b){return a.w==b.w?a.id<b.id:a.w<b.w;});
    for(ll i=1;i<=n;i++)fa[i]=i,sz[i]=1;
    ll pos=1;
    for(ll i=1;i<=pc;){
        while(pos<=m&&e[pos].w<p[i].w)merge(e[pos].u,e[pos].v),pos++;
        ll j=i;
        while(j<=pc&&p[j].w==p[i].w&&p[j].id==p[i].id){
            if(find(p[j].u)==find(p[j].v))ans[p[j].id]=1;
            merge(p[j].u,p[j].v);j++;
        }
        rb(j-i);i=j;
    }
    for(ll i=1;i<=q;i++)cout<<(ans[i]?"NO\n":"YES\n");
}