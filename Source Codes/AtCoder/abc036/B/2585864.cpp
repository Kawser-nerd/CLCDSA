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

	char str[55][55] = { "\0" };
	ll N = 0;
	scanf("%lld", &N);
	for(ll i = 0;i < N;i++)
		scanf("%s", str[i]);
	for (ll i = 0; i < N; i++) {
		for (ll j = N - 1; j >= 0; j--)
			printf("%c", str[j][i]);
		printf("\n");
	}

	return 0;
}