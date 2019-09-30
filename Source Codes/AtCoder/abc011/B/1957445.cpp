#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include<cstdio>
#include<functional>
using namespace std;

int main()
{
	string s;

	cin >> s;
	s[0] = toupper(s[0]);
	for (int i = 1; i<s.size(); i++) {
		s[i] = tolower(s[i]);
	}
	cout << s << endl;

	return 0;
}