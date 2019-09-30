#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	int color[13];

	for (int i = 0; i < 13; i++) {
		color[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		int rate;
		cin >> rate;
		color[int(rate / 400)]++;
	}

	int min = 0;
	for (int i = 0; i < 8; i++) {
		if (color[i] > 0) {
			min++;
		}
	}
	if (min == 0) {
		cout << 1;
	}
	else {
		cout << min;
	}
	cout << " ";

	int max = min;
	for (int i = 8; i < 13; i++) {
		max += color[i];
	}
	cout << max;
	return 0;
}