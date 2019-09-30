#include <stdio.h>
#include <stdlib.h>
long min_l(long n, long m);

int main(void)
{
	long n, m, p1, p2, q1, q2, l;
	int err;
	char *s, *t;
	err=scanf("%ld%ld", &n, &m);
	if (err!=2) exit(1);
	s = (char *)malloc(sizeof(char)*(int)n);
	t = (char *)malloc(sizeof(char)*(int)m);
	err=scanf("%s\n%s", s, t);
	if (err!=2) exit(1);

	l=min_l(n, m);
	p1=l/n;
	q1=l/m;
	p2=0;
	q2=0;
	while((q2<n)&&(p2<m))
	{
		if (s[q2]!=t[p2])
		{
			printf("%d\n", -1);
			return 0;
		}
		p2+=p1;
		q2+=q1;
	}
	printf("%ld\n", l);
	free(s);
	free(t);
	return 0;
}

long min_l(long n, long m){
	long answer, a, b, r = 1;
	if (n >= m)
	{
		a = n;
		b = m;
	}else
	{
		a = m;
		b = n;
	}
	while (r != 0)
	{
		r = a%b;
		a = b;
		b = r;
	}
	answer = n * m / a;
	return answer;
}