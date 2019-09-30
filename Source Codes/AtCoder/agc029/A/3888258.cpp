#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
	string S;
	cin >> S;
	long long sumCount = 0;
	long long countW = 0;
	for (int k = 0;k < S.length();++k) {
		if (S[k] == 'W'){
			sumCount += countW;			
		}
		else {
			++countW;
		}
	}
	cout << sumCount << endl;
	system("pause");
}