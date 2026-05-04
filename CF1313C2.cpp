#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct Node{
    ll l,r,m;
}st1[500005],st2[500005];
ll m[500005],n,ans,l[500005],r[500005],top1=1,top2=1,t[500005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>m[i];
    }
    for(ll i=1;i<=n;i++){
        while(top1>1&&st1[top1-1].m>m[i]){
            top1--;
        }
        ll j=0;
        if(top1==1){
            l[i]=m[i]*i;
        }else{
            ll j=st1[top1-1].r;
            l[i]=l[j]+m[i]*(i-j);
        }
        st1[top1++]={j+1,i,m[i]};
    }
    for(ll i=n;i>=1;i--){
        while(top2>1&&st2[top2-1].m>m[i]){
            top2--;
        }
        ll j=n+1;
        if(top2==1){
            r[i]=m[i]*(n-i+1);
        }else{
            ll j=st2[top2-1].l;
            r[i]=r[j]+m[i]*(j-i);
        }
        st2[top2++]={i,j-1,m[i]};
    }
    ll id=0;
    for(ll i=1;i<=n;i++){
        //cerr<<l[i]<<" "<<r[i]<<"\n";
        if(ans<r[i]+l[i]-m[i]){
            ans=r[i]+l[i]-m[i];
            id=i;
        }
    }
    t[id]=m[id];
    //cerr<<id<<"\n";
    for(ll i=id-1;i>=1;i--){
        t[i]=min(t[i+1],m[i]);
    }
    for(ll i=id+1;i<=n;i++){
        t[i]=min(t[i-1],m[i]);
    }
    for(ll i=1;i<=n;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}