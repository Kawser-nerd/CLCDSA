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



void Show(vector<bool>& Ps) {
	for (int i = 0; i < Ps.size(); i++) {
		if (Ps[i]) {
			cout << "T" << endl;
		} else {
			cout << "F" << endl;
		}
	}
}

void Show(vector<vector<int>>& Ns) {
	for (int i = 0; i < Ns.size(); i++) {
		for (int j = 0; j < Ns[i].size(); j++) {
			cout << Ns[i][j] << " ";
		}
		cout << endl;
	}
}


int main() {
	int N;
	cin >> N;
	cout << N / 3 << endl;
}