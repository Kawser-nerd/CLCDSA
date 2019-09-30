#include<iostream>
#include<unordered_map>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int a[6];
signed main() {
	int S; cin >> S;
	for (int b = 1; b <= 6; b++)a[b - 1] = b;
	for (int i = 0; i <S; i++) {
		swap(a[i % 5], a[i % 5 + 1]);
	}
	for (int j : a)cout << j;
	cout << endl;
}