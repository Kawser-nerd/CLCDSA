#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;

ll func(ll x){ // cout << x << endl;
	int i;
	
	if(x < 10) return x;
	
	string s;
	ll y = x;
	while(y > 0){
		s = (char)('0' + y%10) + s;
		y /= 10;
	}
	
	int L = s.length();
	ll ten = 1;
	REP(i,(L+1)/2) ten *= 10;
	
	if(x % ten == 1){
		string t = s;
		reverse(t.begin(),t.end());
		ll z = 0;
		REP(i,t.length()) z = z * 10 + (t[i] - '0');
		if(z != x) return func(z) + 1;
		return func(x-1) + 1;
	}
	
	if(ten > 1) ten /= 10;
	ll step = (x % ten - 1 + ten) % ten;
	if(step == 0) step = 1;
	
	return func(x-step) + step;
}

void main2(void){
	ll N;
	cin >> N;
	cout << func(N) << endl;
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc+1);
		main2();
	}
	return 0;
}
