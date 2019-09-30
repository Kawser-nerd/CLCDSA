#include<iostream>
using namespace std;
int main() {
	int X = 1;
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N;i++){
		if(X*2 < X+K) X *= 2;
		else X += K;
	}
	cout << X << endl;
	return 0;
}