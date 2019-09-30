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

	ll A = 0, B = 0, C = 0, K = 0;
	ll S = 0, T = 0;
	ll ans = 0;

	scanf("%lld%lld%lld%lld", &A, &B, &C, &K);
	scanf("%lld%lld", &S, &T);

	ans = A * S + B * T;
	if (S + T >= K)
		ans -=  C * (S + T);

	printf("%lld\n", ans);

	return 0;
}