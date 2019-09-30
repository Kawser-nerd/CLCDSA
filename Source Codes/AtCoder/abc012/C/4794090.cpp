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
	int N;
	cin >> N;

	N = 2025 - N;

	for (int i = 1; i <= 9;i++) 
		if (N % i == 0 && (N / i <= 9)) 
			printf("%d x %d\n", i, N / i);


ProgramEndPointLabel:;

	system("pause");

	return 0;
}