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

	for (ll i = 1; i <= N / 2; i++) {
		for (ll j = 1; i * j <= N && i >= j; j++) {
			ans = min(ans, (N - i * j) + (i - j));
		}
	}

	if (N != 1)
		printf("%d\n", ans);
	else
		printf("0\n");

	return 0;
} ./Main.cpp:29:18: warning: format specifies type 'int' but the argument has type 'long long' [-Wformat]
                printf("%d\n", ans);
                        ~~     ^~~
                        %lld
1 warning generated.