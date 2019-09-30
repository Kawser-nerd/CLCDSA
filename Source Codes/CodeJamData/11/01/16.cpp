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

int BotTrust(vector <char> robot, vector <int> button)
{
	int pos[2] = {1, 1};
	int margin[2] = {0, 0};
	int ret = 0;
	for (int i = 0; i < robot.size(); i++) {
		int r = robot[i] == 'O' ? 0 : 1;
		int t = max(abs(button[i] - pos[r]) - margin[r], 0) + 1;
		ret += t;
		pos[r] = button[i];
		margin[r] = 0;
		margin[1 - r] += t;
	}
	return ret;
}


int main()
{
	string line;

	int cases;
	cin >> cases;

	for (int caseno = 1; caseno <= cases; caseno++) {
		int N;
		cin >> N;
		vector <char> robot(N);
		vector <int> button(N);
		for (int i = 0; i < N; i++) {
			cin >> robot[i] >> button[i];
		}
		cout << "Case #" << caseno << ": " << BotTrust(robot, button) << endl;
	}

	return 0;
}
