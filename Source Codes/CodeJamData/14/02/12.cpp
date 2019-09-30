#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

#define ll long long
#define pii pair<int,int>

ofstream fout ("QB.out");
ifstream fin ("QB.in");

double C,F,X;

int main() {
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Working on Case #" << t << endl;
		fin >> C >> F >> X;
		double ans = 0;
		double prod = 2.0;
		while(true) {
			double tn = X/prod;
			double tf = C/prod;
			tf += X/(prod+F);
			if (tf > tn) break;
			ans += C/prod;
			prod += F;
		}
		fout << setprecision(15);
		fout << "Case #" << t << ": " << (ans + X/prod) << endl;
	}
    return 0;
}