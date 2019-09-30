#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
#include <complex>
typedef complex<double> P;
double dot(P a, P b) {
	return (a.real() * b.real() + a.imag() * b.imag());
}
double cross(P a, P b) {
	return (a.real() * b.imag() - a.imag() * b.real());
}
int ccw(P a, P b,P c) {
	P e = b - a;
	P f = c - a;
	if (cross(e, f) > eps) {
		return 1;
	}
	if (cross(e, f) < -eps) {
		return -1;
	}
	if (dot(e, f) < -eps) return 2;
	if (abs(e) < abs(f)) return -2;
	return 0;
}
bool intersect(P a, P b, P c, P d) {
	if (ccw(a, b, c) * ccw(a, b, d) <= 0) {
		if (ccw(c, d, a) * ccw(c, d, b) <= 0){
			return 1;
		}
	}
	return 0;
}
double getDistanceLP(P a, P b, P c) {
	return abs(cross(b - a, c - a) / abs(b - a));
}
double getDistanceSP(P a, P b, P c) {
	if (dot(b - a, c - a) < 0.0) return abs(c - a);
	if (dot(a - b, c - b) < 0.0) return abs(c - b);
	return getDistanceLP(a, b, c);
}
double getDistance(P a, P b, P c, P d) {
	if (intersect(a, b, c, d)) return 0.0;
	return min({ getDistanceSP(a, b, c), getDistanceSP(a, b, d), getDistanceSP(c, d, a), getDistanceSP(c, d, b) });
}
long long input[300000] = {};
int removed[300000] = {};
long long cnt[300000][2] = {};
vector<int> vertexs[300000];
int main() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		vertexs[a].push_back(b);
		vertexs[b].push_back(a);
	}
	REP(i, n) {
		input[i + 1] = s[i] - 'A';
	}
	queue<int> next;
	for (int i = 1; i <= n; ++i) {
		for (int q = 0; q < vertexs[i].size(); ++q) {
			cnt[i][input[vertexs[i][q]]]++;
		}
		if (cnt[i][0] == 0 || cnt[i][1] == 0) {
			next.push(i);
		}
	}
	while (next.empty() == false) {
		int now = next.front();
		next.pop();
		if (removed[now] == false) {
			removed[now] = true;
			for (int q = 0; q < vertexs[now].size(); ++q) {
				cnt[vertexs[now][q]][input[now]]--;
				if (removed[vertexs[now][q]] == false&&cnt[vertexs[now][q]][input[now]] == 0) {
					next.push(vertexs[now][q]);
				}
			}
		}
	}
	REP(i, n) {
		if (removed[i+1] == 0) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}