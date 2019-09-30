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

double GoroSort(vector <int> s)
{
	double ret = 0;
	vector <bool> visited(s.size(), false);
	for (int i = 0; i < s.size(); i++) {
		if (!visited[i]) {
			int index = i;
			int loop = 0;
			while (!visited[index]) {
				visited[index] = true;
				index = s[index] - 1;
				loop++;
			}
			ret += (loop == 1) ? 0 : loop;
		}
	}
	return ret;
}


int main()
{
	string line;

	int cases;
	cin >> cases;

	for (int caseno = 1; caseno <= cases; caseno++) {
		int N;
		cin >> N;
		vector <int> s(N);
		for (int i = 0; i < N; i++) {
			cin >> s[i];
		}
		printf("Case #%d: %.6f\n", caseno, GoroSort(s));
	}

	return 0;
}
