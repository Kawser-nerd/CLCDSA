#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

// Dancing With the Googlers

int main()
{
	string line;

	int cases;
	cin >> cases;

	for (int caseno = 1; caseno <= cases; caseno++) {
		int N, S, p;
		cin >> N >> S >> p;
		vector <int> score(N);
		for (int i = 0; i < N; i++) {
			cin >> score[i];
		}
		sort(score.begin(), score.end(), greater<int>());
		int ret = 0;
		for (int i = 0; i < N; i++) {
			if (score[i] >= p * 3 - 2) {
				ret++;
			} else if (p > 1 && score[i] >= p * 3 - 4 && S > 0) {
				ret++;
				S--;
			}
		}
		cout << "Case #" << caseno << ": " << ret << endl;
	}

	return 0;
}
