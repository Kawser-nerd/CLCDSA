#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
using ulong = unsigned long;
using ll = long long;

ll makeNRed(ll n, ll r, ll b, ll x, ll y){
	ll restr = r - x * n,
	   restb = b - n,
	   maxnumb = min(restr, restb / y);
	if(n > 0 && x > (1ll<<62) / n){
		return 0;
	}
	if(maxnumb < 0){
		return 0;
	}
// 	cout<<"mnr"<<n<<' '<<r<<' '<<b<<' '<<x<<' '<<y<<" ret:"<<n+maxnumb<<endl;
	return n + maxnumb;
}

ll bs(ll left, ll lm, ll rm, ll right, ll r, ll b, ll x, ll y){
// 	cout<<"bs "<<left<<' '<<lm<<' '<<rm<<' '<<right<<endl;
	if(left + 4 >= right){
		ll ret = 0;
		for(ll i=left;i<=right;i++){
			ret = max(ret, makeNRed(i, r, b, x, y));
		}
		return ret;
	}
// 	if(left + 3 >= right){
// 		return max(
// 				max(makeNRed(left, r, b, x, y),
// 					makeNRed(lm, r, b, x, y)),
// 				max(makeNRed(rm, r, b, x, y),
// 					makeNRed(right, r, b, x, y)));
// 	}
	ll lval = makeNRed(lm, r, b, x, y),
	   rval = makeNRed(rm, r, b, x, y);
	
	if(lval < rval){
		return bs(lm, lm + (right - lm) / 3, lm + (right - lm) * 2 / 3, right, r, b, x, y);
// 	}else if(lval > rval){
	}else{
		return bs(left, left + (rm - left) / 3, left + (rm - left) * 2 / 3, rm, r, b, x, y);
// 	}else if(lval == 0){
// 		bs(lm, lm + (right - lm) / 3, lm + (right - lm) * 2 / 3, right, r, b, x, y);
// 		return bs(left, left + (rm - left) / 3, left + (rm - left) * 2 / 3, rm, r, b, x, y);
// 		return max(bs(lm, lm + (right - lm) / 3, lm + (right - lm) * 2 / 3, right, r, b, x, y),
// 				bs(left, left + (rm - left) / 3, left + (rm - left) * 2 / 3, rm, r, b, x, y));
// 	}else if(lm + 1 >= rm){
// // 		return bs(lm, lm + (rm - lm) / 3, lm + (rm - lm) * 2 / 3, rm, r, b, x, y);
// 		ll ret = 0;
// // 		cout<<left<<' '<<right<<endl;
// // 		cout<<lval<<' '<<rval<<endl;
// 		for(int i=left;i<=right;i++){
// 			ret = max(ret, makeNRed(i, r, b, x, y));
// 		}
// 		return ret;
// 	}else{
// 		return bs(lm, lm + (rm - lm) / 3, lm + (rm - lm) * 2 / 3, rm, r, b, x, y);
	}
}

int main(){
	ll r, b, x, y;
	cin >> r >> b >> x >> y;

	ll right = min(b, r / x);
	cout << bs(0, right / 3, right * 2 /  3, right, r, b, x, y) << endl;
// 	ll n = (b * (x - 1) + r * (y - 1)) / (x * y - 1);
// 	cout << n << endl;
	return 0;
}