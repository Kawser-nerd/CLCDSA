#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		double D;
		int N, A;
		cin >> D >> N >> A;
		vector<double > time(N), position(N);
		for (int i=0; i<N; i++)
			cin >> time[i] >> position[i];
		N--;
		while (N>1 && position[N-1]>D) N--;
		/*if (N>0)*/ {
			double f = (D - position[N-1]) / (position[N]-position[N-1]);
			//position[N] = position[N-1] + f*(position[N]-position[N-1]);
			position[N] = D;
			time[N] = time[N-1] + f*(time[N]-time[N-1]);
			N++;
		}
		cout << "Case #" << t << ":\n";
		for (int i=0; i<A; i++) {
			double a;
			cin >> a;
			double waitTime = 0;
			for (int i=0; i<N; i++) {
				double myTime = sqrt(2*position[i]/a);
				double minTime = time[i]-myTime;
				if (waitTime<minTime) waitTime = minTime;
			}
			double rideTime = sqrt(2*D/a);
			cout.precision(16);
			cout << (waitTime+rideTime) << endl;
		}
	}
	return 0;
}
