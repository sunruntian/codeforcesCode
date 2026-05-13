#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,p[200005];
ll l[200005],r[200005];
ll st[200005],top=1;
void lr(){
    for(ll i=1;i<=n;i++)l[i]=1,r[i]=n;
    for(ll i=1;i<=n;i++){
        while(top>1&&p[st[top-1]]<p[i]){
            r[st[top-1]]=i-1;;
            top--;
        }
        if(top==1)l[i]=1;
        else l[i]=st[top-1]+1;
        st[top++]=i;
    }
    for(ll i=1;i<=n;i++)cout<<l[i]<<" "<<r[i]<<"\n";
}
ll t[200005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>p[i];
    }
    //cerr<<"======================\n";
    lr();
    //cerr<<"======================\n";
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll l1=l[i],r1=i,l2=i+1,r2=r[i];
        if((r1-l1+1)<(r2-l2+1)){
            for(ll j=l2;j<=r2;j++){
                t[p[j]]++;
            }
            for(ll j=l1;j<=r1;j++){
                ans+=t[(p[i]-p[j])];
            }
            for(ll j=l2;j<=r2;j++){
                t[p[j]]=0;
            }
        }else{
            for(ll j=l1;j<=r1;j++){
                t[p[j]]++;
            }
            for(ll j=l2;j<=r2;j++){
                ans+=t[(p[i]-p[j])];
            }
            for(ll j=l1;j<=r1;j++){
                t[p[j]]=0;
            }
        }
    }
    //cerr<<"======================\n";
    cout<<ans;
    return 0;
}
