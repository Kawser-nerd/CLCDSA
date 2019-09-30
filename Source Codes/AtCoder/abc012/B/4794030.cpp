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

	int hour = N / 3600;
	N %= 3600;
	int min = N / 60;
	N %= 60;
	int sec = N;

	cout << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << min << ":" << setfill('0') << setw(2) << sec << endl;

ProgramEndPointLabel:;

	system("pause");

	return 0;
}