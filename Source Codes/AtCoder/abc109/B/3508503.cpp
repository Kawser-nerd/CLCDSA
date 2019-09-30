#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int length;
	vector<string> words;

	cin >> length;
	string str;
	while (cin >> str) {
		words.push_back(str);
	}

	bool isFailed = false;
	bool isFirst = true;
	string last = "";
	for (int i = 0; i < length; ++i) {
		bool isExist = false;
		for (int j = 0; j < length; ++j) {
			if (i != j && words[j] == words[i]) {
				isExist = true;
				break;
			}
		}

		if (!isFirst && (isExist || last != words[i].substr(0, 1))) {
			isFailed = true;
			break;
		}
		isFirst = false;
		last = words[i].substr(words[i].size() - 1);
	}

	if (isFailed) {
		cout << "No\n";
	}
	else {
		cout << "Yes\n";
	}

	return 0;
}