#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

void work() {
	int X, Y;
	cin >> X >> Y;
	// E:+1,W-1
	if (X < 0) {
		for (int i = 0; i < abs(X); ++i) {
			cout << "EW";
		}
	} else {
		for (int i = 0; i < X; ++i) {
			cout << "WE";
		}
	}
	// N:+1 S-1
	if (Y < 0) {
		for (int i = 0; i < abs(Y); ++i) {
			cout << "NS";
		}
	} else {
		for (int i = 0; i < Y; ++i) {
			cout << "SN";
		}
	}
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		work();
	}
}
