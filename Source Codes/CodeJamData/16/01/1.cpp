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

bool used[100];
int T, x, C;

void kk(int x) {
	while (x) {
		used[x % 10] = true;
		x /= 10;
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &x);
		printf("Case #%d: ", ++C);
		if (!x)
			printf("INSOMNIA\n");
		else {
			memset(used, false, sizeof used);
			for (int i = 1; ; i++) {
				kk(i * x);
				int c = 0;
				for (int j = 0; j < 10; j++)
					c += int(used[j]);
				if (c == 10) {
					printf("%d\n", i * x);
					break;
				}
			}
		}
	}
}
