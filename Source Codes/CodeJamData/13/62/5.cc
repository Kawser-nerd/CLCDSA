#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void hull(const vector<int>& v, vector<int>& hx, vector<int>& hy, int mul) {
	for (int i = 0; i < v.size(); i++) {
		if (hx.size() >= 2) {
			int x1 = hx[hx.size()-2], x2 = hx[hx.size()-1], x3 = i;
			int y1 = hy[hy.size()-2], y2 = hy[hy.size()-1], y3 = v[i];
			if ((long long)(x2-x1)*(y3-y2)*mul >=
					(long long)(y2-y1)*(x3-x2)*mul) {
				hx.pop_back();
				hy.pop_back();
				i--;
				continue;
			}
		}
		hx.push_back(i);
		hy.push_back(v[i]);
	}
}

main() {
	int T, prob=1;
	for (cin >> T; T--;) {
		int N;
		scanf("%d", &N);
		vector<int> v(N);
		for (int i = 0; i < N; i++) scanf("%d", &v[i]);
		vector<int> ux, uy, dx, dy;
		hull(v, ux, uy, 1);
		hull(v, dx, dy, -1);

/*for (int i = 0; i < ux.size(); i++) cout << ux[i] << ',' << uy[i] << ' ';
cout << endl;
for (int i = 0; i < dx.size(); i++) cout << dx[i] << ',' << dy[i] << ' ';
cout << endl;
cout << endl;*/

		double ret = 1e18;
		for (int i = ux.size()-2, j = 0; i >= 0; i--) {
			while (j+1 < dx.size() &&
					(long long)(dy[j+1]-dy[j])*(ux[i+1]-ux[i]) <=
					(long long)(uy[i+1]-uy[i])*(dx[j+1]-dx[j])) {
				j++;
			}
			double y = uy[i] + (uy[i+1]-uy[i])/(double)(ux[i+1]-ux[i])*(dx[j]-ux[i]);
//cout << ux[i] << ',' << uy[i] << '-' << ux[i+1] << ',' << uy[i+1];
//cout << ": " << y << ' ' << dy[j] << endl;
			ret = min(ret, (y-dy[j])/2);
		}
		for (int i = dx.size()-2, j = 0; i >= 0; i--) {
			while (j+1 < ux.size() &&
					(long long)(uy[j+1]-uy[j])*(dx[i+1]-dx[i]) >=
					(long long)(dy[i+1]-dy[i])*(ux[j+1]-ux[j])) {
				j++;
			}
			double y = dy[i] + (dy[i+1]-dy[i])/(double)(dx[i+1]-dx[i])*(ux[j]-dx[i]);
//cout << dx[i] << ',' << dy[i] << '-' << dx[i+1] << ',' << dy[i+1];
//cout << ": " << uy[j] << ' ' << y << endl;
			ret = min(ret, (uy[j]-y)/2);
		}
		printf("Case #%d: %.9lf\n", prob++, ret);
	}
}
