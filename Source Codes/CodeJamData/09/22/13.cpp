#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);

	int ts;
	cin >> ts;
	for (int t=0; t<ts; ++t) {
		string s;
		cin >> s;
		if (!next_permutation (s.begin(), s.end())) {
			int cnt0 = 0;
			while (s[0] == '0')
				++cnt0,  s.erase (0, 1);
			s.insert (1, "0");
			while (cnt0)
				s.insert (1, "0"),  cnt0--;
		}
		cout << "Case #" << t+1 << ": " << s << endl;
	}

}
