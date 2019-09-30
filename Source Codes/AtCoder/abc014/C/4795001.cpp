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
	vector<int> ques(1000001);
	int n;
	cin >> n;
	int a, b;
	REP(i, n) {
		cin >> a >> b;
		//printf("Input:%d %d\n", a, b);
		ques[a]++;
		if (b == 1000000) continue;
		ques[b + 1]--;
	}

	int mx;
	int sum = 0;
	REP(i, 1000001) {
		sum += ques[i];
		mx = max(mx, sum);
	}

	printf("%d\n", mx);

ProgramEndPointLabel:;

	system("pause");

	return 0;
}