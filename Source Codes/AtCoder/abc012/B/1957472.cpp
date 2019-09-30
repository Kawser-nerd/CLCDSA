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
	int in; 
	int h = 0; 
	int m = 0; 
	int s = 0; 
	string hh, mm, ss;

	cin >> in;

	while (in >= 3600) { 
		if (h < 24) {
			in -= 3600;
			h++;
		}
	}

	while (in >= 60) { 
		in -= 60;
		m++;
	}

	s = in; 
	
	hh = to_string(h);
	mm = to_string(m);
	ss = to_string(s);

	if (hh.length() == 1) {
		hh = "0" + hh;
	}
	if (mm.length() == 1) {
		mm = "0" + mm;
	}
	if (ss.length() == 1) {
		ss = "0" + ss;
	}
	cout << hh << ":" << mm << ":" << ss << endl;

	return 0;
}