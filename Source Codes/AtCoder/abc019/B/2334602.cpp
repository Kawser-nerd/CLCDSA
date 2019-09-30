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
	string s;
	int count = 1;
	
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[i + 1]) {
			cout << s[i] << count;
			count = 1;
		}
		else if(s[i] == s[i+1]){
			count++;
		if (s.size() - 1 == i) {
			cout << s[i] << count;
		}
		}
	}

	cout << endl;

	return 0;
}