#include <stdio.h>

int main(void)
{
	char s[200001], t[200001], s1, t1;
	int n = 0, a[200], b[200];
	scanf("%s%s", s, t);
	while(s[n] != '\0') n++;

	for (int i = 0; i < 200; ++i) {
		a[i] = 0;
		b[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		a[(int)s[i]] += 1;
		b[(int)t[i]] += 1;
	}

	for (int i = 0; i < 200; ++i) {
		if (a[i] > 1) {
			for (int j = 0; j < n-1; ++j) {
				if ((int)s[j] == i) {
					t1 = t[j];
					for (int k = j+1; k < n; ++k) {
						if ((int)s[k] == i) {
							if (t[k] != t1) {
								printf("No\n");
								return 0;
							}
						}
					}
					break;
				}
			}
		}
	}
	for (int i = 0; i < 200; ++i) {
		if (b[i] > 1) {
			for (int j = 0; j < n-1; ++j) {
				if ((int)t[j] == i) {
					s1 = s[j];
					for (int k = j+1; k < n; ++k) {
						if ((int)t[k] == i) {
							if (s[k] != s1) {
								printf("No\n");
								return 0;
							}
						}
					}
					break;
				}
			}
		}
	}
	printf("Yes\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s", s, t);
  ^