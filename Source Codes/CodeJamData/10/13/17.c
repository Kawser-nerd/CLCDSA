#include <stdio.h>
void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int check(int a, int b)
{
	if(a < b)
		swap(&a, &b);
	int c;
	int d;
	int flag = 1;

	for(c = a % b; c>0; c = a % b)
	{
		if ((a/b) > 1 && flag == 1) return 1;
		if ((a/b) > 1 && flag == 0) return 0;
		a = b;
		b = c;
		flag = 1-flag;
	}
		if ((a/b) > 1 && flag == 1) return 1;
		if ((a/b) > 1 && flag == 0) return 0;
	return 0;
}

int main(void)
{
	freopen("input", "rt", stdin);
	freopen("output", "wt", stdout);
	
	int testcase, caseid;
	scanf("%d", &testcase);

	int a1,a2,b1,b2,a,b;
	int count;
	for (caseid=1; caseid<=testcase; caseid++)
	{
		printf("Case #%d:", caseid);
		scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
		count=0;
	for(a=a1;a<=a2;a++)
			for(b=b1;b<=b2;b++)
				count+=check(a,b);
		printf(" %d\n",count);
	}

	return 0;
}
