#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
using ulong = unsigned long;
using ll = long long;
const int M = 1e9 + 7;
#pragma unused(M)

ll next(ll prev, ll thre){
	// for(int i=1;;i++){
	// 	if(prev * i >= thre){
	// 		return i;
	// 	}
	// }
	ll l = 1, r = 1e18 / prev;
	// cout<<"prev:"<<prev<<' '<<thre<<endl;
	// if(prev > thre){ return 1; }
	while(l < r){
		// cout<<l<<' '<<r<<endl;
		// cout<<r<<endl;
		ll piv = (l + r) / 2;
		if(prev * piv < thre){
			l = piv + 1;
		}else{
			r = piv;
		}
	}
	return l;
}

int main(){
	int n;
	cin >> n;
	ll t, a;
	cin >> t >> a;
	for(int i=0;i<n-1;i++){
		ll ti, ai;
		cin >> ti >> ai;
		ll rt = next(ti, t), ra = next(ai, a), r = max(rt, ra);
		t = ti * r;
		a = ai * r;
		// cout<<t<<' '<<a<<endl;
	}
	cout << t + a << endl;
	return 0;
}