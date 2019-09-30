#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <process.h>
#include <windows.h>
#include <ctime>
#include <cstring>
#include <functional>
#include <unordered_set>
#pragma comment(linker, "/STACK:67108864")
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

vector<string> dict;
int numThreads = 0;
int HOD;
const int _maxNumberOfThreads = 4;
const int _maxNumberOfTests = 201;
bool threadsUsed[_maxNumberOfThreads];
HANDLE nowRunning[_maxNumberOfThreads];
struct Answer {
	int numberOfTest;
	int ans;
	inline void output() {
		printf("Case #%d: %d\n", numberOfTest + 1, ans);
	}
};


const int p = 10000019;
struct Solver {
	int _numberOfThread;
	Answer *pAns;
	char str[4005];
	int n;
	unordered_set<unsigned ll> words;
	unsigned ll pp[12];
	int dp[4002][6];
	inline void readInput() {
		scanf("%s", str);
		words.clear();
	}
	inline void upd(int &a, int b) {
		if (a > b) a = b;
	}

	void run() {
		// put an answer into pAns
		rept(i, L(dict)) {
			unsigned ll h = 0;
			rept(j, L(dict[i])) {
				h = h * p + dict[i][j];
			}
			words.insert(h);
		}
		pp[0] = 1;
		rep(i, 11) pp[i] = pp[i - 1] * p;

		n = (int)strlen(str);
		memset(dp, 63, sizeof(dp));
		dp[0][4] = 0;
		rept(i, n) {
			rept(j, 5) {
				if (dp[i][j] >= INF) continue;
				rep(len, 10) {
					if (i + len > n) break;
					unsigned ll cur = 0;
					FOR(z, i, i + len - 1) {
						cur = cur * p + str[z];
					}
					if (words.count(cur)) {
						upd(dp[i + len][min(4, j + len)], dp[i][j]);
						continue;
					}
					rept(fir, len) {
						if (fir + j + 1 < 5) continue;
						bool ok = 0;
						rept(let, 26) {
							if (let == str[i + fir] - 'a') continue;
							unsigned ll now = cur - pp[len - fir - 1] * str[i + fir] + pp[len - fir - 1] * (let + 'a');
							if (words.count(now)) {
								upd(dp[i + len][min(4, len - fir - 1)], dp[i][j] + 1);
								ok = 1;
								break;
							}
							FOR(sec, fir + 5, len - 1) {
								bool ok2 = 0;
								rept(let2, 26) {
									if (let2 == str[i + sec] - 'a') continue;
									unsigned ll nnow = now - pp[len - sec - 1] * str[i + sec] + pp[len - sec - 1] * (let2 + 'a');
									if (words.count(nnow)) {
										upd(dp[i + len][min(4, len - sec - 1)], dp[i][j] + 2);
										ok2 = 1;
										break;
									}
								}
								if (ok2) break;
							}
						}
						if (ok) break;
					}
				}
			}
		}
		int ans = INF;
		rept(i, 5) ans = min(ans, dp[n][i]);
		pAns->ans = ans;
	}
};



void run(void* _p) {
	Solver* s = (Solver*)(_p);
	s->run();
	--numThreads;
	threadsUsed[s->_numberOfThread] = false;
	_endthread();
}
inline void execute(Solver* s) {
	threadsUsed[s->_numberOfThread] = true;
	++numThreads;
	nowRunning[s->_numberOfThread] = (HANDLE)_beginthread(run, 0, s);
}

Solver solvers[_maxNumberOfThreads];
Answer answers[_maxNumberOfTests];

inline void solveParallel(int kolt, int maxThreads = 4) {
	memset(threadsUsed, 0, sizeof(threadsUsed));
	int p = 0;

	while (p < kolt) {
		if (numThreads < maxThreads) {
			int num = 0;
			for (;num < maxThreads && threadsUsed[num]; ++num);
			if (num == maxThreads) continue;

			cerr << "Test #" << p + 1 << " was taken by thread #" << num << " at " << 1.0 * clock() / CLOCKS_PER_SEC << endl;

			solvers[num]._numberOfThread = num;
			solvers[num].readInput();
			answers[p].numberOfTest = p;
			solvers[num].pAns = &answers[p++];
			execute(&solvers[num]);
		}

		if (numThreads == maxThreads) WaitForMultipleObjects(numThreads, nowRunning, false, INFINITE);
	}
	while (numThreads) {
		for (int i = 0; i < maxThreads; ++i) if (threadsUsed[i]) WaitForSingleObject(nowRunning[i], INFINITE);
	}
	
	for (int i = 0; i < kolt; ++i) answers[i].output();

	cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
}

inline void solveSequential(int kolt) {
	for (int hod = 0; hod < kolt; ++hod) {
		cerr << hod << " " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
		solvers[0]._numberOfThread = 1;
		solvers[0].readInput();
		answers[hod].numberOfTest = hod;
		solvers[0].pAns = &answers[hod];
		solvers[0].run();
	}

	for (int i = 0; i < kolt; ++i) answers[i].output();
}

inline void stressTest() {
	for (int hod = 0; hod < INF; ++hod) {
		cerr << hod << " " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
		HOD = hod;
		answers[0].numberOfTest = 0;
		solvers[0]._numberOfThread = 1;
		solvers[0].pAns = &answers[0];
		solvers[0].run();
	}
}

char stmp[10002];
int main() {
	freopen("garbled_email_dictionary.txt", "r", stdin);
	while (gets(stmp)) {
		dict.pb(stmp);
	}
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	char tmp[333];
	int kolt = 0;
	gets(tmp);
	sscanf(tmp, "%d", &kolt);
	if (kolt > _maxNumberOfTests) {
		cerr << "_maxNumberOfTests = " << _maxNumberOfTests << ", but kolt = " << kolt << endl;
		int t = 0;
		while (1) ++t;
	}
	solveParallel(kolt);
	//solveSequential(kolt);
	//stressTest();
}
