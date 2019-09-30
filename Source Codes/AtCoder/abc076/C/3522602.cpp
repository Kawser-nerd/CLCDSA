#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <math.h>
#include <cmath>
#include <set>   
#include <bitset>
//#include <boost/math/common_factor_rt.hpp>

#define ll long long
#define MAX 100000
using namespace std;
ll L = 1000000007;

int main()
{
	string s, t;
	cin >> s >> t;
	for (int i = s.size() - t.size(); i >= 0; i--) {
		//cout<<i<<endl;
		bool ok = true;
		for (int j = 0; j<t.size(); j++) {
			//cout<<s[i+j]<<t[j]<<i<<j<<endl;
			if (s[i + j] != '?'&&s[i + j] != t[j]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			s.replace(i, t.size(), t);
			for (int k = 0; k<s.size(); k++) {
				if (s[k] == '?')cout << 'a';
				else cout << s[k];
			}
			cout << endl;
			return 0;
		}
	}
	cout << "UNRESTORABLE" << endl;
}

int dsum(ll a) {
	int ans = 0;
	while (a != 0) {
		ans += a % 10;
		a /= 10;
	}
	return ans;
}