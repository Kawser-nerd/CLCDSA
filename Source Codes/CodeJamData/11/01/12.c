#include <stdio.h>

int abs(int a) {
	return a < 0 ? -a : a;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int testcase() {
	int total = 0;
	int timeB = 0, timeO = 0;
	int currB = 1, currO = 1;
	int ops;
	char who[4], last = 'X';
	int where;
	scanf("%d", &ops);
	while(ops--) {
		scanf("%s%d", who, &where);
		switch(who[0]) {
			case 'B':
				if(last == 'B') {
					timeB += abs(where - currB) + 1;
				} else {
					timeB = max(timeO, timeB + abs(where - currB)) + 1;
				}
				currB = where;
				break;
			case 'O':
				if(last == 'O') {
					timeO += abs(where - currO) + 1;
				} else {
					timeO = max(timeB, timeO + abs(where - currO)) + 1;
				}
				currO = where;
				break;
		}
		last = who[0];
	}
	return max(timeB, timeO);
}

int main() {
	int T, i;
	scanf("%d", &T);
	for(i = 1; i <= T; i++)
		printf("Case #%d: %d\n", i, testcase());
	return 0;
}
