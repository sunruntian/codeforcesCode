#include<bits/stdc++.h>
typedef long long ll;//https://wwuu.lanzouo.com/i7lzN39p2yzew
using namespace std;
string s;
ll len,has1[5000005],has2[5000005],p[5000005],dp[5000005],ans;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	len=s.size();
	s=" "+s;
	p[0]=1;
	for(ll i=1;i<=len;i++) {
		has1[i]=has1[i-1]*131+s[i];
		has2[i]=has2[i-1]*131+s[len-i+1];
		p[i]=p[i-1]*131;
	}
	for(ll i=1;i<=len;i++) {
		if(has1[i/2]-has1[0]*p[i/2]==has2[len-i+i/2]-has2[len-i]*p[i/2]) {
			dp[i]=dp[i/2]+1;
			ans+=dp[i];
		}
	}
	cout<<ans;
	return 0;
}
