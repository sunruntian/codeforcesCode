#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,a[100005],st[100005],top=1;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=n;i>=1;i--){
        if(top==1||a[i]<a[st[top-1]]){
            st[top++]=i;
        }
    }
    for(ll i=1;i<=n;i++){
        ll l=1,r=top-1;
        ll id=-1;
        while(l<=r){
            ll mid=(l+r)/2;
            if(a[st[mid]]<a[i]){
                id=st[mid];
                r=mid-1;
            }else{
                l=mid+1;
            }
            
        }
        if(id!=-1&&id>i){
            cout<<id-i-1<<" ";
        }else{
            cout<<"-1 ";
        }
    }
    return 0;
}