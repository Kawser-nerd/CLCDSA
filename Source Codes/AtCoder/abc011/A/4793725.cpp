#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<map>
#include<math.h>

#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i,a,b) for (ll i=(a);i<(ll)b; i++)
#define PRINT(x) std::cout << x << std::endl;

typedef long long ll;

using namespace std;

double dist(int x1, int y1, int x2, int y2) {
	return sqrt((double)(x1 - x2) * (double)(x1 - x2) + (double)(y1 - y2) * (double)(y1 - y2));
}

int main(void) {
	int n;
	cin >> n;
	int ans = n % 12;

	printf("%d\n", ans + 1);
	

ProgramEndPointLabel:;

	system("pause");

	return 0;
}