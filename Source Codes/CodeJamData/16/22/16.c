#include <stdio.h>
#include <math.h>
#include <string.h>

int match(int x, char *s1)
{
	char s2[1000];
	int n1, n2, i;
	
	n1=strlen(s1);
	
	if(n1==1) sprintf(s2, "%01d", x);
	if(n1==2) sprintf(s2, "%02d", x);
	if(n1==3) sprintf(s2, "%03d", x);
	
	n2=strlen(s2);
	
	if(n1!=n2) return 0;
	
	for(i=0;i<n1;i++)
	{
		if(s1[i]!='?' && s1[i]!=s2[i]) return 0;
	}
	return 1;
}

int main()
{
	int i,j,k,m,n;
	int T,t;
	int a,b;
	int best, best_a, best_b;
	
	char s[2][20];

	fscanf(stdin, "%d", &T);
	for(t=1;t<=T;t++)
	{
		fscanf(stdin, "%s", s[0]);
		fscanf(stdin, "%s", s[1]);
		n=strlen(s[0]);
		best=9999;
		
		//printf("%d  %s  %s\n", n, s[0], s[1]);
		for(a=999;a>=0;a--)
		{
			if(!match(a,s[0])) continue;
			for(b=999;b>=0;b--)
			{
				if(!match(b,s[1])) continue;
				if(abs(a-b)<=best)
				{
					best=abs(a-b);
					best_a = a;
					best_b = b;
				}
			}
		}
		
		printf("Case #%d: ", t);
		if(n==1) printf("%d %d\n",best_a,best_b);
		if(n==2) printf("%02d %02d\n",best_a,best_b);
		if(n==3) printf("%03d %03d\n",best_a,best_b);
		
	}
	
	return 0;
}