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

void Show(vector<int> N) {
	for (int i = 0; i < N.size(); i++) {
		cout << N[i];
		if (i != N.size() - 1) {
			cout << " ";
		} else {
			cout << endl;
		}
	}
}


int main() {
	string A, B;
	cin >> A >> B;
	int N = stoi(A + B);
	for (int i = 1; i <= 100100; i++) {
		if (N%i == 0 && N / i == i) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}