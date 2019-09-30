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
	double X1 = 0,Y1 = 0,X2 = 0,Y2 = 0;
	double V = 0, N = 0,T = 0;
	double X[1000] = { 0 }, Y[1000] = { 0 };
	bool frag = false;
	scanf("%lf%lf%lf%lf%lf%lf%lf", &X1, &Y1, &X2, &Y2, &T, &V,&N);
	for (int i = 0; i < N; i++) {
		scanf("%lf%lf", &X[i], &Y[i]);
		if (sqrt(pow(X1 - X[i], 2) + pow(Y1 - Y[i], 2)) + sqrt(pow(X2 - X[i], 2) + pow(Y2 - Y[i], 2)) <= T * V)
			frag = true;
	}

	printf("%s\n", frag ? "YES" : "NO");

	return 0;
}