#include <stdio.h>
#include <stdlib.h>

int main() {
	int t, n, m, p, o, e, i, j, k, tmp, trip[2005], man[2005], cur, loss, ans, table[105];
	int stack[2005], top;
	scanf("%d", &t);
	for(k = 0; k < t; k++) {
		scanf("%d %d", &n, &m);
		loss = 0, ans = 0, top = 0;

		//init table
		table[0] = 0;
		for(i = 1; i < 105; i++) {
			table[i] = (table[i - 1] + n - i + 1) % 1000002013;
		}

		for(i = 0; i < m; i++) {
			scanf("%d %d %d", &o, &e, &p);
			trip[i * 2] = o;
			man[i * 2] = p;
			trip[i * 2 + 1] = -e;
			man[i * 2 + 1] = p;
			ans = (ans + table[e - o] * p) % 1000002013;
		}
		for(i = 0; i < 2 * m; i++) {
			for(j = 2 * m - 1; j > i; j--) {
				if(abs(trip[j]) < abs(trip[j - 1])) {
					tmp = trip[j];
					trip[j] = trip[j - 1];
					trip[j - 1] = tmp;
					tmp = man[j];
					man[j] = man[j - 1];
					man[j - 1] = tmp;
				}
				else if(abs(trip[j]) == abs(trip[j - 1]) && trip[j] > trip[j - 1]) {
					tmp = trip[j];
					trip[j] = trip[j - 1];
					trip[j - 1] = tmp;
					tmp = man[j];
					man[j] = man[j - 1];
					man[j - 1] = tmp;
				}
			}
		}
		for(i = 0; i < 2 * m; i++) {
			if(trip[i] < 0) {
				while(man[i]) {
					if(man[i] >= man[stack[top - 1]]) {
						man[i] -= man[stack[top - 1]];
						cur -= man[stack[top - 1]];
						loss = (loss + table[-trip[i] - trip[stack[top - 1]]] * man[stack[top - 1]]) % 1000002013;
						top--;
					}
					else {
						loss = (loss + table[-trip[i] - trip[stack[top - 1]]] * man[i]) % 1000002013;
						man[stack[top - 1]] -= man[i];
						cur -= man[i];
						man[i] = 0;
					}
				}
			}
			else {
				cur += man[i];
				stack[top++] = i;
			}
		}
		printf("Case #%d: %d\n", k + 1, (ans - loss) % 1000002013);
	}
	return 0;
}
