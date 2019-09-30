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
	int txa, tya, txb, tyb, T, V, n;
	cin >> txa >> tya >> txb >> tyb >> T >> V >> n;
	double move_dist = (double)(T * V);

	bool isUwa = false;
	int x, y;
	REP(i, n) {
		cin >> x >> y;
		if (move_dist >= dist(txa, tya, x, y) + dist(x, y, txb, tyb)) {
			isUwa = true;
			break;
		}
	}

	if (isUwa == true) {
		puts("YES");
	}
	else {
		puts("NO");
	}

ProgramEndPointLabel:;

	system("pause");

	return 0;
}