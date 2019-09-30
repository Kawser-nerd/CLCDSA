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
	int n, X;
	cin >> n >> X;
	vector<int> a(n);
	REP(i, n)
		cin >> a[i];

	int res = 0;
	REP(i, n) {
		res += ((X % 2) ? a[i] : 0);
		X /= 2;
	}

	cout << res << endl;

ProgramEndPointLabel:;

	system("pause");

	return 0;
}