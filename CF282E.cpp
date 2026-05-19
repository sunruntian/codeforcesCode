#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;

ll n,a[100005],s[100005],ans,tree[100005*45][2],tot,vis[100005*45];

void insert(ll x){
	ll cur=0;
	for(ll i=40;i>=0;i--){
		ll k=((x>>i)&1);
		if(!tree[cur][k])tree[cur][k]=++tot;
		cur=tree[cur][k];
		vis[cur]++;
	}
}

ll query(ll x){
	ll cur=0,res=0;
	for(ll i=40;i>=0;i--){
		ll k=((x>>i)&1);
		if(!tree[cur][k^1]||!vis[tree[cur][k^1]]){
			if(!tree[cur][k]||!vis[tree[cur][k]])break;
			else{
				res=res*2;
				cur=tree[cur][k];
			}
		}
		else{
			cur=tree[cur][k^1];
			res=res*2+1;
		}
	}
	return res;
}

signed main(){
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=n;i>=1;i--){
		s[i]=s[i+1]^a[i];
		insert(s[i]);
	}
	ans=query(0);
    ll t=0;
	for(ll i=1;i<=n;i++){
		t^=a[i];
		ans=max(ans,query(t));
	}
	cout<<ans;
	return 0;
}
