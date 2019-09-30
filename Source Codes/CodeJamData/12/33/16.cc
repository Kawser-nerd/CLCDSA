#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void Init() {
}

typedef long long ll;

inline void Update(ll& r, ll t) {
	if (t > r) r = t;
}

int aN, bN;
vector<ll> aC, aT, bC, bT;
ll f[200][200];

void Read(istream& in, int& N, vector<ll>& C, vector<ll>& T) {
	C.resize(N);
	T.resize(N);
	for (int i = 0; i < N; ++i)
		in >> C[i] >> T[i];
	int N0 = N;
	N = 0;
	for (int i = 0; i < N0; ++i)
		if (N == 0 || T[i] != T[N - 1]) {
			C[N] = C[i];
			T[N] = T[i];
			++N;
		} else {
			C[N - 1] += C[i];
		}
}

void Solve(istream& in, ostream& out) {
	in >> aN >> bN;
	Read(in, aN, aC, aT);
	Read(in, bN, bC, bT);
	memset(f, 0, sizeof(f));
	for (int a = 0; a <= aN; ++a)
		for (int b = 0; b <= bN; ++b)
			if (!a || !b) {
				if (a) Update(f[a][b], f[a - 1][b]);
				if (b) Update(f[a][b], f[a][b - 1]);
			} else {
				Update(f[a][b], max(f[a - 1][b], f[a][b - 1]));
				if (aT[a - 1] != bT[b - 1])
					continue;
				ll sumA = 0;
				for (int aa = a - 1; aa >= 0; --aa) if (aT[aa] == aT[a - 1]) {
					sumA += aC[aa];
					ll sumB = 0;
					for (int bb = b - 1; bb >= 0; --bb) if (bT[bb] == bT[b - 1]) {
						sumB += bC[bb];
						Update(f[a][b], f[aa][bb] + min(sumA, sumB));
					}
				}
			}
	out << f[aN][bN] << endl;
}

void Main2(istream& in, ostream& out) {
	Init();
	int testNo;
	in >> testNo;
	string line;
	getline(in, line);
	for (int caseId = 1; caseId <= testNo; ++caseId) {
		out << "Case #" << caseId << ": ";
		Solve(in, out);
	}
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		cin.sync_with_stdio(false);
		cout.sync_with_stdio(false);
		Main2(cin, cout);
	} else {
		string s(argv[1]);
		if (s.size() >= 1 && s[s.size() - 1] == '.')
			s.erase(s.end() - 1);
		else if (s.size() >= 3 and s.substr(s.size() - 3) == ".in")
			s.erase(s.end() - 3, s.end());
		ifstream fin((s + ".in").c_str());
		ofstream fout((s + ".out").c_str());
		Main2(fin, fout);
	}
	return 0;
}
