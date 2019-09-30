#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main() {
	ll H, W;
	vector<vector<char>> s;
    cin >> H >> W;

	for(ll i=0; i<H; i++) {
		vector<char> s_row;
		for(ll j=0; j<W; j++) {
			char ss;
			cin >> ss;
			s_row.push_back(ss);
		}
		s.push_back(s_row);
	}

	bool ans = true;
	for(ll i=0; i<H; i++) {
		for(ll j=0; j<W; j++) {
			if( (s[i][j] == '#') &&
				(i==0   || s[i-1][j] == '.' ) &&
				(i==H-1 || s[i+1][j] == '.' ) &&
				(j==0   || s[i][j-1] == '.' ) &&
				(j==W-1 || s[i][j+1] == '.' ) ) {
					ans = false;
				}
		}
	}

	cout << (ans ? "Yes" : "No") << endl;
}