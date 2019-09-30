#include <stdio.h>

int main()
{
	int i,j,k,t,m,n,count;
	int T,X,N,head,tail;
	int s[10000];
	
	fscanf(stdin, "%d", &T);
	for(n=1;n<=T;n++)
	{
		fscanf(stdin, "%d%d", &N, &X);
		for(i=0;i<N;i++)
		{
			fscanf(stdin, "%d", &s[i]);
		}
		
		for(i=0;i<N;i++)
		for(j=0;j<i;j++)
		{
			if(s[i]>s[j]) 
			{
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
		}
		
		head=0; tail=N-1; count=0;
		while(head<tail)
		{
			if(s[head]+s[tail]<=X)
			{
				count++;
				head++;
				tail--;
			}
			else
			{
				count++;
				head++;
			}
		}
		if(head==tail) count++;
		printf("Case #%d: %d\n", n, count);
	}	
	
	return 0;
}	