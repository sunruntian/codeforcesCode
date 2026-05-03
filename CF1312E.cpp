#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,a[505],f[505][505],vis[505][505];
ll dfs(ll l,ll r){
    if(vis[l][r])return f[l][r];
    vis[l][r]=1;
    f[l][r]=r-l+1;
    for(ll i=l;i<r;i++){
        if(a[i]==a[i+1])f[l][r]=min(f[l][r],dfs(l,i-1)+dfs(i+2,r-1)+1);
    }
    
    return f[l][r];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    memset(f,0x3f,sizeof(f));
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++)f[i][i]=1,vis[i][i]=1;
    cout<<dfs(1,n);
    return 0;
}