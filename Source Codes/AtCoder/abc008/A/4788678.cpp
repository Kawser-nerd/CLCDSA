#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<map>

#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i,a,b) for (ll i=(a);i<(ll)b; i++)

typedef long long ll;

using namespace std;

bool Contains(string str, string inc) {
	return str.find(inc) != string::npos;
}

int main(void) {
	int S, T;
	cin >> S >> T;

	cout << (T - S + 1) << endl;

ProgramEndPointLabel:;

	system("pause");

	return 0;
}