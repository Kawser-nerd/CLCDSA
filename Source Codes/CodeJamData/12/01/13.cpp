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
#include <numeric>

using namespace std;

// Speaking in Tongues

int main()
{
	string mapping = "yhesocvxduiglbkrztnwjpfmaq";
	string line;

	int cases;
	cin >> cases;
	getline(cin, line);

	for (int caseno = 1; caseno <= cases; caseno++) {
		getline(cin, line);
		string ret;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] >= 'a' && line[i] <= 'z') {
				ret += (char)(mapping[line[i] - 'a']);
			} else if (line[i] == ' ') {
				ret += ' ';
			}
		}
		cout << "Case #" << caseno << ": " << ret << endl;
	}

	return 0;
}
