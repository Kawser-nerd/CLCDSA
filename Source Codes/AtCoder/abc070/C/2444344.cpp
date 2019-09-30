#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

long long gcd(long long x, long long y){
	if(y > x) swap(x, y);
	return !y ? x : gcd(y, x % y);
}

long long lcm(long long x, long long y){
	return x / gcd(x, y) * y;
}

int main() {
	int n;
	cin >> n;
	long long t[101] = {0};
	for(int i = 0; i < n; i++) cin >> t[i];
	
	long long ans = t[0];
	for(int i = 1; i < n; i++){
		ans = lcm(ans, t[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}