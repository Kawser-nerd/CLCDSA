#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>

#define BIT(a) (1 << (a))

using namespace std;

long long MOD = 1000000007;

long long numerator[200005];
long long denominator[200005];

long long mod_pow(long long x, long long n){
    long long res = 1;
    for(int i = 0;i < 60; i++){
        if(n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

int main(void){
	long long n, k;
	cin >> n >> k;
	if (n == 1){
		cout << 1 << endl;
		return 0;
	}

	numerator[0] = 1;
	for (int i = 1; i < 200005; i++){
		numerator[i] = numerator[i-1]*i % MOD;
	}

	for (int i = 1; i < 200005; i++){
		denominator[i] = mod_pow(numerator[i], MOD-2);
	}

	long long ans = numerator[(n-1)+k]*denominator[n-1];
	ans %= MOD;
	ans *= denominator[k];
	ans %= MOD;

	cout << ans << endl;
	return 0;
}