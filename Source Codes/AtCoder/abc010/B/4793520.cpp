#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<map>

#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i,a,b) for (ll i=(a);i<(ll)b; i++)
#define PRINT(x) std::cout << x << std::endl;

typedef long long ll;

using namespace std;

int main(void) {
	//bool OK[] = { true,false,true,false,false,false };
	int Num[] = { 0,1,0,1,2,3 };
	int n;
	cin >> n;
	int tmp;
	int res = 0;
	REP(i, n) {
		cin >> tmp;
		res += Num[(tmp - 1) % 6];
	}
	printf("%d\n", res);

ProgramEndPointLabel:;

	system("pause");

	return 0;
}