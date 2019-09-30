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

int N,D1,D2,D3;

int main(void) {
	cin >> N >> D1 >> D2 >> D3;
	if (N == D1 || N == D2 || N == D3) {
		puts("NO"); goto ProgramEndPointLabel;
	}

	int count;
	for (count = 1;count <= 100; count++) {
		for (int minus = 3; minus >= 1; minus--) {
			int tmp = N - minus;
			if (tmp == D1 || tmp == D2 || tmp == D3)
				if (minus == 1) {
					puts("NO");
					goto ProgramEndPointLabel;
				} else continue;
			//printf("%d ", minus);
			N -= minus;
			break;
		}
	}

	if (N <= 0)
		puts("YES");
	else
		puts("NO");

ProgramEndPointLabel:;

	system("pause");

	return 0;
} ./Main.cpp:34:7: warning: add explicit braces to avoid dangling else [-Wdangling-else]
                                } else continue;
                                  ^
1 warning generated.