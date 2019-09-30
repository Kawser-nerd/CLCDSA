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
	int n;
	cin >> n;
	int sum = 0, num = 0, tmp;
	REP(i, n) {
		cin >> tmp;
		if (tmp != 0) {
			sum += tmp;
			num++;
		}
	}

	cout << ceil((double)sum / (double)num) << endl;


ProgramEndPointLabel:;

	system("pause");

	return 0;
}