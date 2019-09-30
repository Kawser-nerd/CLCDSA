#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<string>
using namespace std;

string a[50];
int main() {
	int b; cin >> b;
	for (int c = 0; c < b; c++) {
		cin >> a[c];
	}
	for (int x = 0; x < b; x++) {
		for (int y = 0; y < b; y++) {
			cout << a[b - y - 1][x];
		}
		cout << endl;
	}
}