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
	ll i = 4;
	scanf("%lld", &N);
	if (N == 1) {
		printf("Aoki\n");
		return 0;
	}
	N--;
	while (1) {
		N -= i;
		if (N <= 0) {
			printf("Takahashi\n");
			return 0;
		}
		N -= i;
		if (N <= 0) {
			printf("Aoki\n");
			return 0;
		}
		i *= 4;
	}
	return 0;
}