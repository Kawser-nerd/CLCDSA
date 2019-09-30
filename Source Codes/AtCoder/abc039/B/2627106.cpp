#include<algorithm>
#include<iostream>
#include<math.h>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<string>
#include<vector>

#define ll long long
#define ull unsigned long long

using namespace std;
int main(void) {

	ll N = 0;
	ll ans = LONG_MAX;

	scanf("%lld", &N);

	for (ll i = 0; pow(i, 4) <= N; i++) {
		if (pow(i, 4) == N) {
			printf("%lld\n", i);
			return 0;
		}
	}

	return 0;
}