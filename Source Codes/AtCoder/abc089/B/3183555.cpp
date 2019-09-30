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
	array<bool, 4> Arare;
	for (int i = 0; i < 4; i++) {
		Arare[i] = false;
	}
	int N;
	cin >> N;
	char c;
	for (int i = 0; i < N; i++) {
		cin >> c;
		switch (c) {
			case 'G':
				Arare[0] = true;
				break;
			case 'P':
				Arare[1] = true;
				break;
			case 'Y':
				Arare[2] = true;
				break;
			case 'W':
				Arare[3] = true;
				break;
			defaut:
				break;
		}
	}
	int Count = 0;
	for (int i = 0; i < 4; i++) {
		if (Arare[i])Count++;
	}
	if (Count == 3)	cout << "Three" << endl;
	if (Count == 4)	cout << "Four" << endl;
}