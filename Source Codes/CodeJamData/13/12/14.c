#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long int E,Ein,R,N,V[10000];
long int ans;
void printCase(int i)
{
	printf("Case #%d: ",i+1);
}

void execute()
{
	long int i;
	long int length;
	length=E/R;
	if(E%R) length++;
	for(i=0;i<N;i++)
	{
		long int j;
		for(j=0;j<=length && i+j<N && V[i]>=V[i+j];j++);
		
		if(i+j==N || j>length)
		{
			ans=ans+V[i]*E;
			E=R;
		}
		else
		{
			if(Ein-E > (j)*R)
			{	
				E=E+(j)*R;
				if(E>Ein)
				{
					ans=ans+V[i]*(E-Ein);
					E=Ein;
				}
				i=i+j-1;
			}
			else
			{
			
				if(Ein-j*R >= 0)
				{
					ans=ans+V[i]*(E-(Ein-(j)*R));
					E=Ein;
					i=i+j-1;
				}
				else 
				{
					ans=ans+V[i]*E;
					E=R;
				}
				
			}
		}
	}
}

int main()
{
	int cases,k;
	
	scanf("%d",&cases);
	for(k=0;k<cases;k++)
	{
		long int i;
		ans=0;
		scanf("%ld",&Ein);
		scanf("%ld",&R);
		scanf("%ld",&N);
		E=Ein;
		for(i=0;i<N;i++)
		{
			scanf("%ld",&V[i]);
		}
		if(R>=E)
		{
			for(i=0;i<N;i++)
			ans=ans+V[i]*E;
		}
		else execute();
		printCase(k);
		printf("%ld\n",ans);
	}
	return 0;
}
