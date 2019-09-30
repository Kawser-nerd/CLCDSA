#include<stdio.h>
#include<string.h>
char shu[3000],shubh[3000];
int main()
{
int test,m,i,start,end;
scanf("%d",&test);
m=test;
while(m--)
{
start=1002;end=1002;
scanf("%s",shu);
for(i=0;shu[i];i++)
	{
	if(i==0)shubh[start]=shu[i];
	else if(shu[i]>=shubh[start])
		{
		shubh[--start]=shu[i];
		}
	else if(shu[i]<shubh[start])
		{
		shubh[++end]=shu[i];
		}
	}
	shubh[end+1]='\0';
	printf("Case #%d: %s\n",test-m,shubh+start);
}
return 0;
}
