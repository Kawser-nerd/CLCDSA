#include <cstdio>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int n, l;
string s[110], b;

void doit() {
	scanf("%d%d", &n, &l);
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	cin >> b;
	for (int i = 1; i <= n; i++)
		if (b == s[i]) {
			printf("IMPOSSIBLE\n");
			return ;
		}
	if (l == 1) {
		if (b[0] == '1')
			printf("0 0?\n");
		else
			printf("1 1?\n");
		return ;
	}
	// }else {
	// 	printf("0");
	// 	for (int i = 1; i < l; i++) printf("?");
	// 	printf(" ");
	// 	for (int i = 1; i <= 30; i++)
	// 		printf("01");
	// 	printf("0?");
	// 	for (int i = 1; i <= 30; i++)
	// 		printf("10");
	// 	printf("\n");
	// }
	for (int i = 0; i < l - 1; i++)
		if (b[i] == '0')
			printf("10");
		else
			printf("01");
	printf(" ");
	for (int i = 0; i < l; i++) {
		if (b[i] == '1')
			printf("0");
		else
			printf("1");
		printf("?");
	}
	printf("\n");
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: " , i);
		doit();
	}
}
