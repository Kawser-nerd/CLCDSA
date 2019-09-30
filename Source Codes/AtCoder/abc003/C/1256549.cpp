#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<double> ve;
int main() {
	int N, K;
	cin >> N >> K;
	double input;
	while (cin >> input) {
		ve.push_back(input);
	}
	sort(ve.begin(), ve.end());
	double ans = 0.0;
	for (int i = N-K;i < N;i++) {
		ans+=ve[i];
		ans/=2.0;
	}
	cout << fixed << setprecision(6) <<ans << endl;
	return 0;
}