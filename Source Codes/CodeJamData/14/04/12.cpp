#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define pii pair<int,int>

ofstream fout ("QD.out");
ifstream fin ("QD.in");

double w1[1005],w2[1005];
int N;

int play() {
	int i1 = 0,i2 = 0;
	int passed = 0;
	for (i2 = 0; i2 < N; i2++) {
		while (i1 != N && w1[i1] < w2[i2]) i1++;
		if (i1 != N) {
			i1++;
			passed++;
		}
	}
	return passed;
}

int main() {
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Working on Case #" << t << endl;
		fin >> N;
		for (int i = 0; i < N; i++) fin >> w1[i];
		for (int i = 0; i < N; i++) fin >> w2[i];
		sort(w1,w1+N);
		sort(w2,w2+N);
		fout << "Case #" << t << ": " << play();
		for (int i = 0; i < N; i++) {
			double temp = w1[i];
			w1[i] = w2[i];
			w2[i] = temp;
		}
		fout << " " << (N-play()) << endl;
	}
    return 0;
}