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

long double calc(long double p, long double t){
	return t + p / pow(2, t/1.5);
}

int main(){
	long double p;
	cin >> p;
	long double left = 0, right = p;
	while(1){
		long double ll = left + (right - left) / 3, rr = left + (right - left) * 2 / 3,
			 lval = calc(p, ll), rval = calc(p, rr);
		if(lval > rval){
			left = ll;
		}else{
			right = rr;
		}
		// cout << left << ' ' << ll << ' ' << rr << ' ' << right << endl;
		if(abs(ll - rr) < 10e-10){
			cout << fixed << setprecision(10) << calc(p, ll) << endl;
			break;
		}
	}
	return 0;
}