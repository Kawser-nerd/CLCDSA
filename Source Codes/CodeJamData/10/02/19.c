#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAXBIGNUM	1024

void rev(char v[])
{
	int i, n = strlen(v), tmp;
	for (i = 0; i < n / 2; i++)
		tmp = v[i], v[i] = v[n - i - 1], v[n - i - 1] = tmp;
}

void add(char v1[], char v2[])
{
	int i, d, c = 0;
	int l1 = strlen(v1), l2 = strlen(v2);
	for (i = l1; i < l2; i++) v1[i] = '0';
	for (i = l2; i < l1; i++) v2[i] = '0';
	for (i = 0; i < l1 || i < l2; i++) {
		d = (v1[i] - '0') + (v2[i] - '0') + c;
		c = d / 10; d %= 10;
		v1[i] = d + '0';
	}

	for ( ; c; c /= 10, i++) v1[i] = (c % 10) + '0';
	v1[i] = v2[l2] = '\0';
}

void subtract(char v1[], char v2[])
{
	int i, d, c = 0;
	int l1 = strlen(v1), l2 = strlen(v2);
	for (i = l2; i < l1; i++) v2[i] = '0';
	for (i = 0; i < l1; i++) {
		d = (v1[i] - '0') - (v2[i] - '0') - c;
		if (d < 0) {
			d += 10;
			c = 1;
		} else {
			c = 0;
		}
		v1[i] = d + '0';
	}
	v2[l2] = '\0';
	for (i = l1 - 1; i > 0 && v1[i] == '0'; i--) {}
	v1[i + 1] = '\0';
}

int comp(const char v1[], const char v2[])
{
	int i, l1 = strlen(v1), l2 = strlen(v2);
	if (l1 > l2) return 1;
	if (l1 < l2) return -1;
	for (i = l1 - 1; i >= 0; i--) {
		if (v1[i] > v2[i]) return 1;
		if (v1[i] < v2[i]) return -1;
	}
	return 0;
}

void multiply(char v1[], char v2[], char v[])
{
	static char tmp[MAXBIGNUM];
	static char tmpd[10][MAXBIGNUM], bs[MAXBIGNUM];
	int i, l2 = strlen(v2);

	bs[0] = '\0';
	tmpd[0][0] = '0'; tmpd[0][1] = '\0';
	for (i = 1; i < 10; i++) {
		strcpy(tmpd[i], tmpd[i - 1]);
		add(tmpd[i], v1);
	}
	v[0] = '0'; v[1] = '\0';
	for (i = 0; i < l2; i++) {
		strcpy(tmp, bs);
		bs[i] = '0'; bs[i + 1] = '\0';
		strcat(tmp, tmpd[v2[i] - '0']);
		add(v, tmp);
	}
}

void divide(char v1[], char v2[], char q[], char r[])
{
	static char tmp1[MAXBIGNUM];
	int i, l, ff = 1;
	if (strcmp(v2, "1") == 0) {
		strcpy(q, v1);
		strcpy(r, "0");
		return;
	}
	if (strcmp(v1, "0") == 0) {
		q[0] = r[0] = '0';
		q[1] = r[1] = '\0';
		return;
	}

	for (i = 0; v1[i]; i++) q[i] = '0';
	q[i] = '\0';
	l = i;
	for (i = l - 1; i >= 0; i--) {
		for ( ; ; ) {
			if (q[i] == '9') break;
			q[i]++;
			multiply(q, v2, r);
			if (comp(r, v1) > 0) {
				q[i]--;
				break;
			}
			ff = 0;
		}
		if (ff && i) q[i] = '\0';
	}
	multiply(v2, q, tmp1);
	strcpy(r, v1);
	subtract(r, tmp1);
}

int gcd_(int a, int b)
{
	int r;
	if (b == 0) return a;
	while (r = a % b) a = b, b = r;
	return b;
}

/* Greatest common divisor */
void gcd(const char *x, const char *y, char *r)
{
	static char a[MAXBIGNUM], b[MAXBIGNUM], q[MAXBIGNUM], t[MAXBIGNUM];
	
	if (y[0] == '0' && y[1] == '\0') {
		strcpy(r, x);
		return;
	}
	
	strcpy(a, x);
	strcpy(b, y);
	
	for ( ; ; ) {
		divide(a, b, q, t);
		if (t[0] == '0' && t[1] == '\0')
			break;
		strcpy(a, b);
		strcpy(b, t);
	}
	
	strcpy(r, b);	
}

int main(int argc, char *argv[])
{
	int nc, ci;
	int n, i;
	static char t[1024][64], d[1024][64], q[128], r[128], s[128];
	
	scanf("%d", &nc);
	for (ci = 0; ci < nc; ci++) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%s", t[i]);
			rev(t[i]);
			if (i == 0) continue;
			if (comp(t[i - 1], t[i]) < 0) {
				strcpy(d[i - 1], t[i]);
				subtract(d[i - 1], t[i - 1]);
			} else {
				strcpy(d[i - 1], t[i - 1]);
				subtract(d[i - 1], t[i]);
			}
		}
		
		strcpy(r, d[0]);
		for (i = 1; i < n - 1; i++)
			gcd(r, d[i], r);
		
		divide(t[0], r, q, s);
		if (s[0] == '0' && s[1] == '\0') {
			printf("Case #%d: 0\n", ci + 1);
		} else {
			subtract(r, s);
			rev(r);
			printf("Case #%d: %s\n", ci + 1, r);
		}
	}

	return 0;
}
