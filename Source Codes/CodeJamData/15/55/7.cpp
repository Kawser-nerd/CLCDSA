#include <iostream>
using namespace std;

int flows[5000];

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, D;

		cin >> N >> D;
		bool bad = false;
		for (int i = 0; i < N; i++) {
			cin >> flows[i];
			if (i > 2 * D && flows[i] != flows[i-2*D]) bad = true;
		}

		int farmers = 0;
		for (int l = D; l >= 1; l /= 2) {
			for (int i = 0; i < l; i++) {
				int net = flows[i+l]-flows[i]-flows[i+l-1]+flows[(i+2*l-1)%(2*l)];
				if (net % 2) bad = true;
				net /= 2;

				if (net > 0) {
					farmers += net;
					for (int j = i+l; j < i+2*l; j++) {
						flows[j%(2*l)] -= net;
					}
				} else {
					farmers -= net;
					for (int j = i; j < i+l; j++) {
						flows[j%(2*l)] += net;
					}
				}
			}
		}

		cout << "Case #" << t << ": ";
		if (bad || flows[0] < 0) {
			cout << "CHEATERS!\n";
			continue;
		}
		cout << farmers << '\n';
	}

	return 0;
}
