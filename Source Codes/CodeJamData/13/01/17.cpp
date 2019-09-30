#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char map[5][5];

bool check(char ch) {
	bool flag = false;
	for (int i = 0; i < 4; ++i) {
	  flag = true;
		for (int j = 0; j < 4; ++j) {
	    if (map[i][j] != ch && map[i][j] != 'T') flag = false;
		}
		if (flag) return true;
	}
	for (int i = 0; i < 4; ++i) {
	  flag = true;
		for (int j = 0; j < 4; ++j) {
	    if (map[j][i] != ch && map[j][i] != 'T') flag = false;
		}
		if (flag) return true;
	}
	flag = true;
	for (int i = 0; i < 4; ++i) {
	  if (map[i][i] != ch && map[i][i] != 'T') flag = false;
	}
	if (flag) return true;
	flag = true;
	for (int i = 0; i < 4; ++i) {
	  if (map[i][3 - i] != ch && map[i][3 - i] != 'T') flag = false;
	}
	return flag;
}

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for (int V = 1; V <= T; ++V) {
	  for (int i = 0; i < 4; ++i) {
	    scanf("%s", map[i]);
		}
		printf("Case #%d: ", V);
		if (check('X')) {
			printf("X won\n");
		} else if (check('O')) {
			printf("O won\n");
		} else {
		  bool flag = false;
			for (int i = 0; i < 4; ++i) {
		    for (int j = 0; j < 4; ++j) {
		      if (map[i][j] == '.') flag = true;
				}
			}
			if (flag) {
			  printf("Game has not completed\n");
			} else {
			  printf("Draw\n");
			}
		}		
	}
	return 0;
}

