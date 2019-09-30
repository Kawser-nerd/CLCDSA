/*
 * 16-5-14_ARC053_B.cpp
 *
 *  Created on: 2016/05/14
 *      Author: ryoma
 */

#include <iostream>
#include <string.h>
#include <map>
#include <set>
using namespace std;

map<char, int> smap;
set<char> sset;
char a[100001];
int ans, odd, even, center = 1;
int main() {
	cin >> a;
	for (int i = 0; i < strlen(a); i++) {
		int num = ++smap[a[i]];
		//sset.insert(a[i]);
		if (num & 1) {
			odd++;
		} else {
			odd--;
			even++;
		}
	}
	//for (std::set<char>::iterator itr = sset.begin(); itr != sset.end(); itr++) {
	//int num = smap[*itr];
	//odd += num & 1;
	//even += num / 2;
	//}
	if (odd == 0) {
		odd = 1;
		center = 0;
	}
	ans = (even / odd) * 2 + center;
	//cout << odd << endl;
	//cout << even << endl;
	cout << ans << endl;
	return 0;
}