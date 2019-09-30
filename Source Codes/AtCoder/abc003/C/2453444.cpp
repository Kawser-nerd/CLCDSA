#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	int N,K;
  vector<double> vd;
  double R;
	cin >> N >> K;
	while (cin >> R) {
		vd.push_back(R);
	}

	sort(vd.begin(), vd.end());
	double ans=0.0;
	for (int i=N-K; i<N; i++) {
		ans += vd[i];
		ans /= 2.0;
	}

	cout << fixed << setprecision(6) << ans << endl;
	return 0;
}