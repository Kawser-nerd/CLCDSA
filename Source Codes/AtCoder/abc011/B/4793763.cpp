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



int main(void) {
	string ABC = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string abc = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";

	string S,Ans;
	cin >> S;
	Ans.resize(S.size());

	REP(i, S.size()) {
		Ans[i] = abc[ABC.find(S[i])];
	}

	Ans[0] = ABC[abc.find(Ans[0]) + 26];

	cout << Ans << endl;

ProgramEndPointLabel:;

	system("pause");

	return 0;
}