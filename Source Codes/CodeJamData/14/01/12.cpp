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

ofstream fout ("QA.out");
ifstream fin ("QA.in");

bool possible[16];

int main() {
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Working on Case #" << t << endl;
		for (int i = 0; i < 16; i++) possible[i] = false;
		int row;
		fin >> row;
		row--;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int a;
				fin >> a;
				a--;
				if (i == row) possible[a] = true;
			}
		}
		int cnt = 0;
		int ans = 0;
		fin >> row;
		row--;
		for (int i = 0; i < 4; i++) {
			for (int j = 0 ; j < 4; j++) {
				int a;
				fin >> a;
				a--;
				if (i == row) {
					if (possible[a]) {
						cnt++;
						ans = a+1;
					}
				}
			}
		}
		fout << "Case #" << t << ": ";
		if (cnt == 1) fout << ans << endl;
		else if (cnt == 0) fout << "Volunteer cheated!" << endl;
		else fout << "Bad magician!" << endl;
	}
    return 0;
}