#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string x;
	cin >> x;
	int zero=0, one=0;
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] == '0') zero++;
		else one++;
	}
	
	cout << 2*min(one, zero) << endl;
	
	return 0;
}