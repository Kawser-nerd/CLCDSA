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

int main(void) {
	int N;
	cin >> N;

	vector<int> A;
	int tmp;

	REP(i, N) {
		cin >> tmp;
		A.push_back(tmp);
	}

	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());

	cout << A[A.size() - 2] << endl;


ProgramEndPointLabel:;

	system("pause");

	return 0;
}