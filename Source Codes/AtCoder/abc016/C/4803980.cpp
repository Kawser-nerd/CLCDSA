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

int N, M;
vector<vector<bool>> isConnect;
vector<bool> isAdd;

int search(int curr) {
	int res = 0;
	REP(i, N) {
		if (i != curr && isConnect[i][curr]) {
			REP(j, N) {
				if (j != curr && j != i && isConnect[j][i] && !isConnect[j][curr] && !isAdd[j]) {
					res++;
					isAdd[j] = true;
				}
			}
		}
	}
	return res;
}

int Depth = 2;


int main(void) {
	cin >> N >> M;

	//Initialize
	isConnect.resize(N);
	REP(i, N) {
		isConnect[i].resize(N);
	}

	int a, b;
	REP(i, M) {
		cin >> a >> b;
		isConnect[a - 1][b - 1] = true;
		isConnect[b - 1][a - 1] = true;
	}

	vector<bool> Init(N);
	REP(i, N) {
		isAdd = Init;
		cout << search(i) << endl;
	}

ProgramEndPointLabel:;

	system("pause");

	return 0;
}