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

int N, M;
vector<vector<int> > adj, invAdj, reach;
vector<int> deg;

bool Solve(istream& in, ostream& out) {
	in >> N;
	deg.assign(N, 0);
	adj.assign(N, vector<int>());
	invAdj.assign(N, vector<int>());
	for (int i = 0; i < N; ++i) {
		int M;
		in >> M;
		for (int j = 0; j < M; ++j) {
			int k;
			in >> k;
			--k;
			++deg[k];
			adj[i].push_back(k);
			invAdj[k].push_back(i);
		}
	}
	vector<int> ord;
	for (int i = 0; i < N; ++i)
		if (deg[i] == 0)
			ord.push_back(i);
	for (int i = 0; i < ord.size(); ++i) {
		int u = ord[i];
		for (int& v : adj[u])
			if (--deg[v] == 0)
				ord.push_back(v);
	}
	reach.assign(N, vector<int>());
	for (int& u : ord) {
		int sum = 0;
		for (int& v : invAdj[u])
			sum += reach[v].size();
		if (sum >= N)
			return true;
		vector<int>& r = reach[u];
		r.reserve(sum + 1);
		r.push_back(u);
		for (int& v : invAdj[u])
			r.insert(r.end(), reach[v].begin(), reach[v].end());
		sort(r.begin(), r.end());
		r.erase(unique(r.begin(), r.end()), r.end());
		if (r.size() < sum + 1)
			return true;
	}
	return false;
}

void Main2(istream& in, ostream& out) {
	Init();
	int testNo;
	in >> testNo;
	string line;
	getline(in, line);
	for (int caseId = 1; caseId <= testNo; ++caseId) {
		out << "Case #" << caseId << ": ";
		out << (Solve(in, out) ? "Yes" : "No") << endl;
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
