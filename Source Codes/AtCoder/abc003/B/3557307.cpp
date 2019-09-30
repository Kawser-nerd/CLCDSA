#include <iostream>
#include <string>
#include <map>
using namespace std;

#define rep(i, n) for(int i = 0;i <= n; i++)

int main() {
	map<char, int> score;
	score['a'] = 1;
	score['t'] = 1;
	score['c'] = 1;
	score['o'] = 1;
	score['d'] = 1;
	score['e'] = 1;
	score['r'] = 1;
	score['@'] = 10;
	string S, T;
	cin >> S >> T;
	int f = 0;
	bool flags = true;
	rep(i, S.length()) {
		int s = 0;
		int t = 0;
		if (S[i] == T[i]) continue;
		else if (score[S[i]] + score[T[i]] >= 11) continue;
		else {
			flags = false;
			break;
		}
	}

	if (flags) {
		cout << "You can win" << endl;
	}
	else {
		cout << "You will lose" << endl;
	}

	system("pause");
	return 0;
}