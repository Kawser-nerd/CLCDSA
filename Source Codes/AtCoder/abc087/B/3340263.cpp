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


int main() {
	int X;
	array<int, 3> Coins;
	array<int, 3> Prices = { 500,100,50 };
	for (int i = 0; i < 3; i++) {
		cin >> Coins[i];
	}
	cin >> X;
	queue<int> State;
	State.push(X);
	for (int i = 0; i < 3; i++) {
		queue<int> Next;
		int N = State.size();
		for (int j = 0; j < N; j++) {
			int n = State.front();
			State.pop();
			for (int k = 0; k <= Coins[i]; k++) {
				if (i == 2) {
					if (n == k * Prices[i])Next.push(0);
				} else {
					if (n >= k*Prices[i])Next.push(n - k * Prices[i]);
				}
			}
		}
		State = Next;
	}
	cout << State.size() << endl;
}