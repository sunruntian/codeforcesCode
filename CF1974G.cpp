#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll T;
    cin>>T;
    while(T--){
        ll n,x;
        cin>>n>>x;
        priority_queue<ll>pq;
        ll m=0;
        for(ll i=1;i<=n;i++){
            ll c;
            if(m>=c){
                pq.push(c);
            }else{
                if(c<pq.top()){
                    m+=pq.top();
                    pq.pop();
                    pq.push(c);
                }
            }
            m+=x;
        }
        cout<<pq.size()<<"\n";
    }
    return 0;
}