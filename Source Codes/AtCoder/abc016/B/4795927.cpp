#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<map>
#include<math.h>
#include<iomanip>

#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i,a,b) for (ll i=(a);i<(ll)b; i++)
#define PRINT(x) std::cout << x << std::endl;

typedef long long ll;

using namespace std;

int main(void) {
	int A, B, C;
	cin >> A >> B >> C;

	bool Plus = A + B == C;
	bool Minus = A - B == C;

	if (Plus && !Minus) puts("+");
	else if (!Plus && Minus) puts("-");
	else if (Plus && Minus) puts("?");
	else puts("!");

ProgramEndPointLabel:;

	system("pause");

	return 0;
}