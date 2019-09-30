#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#include <cmath>
#include <sstream>
using namespace std;

int main()
{
	int a,b,ans;
	string A,B,s;
	ostringstream ss;
	cin >> a >> b;
	A = to_string(a);
	B = to_string(b);

	ss << A << B;
	s = A + B;
	ans = stoi(s);
	ans = ans * 2;

	cout << ans << endl;

	return 0;
}