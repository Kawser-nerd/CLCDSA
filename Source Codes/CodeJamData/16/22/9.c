#include <stdio.h>

typedef long long ll;

char c1[20], c2[20];
char ansc1[20], ansc2[20];
ll ans1, ans2, diff;
int l;

void ltcheck() {
	ll t1 = 0, t2 = 0;
	int i;
	for(i = 0; i < l; i++) {
		t1 *= 10;
		t2 *= 10;
		t1 += (c1[i] == '?') ? 9 : (c1[i] - '0');
		t2 += (c2[i] == '?') ? 0 : (c2[i] - '0');
	}
	//printf("lt: %s %s %lld %lld %lld\n", c1, c2, t1, t2, t2-t1);
	if ((t2 - t1 < diff) || (t2 - t1 == diff && ((t1 < ans1) || (t1 == ans1 && t2 < ans2)))) {
		diff = t2 - t1;
		ans1 = t1;
		ans2 = t2;
	}
}

void gtcheck() {
	ll t1 = 0, t2 = 0;
	int i;
	for(i = 0; i < l; i++) {
		t1 *= 10;
		t2 *= 10;
		t1 += (c1[i] == '?') ? 0 : (c1[i] - '0');
		t2 += (c2[i] == '?') ? 9 : (c2[i] - '0');
	}
	//printf("gt: %s %s %lld %lld %lld\n", c1, c2, t1, t2, t1-t2);
	if ((t1 - t2 < diff) || (t1 - t2 == diff && ((t1 < ans1) || (t1 == ans1 && t2 < ans2)))) {
		diff = t1 - t2;
		ans1 = t1;
		ans2 = t2;
	}
}

int main() {
	int t, T;
	int i, j, flag;
	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		ans1 = 1ll<<62;
		ans2 = 0;
		diff = 1ll<<62;
		flag = 0;
		scanf("%s %s", c1, c2);
		for(l = 0; c1[l] != '\0'; l++);

		for(i = 0; i < l; i++) {
			if(c1[i] == '?' && c2[i] == '?') {
				c1[i] = '0';
				c2[i] = '1';
				ltcheck();
				c1[i] = '1';
				c2[i] = '0';
				gtcheck();
				c1[i] = '0';
				c2[i] = '0';
				continue;
			}
			else if(c1[i] == '?' && c2[i] != '?') {
				if(c2[i] != '0') {
					c1[i] = c2[i] - 1;
					ltcheck();
				}
				if(c2[i] != '9') {
					c1[i] = c2[i] + 1;
					gtcheck();
				}
				c1[i] = c2[i];
				continue;
			}
			else if(c1[i] != '?' && c2[i] == '?') {
				if(c1[i] != '9') {
					c2[i] = c1[i] + 1;
					ltcheck();
				}
				if(c1[i] != '0') {
					c2[i] = c1[i] - 1;
					gtcheck();
				}
				c2[i] = c1[i];
				continue;
			}
			else if(c1[i] == c2[i]) {
				continue;
			}
			else if(c1[i] < c2[i]) {
				ltcheck();
				flag = 1;
				break;
			}
			else if(c1[i] > c2[i]) {
				gtcheck();
				flag = 1;
				break;
			}
			else {
				printf("ERROR!\n");
				flag = 1;
				break;
			}
		}
		if(flag == 0) {
			ltcheck();
		}
		ansc1[l] = ansc2[l] = '\0';
		for(i = 0; i < l; i++) {
			ansc1[l-i-1] = (ans1 % 10) + '0';
			ansc2[l-i-1] = (ans2 % 10) + '0';
			ans1 /= 10;
			ans2 /= 10;
		}
		printf("Case #%d: ", t);
		printf("%s %s", ansc1, ansc2);
		printf("\n");
	}
}
