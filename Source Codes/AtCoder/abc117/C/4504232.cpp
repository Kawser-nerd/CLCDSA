#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	
	int N, M;
	cin >> N >> M;
	int* X = new int[M];
	for (int i = 0; i < M; i++)
	{
		cin >> X[i];
	}
	sort(X, X + M);
	int* between = new int[M - 1];
	for (int i = 0; i < M - 1; i++)
	{
		between[i] = X[i + 1] - X[i];
	}
	sort(between, between + M - 1);
	int output = 0;
	for (int i = 0; i < M - N; i++)
	{
		output += between[i];
	}
	cout << output << endl;
	

	return 0;
}