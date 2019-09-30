#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;
ll inf = 1e18;
ll mod=1e9+7;
//LLONG_MIN

/*
AC
??????xor?0
*/

ll a,b,ans=0,a2=0;

//O(log(x))??
// ll xor_sum(ll s){
// 	ll sum=0;
// 	rep(i,40){
// 		bool ok=false;
// 		ll x=(ll)1<<i;
// 		if(i==0){//????????????????2?????????
// 			if((s+1)/2%2==1)ok=true;
// 		}else if((s/x)%2 == 1 && ((s+1)%x)%2 == 1){
// 			ok=true;
// 		}
// 		if(ok)sum+=x;
// 	}
// 	return sum;
// }

//O(1)??
ll xor_sum(ll s){
	ll ans;
	switch((s+1)%4){
		case 0:
			ans=0;
			break;
		case 1:
			ans=s;
			break;
		case 2:
			ans=1;
			break;
		case 3:
			ans=s^1;
			break;
	}
	return ans;
}

int main(void){
	cin>>a>>b;
	cout<<(xor_sum(b)^xor_sum(a-1))<<endl;
	return 0;
}