#include <algorithm>
#include <array>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <functional>
#include <queue>

//AtCoderC++.cpp

using namespace std;

void Show(vector<vector<int>> Ns) {
	for (int i = 0; i < Ns.size(); i++) {
		for (int j = 0; j < Ns[i].size(); j++) {
			if (j == Ns[i].size() - 1) {
				cout << Ns[i][j] << endl;
			} else {
				cout << Ns[i][j] << ",";
			}			
		}
	}
}
void Show(array<char,26> Ns) {
	for (int i = 0; i < 26; i++) {
		cout <<'a' +i  << "->" << Ns[i]  << endl;
	}
}


int main() {
	int X, A, B;
	cin >> X >> A >> B;
	cout << (X - A) % B << endl;
}