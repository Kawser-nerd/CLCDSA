#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		ll all = 0;
		char s[50];
		scanf("%s", s);
		int d = strlen(s);
		int combos = (int) pow(3.0, (double) (d-1));
		for (int cc = 0; cc < combos; cc++) {
			ll sum = 0;
			ll sign = +1;
			ll current = s[0]-'0';
			int c = cc;
			for (int i = 1; i < d; i++) {
				int code = c % 3;
				c/= 3;
				switch (code) {
					case 0:
						current = current * 10 + (s[i]-'0');
						break;
					case 1:
						sum += sign * current;
						current = s[i]-'0';
						sign = +1;
						break;
					case 2:
						sum += sign * current;
						current = s[i] - '0';
						sign = -1;
						break;
				}
			}
			sum += sign * current;
			if (sum % 2 == 0 || sum % 3 == 0 || sum % 5 == 0 || sum % 7 == 0) all++;
		}
		cout << "Case #" << tc << ": " << all << endl;
	}
	return 0;
}
