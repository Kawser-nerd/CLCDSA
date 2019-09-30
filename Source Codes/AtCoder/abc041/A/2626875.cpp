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
	char str[101] = "\0";
	scanf("%s", str);
	scanf("%lld", &N);

	printf("%c\n", str[N - 1]);

	return 0;
}