#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, K;
ll x[50], y[50], ans = INT64_MAX;

int main() {
	cin >> n >> K;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll maxx, minx, maxy, miny;
			maxx = max(x[i], x[j]);
			minx = min(x[i], x[j]);
			maxy = max(y[i], y[j]);
			miny = min(y[i], y[j]);
			//cout << "maxx:" << maxx << " minx:" << minx << " maxy:" << maxy << " miny:" << miny << endl;

			int count = 0;
			for (int k = 0; k < n; k++) {
				if (maxx >= x[k] && x[k] >= minx && maxy >= y[k] && y[k] >= miny)count++;
			}
			if (count >= K) {
				ans = min(ans, abs(maxx - minx)*abs(maxy - miny));
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				ll maxx, minx, maxy, miny;
				maxx = max(max(x[i], x[j]),x[k]);
				minx = min(min(x[i], x[j]),x[k]);
				maxy = max(max(y[i], y[j]),y[k]);
				miny = min(min(y[i], y[j]),y[k]);
				//cout << "maxx:" << maxx << " minx:" << minx << " maxy:" << maxy << " miny:" << miny << endl;

				int count = 0;
				for (int l = 0; l < n; l++) {
					if (maxx >= x[l] && x[l] >= minx && maxy >= y[l] && y[l] >= miny)count++;
				}
				if (count >= K) {
					ans = min(ans, abs(maxx - minx)*abs(maxy - miny));
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				for (int l = k + 1; l < n; l++) {
					ll maxx, minx, maxy, miny;
					maxx = max(max(x[i], x[j]), max(x[k], x[l]));
					minx = min(min(x[i], x[j]), min(x[k], x[l]));
					maxy = max(max(y[i], y[j]), max(y[k], y[l]));
					miny = min(min(y[i], y[j]), min(y[k], y[l]));
					//cout << "maxx:" << maxx << " minx:" << minx << " maxy:" << maxy << " miny:" << miny << endl;

					int count = 0;
					for (int m = 0; m < n; m++) {
						if (maxx >= x[m] && x[m] >= minx && maxy >= y[m] && y[m] >= miny)count++;
					}
					if (count >= K) {
						ans = min(ans, abs(maxx - minx)*abs(maxy - miny));
					}
				}
			}
		}
	}

	cout << ans << endl;
}