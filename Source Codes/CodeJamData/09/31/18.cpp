#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int TESTS;

int main()
{
	freopen ("A-large.in", "rt", stdin);
	freopen ("A-large.out", "wt", stdout);

	cin >> TESTS;
	for (int test = 1; test <= TESTS; ++test)
	{
		string s;
		cin >> s;
		map <char, int> digits;
		for (int i = 0; i < s.size(); ++i)
			digits[s[i]] = -1;
		int size = digits.size();
		if (size == 1) size = 2;
		long long ans = 0, next = 0;
		digits[s[0]] = 1;
		for (int i = 0; i < s.size(); ++i) {
			long long a = digits[s[i]];
			if (a == -1) {
				digits[s[i]] = a = next;
				++next;
				if (next == 1) ++next;
			}
			ans = ans * size + a;
		}
		cout << "Case #" << test << ": " << ans << endl;
	}

	return 0;
}