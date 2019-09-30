#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPL(i,f,n) for(int i=f, i##_len=(n); i<i##_len; ++i)
typedef long long ll;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H,W;
	char s[60][60];
	cin >> H >> W;
	REP(i, H) {
		scanf("%s",&s[i]);
	}
	bool ans = true;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	REP(i, H) {
		REP(j, W) {
			if (s[i][j] == '#') {
				bool found = false;
				REP (k, 4) {
					int i2 = i + dx[k];
					int j2 = j + dy[k];
					if (i2 >= 0 && i2 < H 
						&& j2 >= 0 && j2 < W && s[i2][j2] == '#') {
						found = true;
					}
				}
				if (!found) {
					ans = false;
					break;
				}
			}
		}
	}
	cout << (ans?"Yes":"No") << endl;
	return 0;
} ./Main.cpp:22:14: warning: format specifies type 'char *' but the argument has type 'char (*)[60]' [-Wformat]
                scanf("%s",&s[i]);
                       ~~  ^~~~~
1 warning generated.