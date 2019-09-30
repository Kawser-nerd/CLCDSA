#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#include <cmath>
using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	if (A + B == C && A - B == C) {
		cout << "?" << endl;
	}
	else if (A + B == C) {
		cout << "+" << endl;
	}
	else if (A - B == C) {
		cout << "-" << endl;
	}
	else {
		cout << "!" << endl;
	}

	return 0;
}