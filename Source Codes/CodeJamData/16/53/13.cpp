#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int T;
int N, S;
double xi[1010], yi[1010], zi[1010], vx[1010], vy[1010], vz[1010];

pair<double, double> valid_time(int p, int q, double d)
{
	double rx = xi[q] - xi[p], ry = yi[q] - yi[p], rz = zi[q] - zi[p];
	double rvx = vx[q] - vx[p], rvy = vy[q] - vy[p], rvz = vz[q] - vz[p];
	if (fabs(rvx) < 1e-6 && fabs(rvy) < 1e-6 && fabs(rvz) < 1e-6) {
		if (rx * rx + ry * ry + rz * rz <= d) return{ 0.0, 1e10 };
		else return { -1.0, -1.0 };
	}

	double a = (rvx * rvx + rvy * rvy + rvz * rvz);
	double b = (rvx * rx + rvy * ry + rvz * rz);
	double c = (rx * rx + ry * ry + rz * rz) - d;

	if (b * b - a * c < 0) return{ -1.0, -1.0 };
	double sq = sqrt(b * b - a * c);
	return{ (-b - sq) / a, (-b + sq) / a };
}

double tmin[1010][1010], tmax[1010][1010];

int n_look[1010];
bool enabled[1010][1010];
set<pair<int, int> > waiting[1010];

bool resolve(int p, int q)
{
	enabled[p][q] = true;
	++n_look[p];
	++n_look[q];
	if (n_look[p] == 1) {
		for (auto a : waiting[p]) {
			int u = a.first, v = a.second;
			waiting[u + v - p].erase(a);
			resolve(u, v);
		}
	}
	if (n_look[q] == 1) {
		for (auto a : waiting[q]) {
			int u = a.first, v = a.second;
			waiting[u + v - q].erase(a);
			resolve(u, v);
		}
	}
}

bool isok(double d)
{
	//printf("%f\n", d);
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			auto a = valid_time(i, j, d);
			tmin[i][j] = tmin[j][i] = max(0.0, a.first);
			tmax[i][j] = tmax[j][i] = a.second;
			//printf("%d--%d: %f %f\n", i, j, tmin[i][j], tmax[i][j]);
		}
	}

	vector<pair<double, pair<int, int> > > act;
	for (int i = 0; i < N; ++i) {
		waiting[i].clear();
		for (int j = i + 1; j < N; ++j) {
			enabled[i][j] = false;
			if (tmax[i][j] < -1e-6) continue;
			act.push_back({ tmin[i][j],{ i, j } });
			act.push_back({ S + tmax[i][j],{ ~i, j } });
		}
	}

	for (int i = 0; i < N; ++i) n_look[i] = 0;

	act.push_back({ (double)S, {~0, 0} });
	n_look[0] += 2;
	enabled[0][0] = true;
	sort(act.begin(), act.end());
	for (auto a : act) {
		int p = a.second.first, q = a.second.second;
		if (n_look[1] > 0) return true;
		if (p < 0) {
			p = ~p;
			waiting[p].erase({ p, q });
			waiting[q].erase({ p, q });
			if (enabled[p][q]) {
				--n_look[p];
				--n_look[q];
			}
		} else {
			if (n_look[p] || n_look[q]) {
				/*
				enabled[p][q] = true;
				++n_look[p];
				++n_look[q];

				for (auto a : waiting[p]) {
					int u = a.first, v = a.second;
					enabled[u][v] = true;
					++n_look[u];
					++n_look[v];
					waiting[u + v - p].erase(a);
				}
				waiting[p].clear();
				for (auto a : waiting[q]) {
					int u = a.first, v = a.second;
					enabled[u][v] = true;
					++n_look[u];
					++n_look[v];
					waiting[u + v - q].erase(a);
				}
				waiting[q].clear();
				*/
				resolve(p, q);
			} else {
				waiting[p].insert({ p, q });
				waiting[q].insert({ p, q });
			}
		}
		if (n_look[1] > 0) return true;
	}
	for (int i = 0; i < N; ++i) {
		if (n_look[i] > 0) {
			fprintf(stderr, "><\n");
		}
	}
	return false;
}

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;){
		scanf("%d%d", &N, &S);
		for (int i = 0; i < N; ++i) {
			scanf("%lf%lf%lf%lf%lf%lf", xi + i, yi + i, zi + i, vx + i, vy + i, vz + i);
		}

		double left = 0, right = 1e7;
		for (int i = 0; i < 50; ++i) {
			double mid = (left + right) / 2;
			if (isok(mid)) {
				right = mid;
			} else {
				left = mid;
			}
		}

		printf("Case #%d: %f\n", t, sqrt(left));
	}

	return 0;
}
