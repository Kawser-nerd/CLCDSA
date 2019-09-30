#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;
typedef long long ll;
const ll maxK = 100000;
const ll maxAi = 1000000000;
ll K, A[maxK + 10];
ll ansMax, ansMin;
ll maxValue = 2 + maxK*maxAi;

ll simulate(ll x) {
	for (ll i = 0; i < K; i++) {
		x /= A[i];
		x *= A[i];
	}
	return x;
}

ll searchMax() {
	//simulate(x)<=2??????
	ll min = 0, max = maxValue, x = (min + max) / 2, gx;
	while (1) {
		if (simulate(x) <= 2) { 
			min = x;
			x = (min + max) / 2;
		}
		else {
			max = x;
			x = (min + max) / 2;
		}
		if ((max - min) <= 1) {
			if (simulate(max) <= 2)return max;
			else return min;
		}
	}
}

ll searchMin() {
	//simulate(x)>=2??????
	ll min = 0, max = maxValue, x = (min + max) / 2, gx;
	while (1) {
		if (simulate(x) >= 2) {
			max = x;
			x = (min + max) / 2;
		}
		else {
			min = x;
			x = (min + max) / 2;
		}
		if ((max - min) <= 1) {
			if (simulate(min) >= 2)return min;
			else return max;
		}
	}
}


int main() {
	cin >> K;
	for (ll i = 0; i < K; i++) {
		cin >> A[i];
	}

	ansMax = searchMax();
	ansMin = searchMin();

	if (ansMin > ansMax) cout << "-1" << endl;
	else cout << ansMin << " " << ansMax << endl;

	return 0;
}