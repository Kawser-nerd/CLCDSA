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
	double a = 0.0, b = 0.0, c = 0.0, d = 0.0;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

	if (b / a == d / c)
		printf("DRAW");
	else if (b / a > d / c)
		printf("TAKAHASHI");
	else
		printf("AOKI");
	printf("\n");
	

	return 0;
}