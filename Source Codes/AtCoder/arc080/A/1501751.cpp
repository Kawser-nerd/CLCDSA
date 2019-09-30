#include <iostream>
#include <cstring>
using namespace std;

int mp[3];
int n, x;

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		memset(mp, 0, sizeof(mp));
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x % 4 == 0)
				mp[2]++;
			else if (x % 2 == 0)
				mp[1]++;
			else
				mp[0]++;
		}
		if (mp[1] > 0)
			mp[0]++;
		if (mp[0] - 1 > mp[2])
			cout << "No\n";
		else
			cout << "Yes\n";
	}
	return 0;
}