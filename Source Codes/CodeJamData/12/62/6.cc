#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int C[10001];
double P[10001];

double doit(const vector<double>& v) {
	double pawake = 1.0, pasleep = 0.0, pwoken = 0.0;
	for (int i = 0; i < v.size(); i++) {
		pwoken += pasleep * v[i];
		pasleep = pasleep * (1.0-v[i]) + pawake * (1.0-v[i]);
		pawake *= v[i];
	}
	return pwoken;
}

main() {
	int T, prob = 1;
	for (cin >> T; T--;) {
		int N, K;
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			int a, b;
			char ch;
			cin >> a >> ch >> b >> C[i];
			P[i] = a/(double)b;
		}

		vector<double> v;
		for (int i = 0; i < N; i++)
		for (int j = 0; j < C[i]; j++)
			v.push_back(P[i]);
		sort(v.begin(), v.end());

		double ret = 1.0;
		for (int nmx = 0; nmx <= K; nmx++)
		for (int order1 = 0; order1 <= 2; order1++)
		for (int order2 = 0; order2 <= 2; order2++) {
			vector<double> v2;
			if (order1) {
				v2.insert(v2.end(), v.begin()+v.size()-nmx, v.end());
			} else {
				v2.insert(v2.end(), v.rbegin(), v.rbegin()+nmx);
			}
			if (order2) {
				v2.insert(v2.end(), v.rbegin()+v.size()-(K-nmx), v.rend());
			} else {
				v2.insert(v2.end(), v.begin(), v.begin()+(K-nmx));
			}
			ret = min(ret, doit(v2));
		}
		printf("Case #%d: %.9lf\n", prob++, ret);
	}
}
