#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,k,cnt;
ll a[300005],b[300005],c[300005];
ll lst[300005];
vector<ll>tong[300005];
priority_queue<ll,vector<ll>,greater<ll>>pq;
ll ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i],lst[i]=i;
    for(ll i=1;i<=m;i++){
        ll x,y;cin>>x>>y;
        lst[y]=max(lst[y],x);
    }
    cnt=k;
    for(ll i=1;i<=n;i++){
        tong[lst[i]].push_back(i);
    }
    for(ll i=1;i<=n;i++){
        while(cnt<a[i]){
            if(pq.empty()){
                cout<<-1;
                return 0;
            }
            ans-=pq.top();
            pq.pop();
            cnt++;
        }
        cnt+=b[i];
        for(auto x:tong[i]){
            cnt--;
            pq.push(c[x]);
            ans+=c[x];
        }
        while(cnt<0){
            ans-=pq.top();
            pq.pop();
            cnt++;
        }
    }
    cout<<ans;
    return 0;
}