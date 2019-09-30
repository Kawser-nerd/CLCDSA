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

struct Solver {
	int _numberOfThread;
	Answer *pAns;
	int a, n;
	int mas[102];
	inline void readInput() {
		scanf("%d%d", &a, &n);
		rept(i, n) scanf("%d", &mas[i]);
	}

	void run() {
		// put an answer into pAns
		sort(mas, mas + n);
		int ans = 2 * INF + 1;
		rept(good, n + 1) {
			int cur = n - good;
			int have = a;
			rept(i, good) {
				if (have > mas[i]) {
					have += mas[i];
				} else {
					if (have == 1) {
						cur = 2 * INF + 1;
						break;
					}
					while (have <= mas[i]) {
						have += have - 1;
						++cur;
					}
					have += mas[i];
				}
			}
			ans = min(ans, cur);
		}
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
int main() {
	freopen("A-large.in", "r", stdin);
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
