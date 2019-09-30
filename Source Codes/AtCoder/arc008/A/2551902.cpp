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
	scanf("%lld", &N);
	printf("%lld\n", (N / 10 * 100) + (N % 10 > 6 ? 100 : (N % 10) * 15));

	return 0;
}