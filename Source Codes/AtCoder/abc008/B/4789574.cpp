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
	
	map<string, int> mp;

	string tmp;
	REP(i, N) {
		cin >> tmp;
		mp[tmp]++;
	}

	int max = 0;
	string max_name;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		int point = it->second;
		if (max < point) {
			max = point;
			max_name = it->first;
		}
	}

	cout << max_name << endl;

ProgramEndPointLabel:;

	system("pause");

	return 0;
}