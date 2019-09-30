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

int main(){
	ll a, k;
	cin >> a >> k;
	if(k == 0){
		ll ans = 2e12 - a;
		cout << ans << endl;
		return 0;
	}
	for(int i=1;;i++){
		a += 1 + k * a;
		if(a >= 2e12){
			cout << i << endl;
			break;
		}
	}
	return 0;
}