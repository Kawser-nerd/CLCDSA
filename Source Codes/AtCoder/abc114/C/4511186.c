#include <stdio.h>
long long all[30000];
long long max=999999999;
int allcount=0;
int check(long long num)
{
	int have3=0;
	int have5=0;
	int have7=0;
	long long now=num;
	while(now!=0)
	{
		if(now%10==3)
		{
			have3=1;
		}
		else if(now%10==5)
		{
			have5=1;
		}
		else
		{
			have7=1;
		}
		now/=10;
	}
	if(have3==1&&have5==1&&have7==1)
	{
		return 1;
	}
	return 0;
}
void getall(long long now)
{
	if(now>max)
		return;
	if(check(now)==1)
	{
		all[allcount]=now;
		allcount++;
	}
	getall(now*10+3);
	getall(now*10+5);
	getall(now*10+7);
}
int cmp(const void*a,const void*b)
{
	long long la=*(long long*)a;
	long long lb=*(long long*)b;
	if(la>=lb)
		return 1;
	else
		return -1;
}
int main()
{
	int i,j;
	long long time;
	getall(3);
	getall(5);
	getall(7);
	qsort(all,allcount,sizeof(all[0]),&cmp);
	scanf("%lld",&time);
	for(i=0;i<allcount;i++)
	{
		if(all[i]<=time)
		{
			continue;
		}
		else
		{
			break; 
		}
	}
	printf("%d",i);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:62:2: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
  qsort(all,allcount,sizeof(all[0]),&cmp);
  ^
./Main.c:63:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&time);
  ^