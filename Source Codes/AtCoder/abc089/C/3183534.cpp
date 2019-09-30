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
	array<int, 5> MARCH;
	for (int i = 0; i < 5; i++) {
		MARCH[i] = 0;
	}
	int N;
	long long Count = 0;
	cin >> N;
	string S;
	for (int i = 0; i < N; i++) {
		cin >> S;
		if (S[0] == 'M')MARCH[0]++;
		if (S[0] == 'A')MARCH[1]++;
		if (S[0] == 'R')MARCH[2]++;
		if (S[0] == 'C')MARCH[3]++;
		if (S[0] == 'H')MARCH[4]++;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			long long C = 1;
			for (int k = 0; k < 5; k++) {
				if (k != i && k != j) {
					C *= MARCH[k];
				}
			}
			Count += C;
		}
	}
	cout << Count << endl;
}