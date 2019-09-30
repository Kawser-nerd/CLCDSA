#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef long long ll;

int n;
ll dat[1000][3];

bool C(double t);

int main(int argc, char const *argv[]) {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> dat[i][0] >> dat[i][1] >> dat[i][2];

	double lb = 0, ub = INT_MAX;

	for(int i = 0; i < 10000; i++) {
		double mid = (ub + lb) / 2.0;
		if(C(mid)) ub = mid;
		else lb = mid;
	}

	cout << setprecision(30) << ub << endl;
	return 0;
}

bool C(double t) {
	double left = INT_MIN, right = INT_MAX, bottom = INT_MIN, top = INT_MAX;
	for(int i = 0; i < n; i++) {
		double cost = (double)dat[i][2];
		left = max(left, (double)dat[i][0] - t / cost);
		right = min(right, (double)dat[i][0] + t / cost);
		bottom = max(bottom, (double)dat[i][1] - t / cost);
		top = min(top, (double)dat[i][1] + t / cost);
	}
	return (left <= right) && (bottom <= top);
}