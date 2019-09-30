#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int
read_int(void)
{
	char s[1000];
	if (!fgets(s, 1000, stdin)) {
		perror("fgets");
		exit(-1);
	}
	return atoi(s);
}

char *
read_string(void)
{
	char s[1000];
	if (!fgets(s, 1000, stdin)) {
		perror("fgets");
		exit(-1);
	}
	s[strcspn(s,"\r\n")] = 0;
	return strdup(s);
}
void
read_int2(int *x,int *y)
{
	char s[1000];
	char *p;
	if (!fgets(s, 1000, stdin)) {
		perror("fgets");
		exit(-1);
	}
	p = s;
	*x = strtoul(p, &p, 10);
	p++;
	*y = strtoul(p, &p, 10);
}

void
read_int4(int *x,int *y, int *z, int *a)
{
	char s[1000];
	char *p;
	if (!fgets(s, 1000, stdin)) {
		perror("fgets");
		exit(-1);
	}
	p = s;
	*x = strtoul(p, &p, 10);
	p++;
	*y = strtoul(p, &p, 10);
	p++;
	*z = strtoul(p, &p, 10);
	p++;
	*a = strtoul(p, &p, 10);
}
void
read_double5(double *a,double *b,double*c,double*d,double*e)
{
	char s[1000];
	char *p;
	if (!fgets(s, 1000, stdin)) {
		perror("fgets");
		exit(-1);
	}
	p = s;
	*a = strtod(p, &p);
	p++;
	*b = strtod(p, &p);
	p++;
	*c = strtod(p, &p);
	p++;
	*d = strtod(p, &p);
	p++;
	*e = strtod(p, &p);
}

int
read_intx(char **s)
{
	char *p = *s;
	int ret;
	while (isspace(*p)) {
		p++;
	}
	ret = strtoul(p, &p, 10);
	*s = p;
	return ret;
}

int order[100];
int k;
char buf[1000000];

int compute(void)
{
	int i,j = 0;
	int start = 0;
	int ret = 0;
	char last = 0;
	for (i = 0; buf[i]; i++) {
		char c = buf[start+order[j]];
		if (c != last) {
			ret++;
			last = c;
		}
		j++;
		if (j == k) {
			j = 0;
			start = i+1;
		}
	}
	return ret;
}

int tryx(int ofs) {
	int i,j,m;
	int min = 1000000000;
	if (ofs == k) {
		int x = compute();
#if 0
{
printf("%d: \n  ",x);
int y,z=0,start=0;
for (y = 0; y < k; y++) {
printf(" %X",order[y]);
}
printf("\n  ");
for (y = 0; buf[y]; y++) {
char c = buf[start+order[z]];
printf("%c",c);
		z++;
		if (z == k) {
			z = 0;
			start = y+1;
		}
	}
printf("\n");
}
#endif
		return x;
	}
	for (i = 0; i < k; i++) {
		for (j = 0; j < ofs; j++) {
			if (order[j] == i) {
				break;
			}
		}
		if (j == ofs) {
			order[ofs] = i;
		} else {
			continue;
		}
		m = tryx(ofs+1);
		if (m <= min) {
			min = m;
		}
	}
	return min;
}

int main(void)
{
	int N = read_int();
	int i;
	for (i = 0; i < N; i++) {
		k = read_int();
		fgets(buf, 1000000, stdin);
		buf[strcspn(buf,"\r\n")] = 0;
		printf("Case #%d: %d\n",i+1,tryx(0));
	}
	return 0;
}
