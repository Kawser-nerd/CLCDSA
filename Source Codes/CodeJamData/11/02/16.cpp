#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

string Magicka(vector <string> combine, vector <string> opposed, string invoked)
{
	string list = "";
	for (int i = 0; i < invoked.size(); i++) {
		char c = invoked[i];
		for (int j = 0; j < combine.size(); j++) {
			for (int k = 0; k < 2; k++) {
				if (combine[j][k] == c && 
				    list.size() > 0 && combine[j][1 - k] == list[list.size() - 1]) {
					list = list.substr(0, list.size() - 1);
					c = combine[j][2];
				}
			}
		}
		bool clear = false;
		for (int j = 0; j < opposed.size(); j++) {
			for (int k = 0; k < 2; k++) {
				if (opposed[j][k] == c && list.find(string(1, opposed[j][1 - k])) != string::npos) {
					clear = true;
				}
			}
		}
		if (clear) {
			list = "";
		} else {
			list += c;
		}
	}
	return list;
}


int main()
{
	string line;

	int cases;
	cin >> cases;

	for (int caseno = 1; caseno <= cases; caseno++) {
		int C, D, N;
		cin >> C;
		vector <string> combine(C);
		for (int i = 0; i < C; i++) {
			cin >> combine[i];
		}
		cin >> D;
		vector <string> opposed(D);
		for (int i = 0; i < D; i++) {
			cin >> opposed[i];
		}
		string invoke;
		cin >> N >> invoke;
		string ret = Magicka(combine, opposed, invoke);
		cout << "Case #" << caseno << ": [";
		for (int i = 0; i < ret.size(); i++) {
			cout << ret[i] << ((i + 1 < ret.size()) ? ", " : "");
		}
		cout << "]" << endl;
	}

	return 0;
}
