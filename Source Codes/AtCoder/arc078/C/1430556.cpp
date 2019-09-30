#include <iostream>
#include <string>

using namespace std;

string check(string s, int x) {
	string tmp = std::to_string(x);
	cout << "? " << (s + tmp) << endl;
	cin >> tmp;
	return tmp;
}

void add(string &prefix, int x) {
	string tmp = std::to_string(x);
	prefix = prefix + tmp;
}

string build(string prefix, int last) {
	string tmp = std::to_string(last);
	tmp = prefix + tmp;
	while (tmp.size() < 15) {
		tmp.push_back('9');
	}
	return tmp;
}

int main() {
	string prefix = "";
	while (true) {
		int r = 10;
		int l = 0;
		if (prefix == "") {
			l = 1;
		}
		string v9 = check(prefix, 9);
		bool last = false;
		if (v9 == "Y") {
			string v80 = check(prefix, 80);
			if (v80 == "N") {
				cout << "! " << prefix << "9" << endl;
				return 0;
			}
			string vlast = "";
			if (l == 0)
				vlast = check(prefix + "0", 0);
			else
				vlast = check(prefix, 10);
			if (vlast == "Y") {
				if (check(build(prefix, l), 9) == "Y") {
					cout << "! " << prefix << l << endl;
					return 0;
				} else {
					add(prefix, 9);
					continue;
				}
			}
			last = true;
		}
		if (!last) {
			r--;
			while (r - l > 1) {
				int mid = (r + l) / 2;
				if (check(prefix, mid) == "Y")
					l = mid;
				else
					r = mid;
			}
			add(prefix, l);
			continue;
		}
		l++;
		while (r - l > 1) {
			int mid = (r + l) / 2;
			if (check(prefix, (mid - 1) * 10 + 0) == "N") {
				l = mid;
			} else
				r = mid;
		}
		cout << "! " << prefix << l << endl;
		return 0;
	}
	return 0;
}