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

/* *2 */
#define AREA (((x3-x1)*(y2-y1))-((x2-x1)*(y3-y1)))
int main(void)
{
	int C = read_int();
	int i,j,k,l,m;
	int x1,x2,x3;
	int y1,y2,y3;
	int N,M,A;
	for (i = 0; i < C; i++) {
		char buf[1000];
		char *s=buf;
		fgets(s, 1000, stdin);
		N=read_intx(&s);
		M=read_intx(&s);
		A=read_intx(&s);
		for (j = 0; j <= N; j++) {
			x1 = j;
			y1 = 0;
			for (k = 0; k <= M; k++) {
				x2 = 0;
				y2 = k;
				for (l = 0; l <= N; l++) {
					x3 = l;
					for (m = 0; m <= M; m++) {
						y3 = m;
						if (AREA == A) {
							printf("Case #%d: %d %d %d %d %d %d\n",i+1,x1,y1,x2,y2,x3,y3);
							goto done;
						}
					}
				}
			}
		}
		printf("Case #%d: IMPOSSIBLE\n",i+1);
done: ;
	}

	return 0;
}
