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

struct {
	char curr;		/* 1 = AND, 0 = OR */
	char orig;
	char changable;	
} interiors[100000];
char exteriors[100000];
int M,V;
int num_ints;
#define LEFT(x) ((((x+1)*2)+0)-1)
#define RIGHT(x) ((((x+1)*2)+1)-1)

int compute(int node)
{
	int l,r;
	if (node >= num_ints) {
		return exteriors[node-num_ints];
	}
	l = compute(LEFT(node));
	r = compute(RIGHT(node));
	if (interiors[node].curr) {
		return l&r;
	} else {
		return l|r;
	}
}


int tryx(int node, int val)
{
	int l,r,op,x;
	int num_changed =   1000000000;
	int first = 1;
	int first_changed = 1000000000;
	int i,j;
	if (node >= num_ints) {
		return (compute(node) == val) ? 0 : -1;
	}
	l = compute(LEFT(node));
	r = compute(RIGHT(node));
	op = interiors[node].curr;
	if (op) {
		x = l&r;
	} else {
		x = l|r;
	}
	if (x == val) {
		/* already there */
		return 0;
	}
	if (interiors[node].changable) {
		if (!op) {
			x = l&r;
		} else {
			x = l|r;
		}
		if (x == val) {
			return 1;
		}
	}
retry: ;
	if (op && val) {
		/* AND, want 1 */
		if (l) {
			i = tryx(RIGHT(node), 1);
			if ((i > 0) && (i < num_changed)) {
				num_changed = i;
			}
		} else if (r) {
			i = tryx(LEFT(node), 1);
			if ((i > 0) && (i < num_changed)) {
				num_changed = i;
			}
		} else {
			i = tryx(RIGHT(node), 1);
			if ((i > 0) && (i < num_changed)) {
				j = tryx(LEFT(node), 1);
				if (j > 0) {
					i += j;
					if ((i > 0) && (i < num_changed)) {
						num_changed = i;
					}
				}
			}
		}
	} else if (op && !val) {
		i = tryx(LEFT(node), 0);
		if ((i > 0) && (i < num_changed)) {
			num_changed = i;
		}
		i = tryx(RIGHT(node), 0);
		if ((i > 0) && (i < num_changed)) {
			num_changed = i;
		}
	} else if (!op && val) {
		i = tryx(LEFT(node), 1);
		if ((i > 0) && (i < num_changed)) {
			num_changed = i;
		}
		i = tryx(RIGHT(node), 1);
		if ((i > 0) && (i < num_changed)) {
			num_changed = i;
		}
	} else if (!op && !val) {
		if (!l) {
			i = tryx(RIGHT(node), 0);
			if ((i > 0) && (i < num_changed)) {
				num_changed = i;
			}
		} else if (!r) {
			i = tryx(LEFT(node), 0);
			if ((i > 0) && (i < num_changed)) {
				num_changed = i;
			}
		} else {
			i = tryx(RIGHT(node), 0);
			if ((i > 0) && (i < num_changed)) {
				j = tryx(LEFT(node), 0);
				if (j > 0) {
					i += j;
					if ((i > 0) && (i < num_changed)) {
						num_changed = i;
					}
				}
			}
		}
	}
	if (interiors[node].changable && first) {
		first = 0;
		first_changed = num_changed;
		num_changed = 1000000000;
		op = !op;
		goto retry;
	}
	if (!first) {
		num_changed++;
		if (first_changed < num_changed) {
			num_changed = first_changed;
		}
	}
	if (num_changed == 1000000000) {
		return -1;
	}
	return num_changed;
}

int main(void)
{
	int N = read_int();
	int i,j,k;
	for (i = 0; i < N; i++) {
		char buf[10000];
		char *s = buf;
		fgets(buf, 1000, stdin);
		M = read_intx(&s);
		V = read_intx(&s);
		num_ints = (M-1)/2;
		for (j = 0; j < num_ints; j++) {
			fgets(buf, 1000, stdin);
			s=buf;
			interiors[j].curr = interiors[j].orig = read_intx(&s);
			interiors[j].changable = read_intx(&s);
		}
		for (j = 0; j < (M+1)/2; j++) {
			exteriors[j] = read_int();
		}
		k = tryx(0,V);
		if (k == -1) {
			printf ("Case #%d: IMPOSSIBLE\n", i+1);
		} else {
			printf ("Case #%d: %d\n", i+1,k);
		}
	}
	return 0;
}
