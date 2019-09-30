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

const double eps = 1e-20;

void Init() {
}

int N;
double D, t[2222], p[2222];

double Solve(double a) {
	double v = 0, curP = 0;
	for (int i = 0; i + 1 < N; ++i) {
		double T = t[i + 1] - t[i],
			   V = (p[i + 1] - p[i]) / T;
		if (curP + v * T + 0.5 * a * T * T <= p[i + 1] + eps) {
			curP += v * T + 0.5 * a * T * T;
			v += a * T;
		} else {
			curP = p[i + 1];
			v = sqrt(2 * p[i + 1] * a);
		}
	}
	double A = 0.5 * a, B = v, C = curP - D;
	double delta = B * B - A * C * 4;
	return (-B + sqrt(delta)) / A / 2 + t[N - 1];
}

void Solve(istream& in, ostream& out) {
	int A;
	in >> D >> N >> A;
	for (int i = 0; i < N; ++i)
		in >> t[i] >> p[i];
	while (N > 1 && p[N - 2] >= D - eps) --N;
	if (p[N - 1] > D + eps) {
		double T = t[N - 1] - t[N - 2],
			   V = (p[N - 1] - p[N - 2]) / T;
		p[N - 1] = D;
		t[N - 1] = (D - p[N - 2]) / V + t[N - 2];
	}
	out << endl;
	for (int i = 0; i < A; ++i) {
		double a;
		in >> a;
		out << Solve(a) << endl;
	}
}

void Main2(istream& in, ostream& out) {
	Init();
	int testNo;
	in >> testNo;
	string line;
	getline(in, line);
	out.setf(ios::fixed);
	out.precision(20);
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
