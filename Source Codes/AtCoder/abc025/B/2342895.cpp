#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#include <cmath>
#include <sstream>
#include <set>  

using namespace std;

int main()
{
	int n, a, b, d;
	int ans = 0;
	string s;
	string East = "East";
	string West = "West";

	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		cin >> s >> d;
		if (s == "East") {
			if (d < a) {
				ans += a;
			}
			else if (b < d) {
				ans += b;
			}
			else {
				ans += d;
			}
		}
		else {
			if (d < a) {
				ans -= a;
			}
			else if (b < d) {
				ans -= b;
			}
			else {
				ans -= d;
			}
		}
	}
	if (ans > 0) {
		cout << East << " " <<ans <<  endl;
	}
	else if(ans < 0){
		cout << West << " "<<ans * -1 << endl;
	}
	else if (ans == 0) {
		cout << 0 << endl;

	}
	return 0;
}