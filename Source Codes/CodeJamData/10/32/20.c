#include<stdio.h>
#include<math.h>
int main()
{
int test,k,i,j,q,a,b,c,p,t;
freopen("a.in","r",stdin);
freopen("output.txt","w",stdout);
scanf("%d",&test);
for(k=0;k<test;k++)
{
p=0;
	scanf("%d%d%d",&a,&b,&c);
	t=c;
	q=b;
	while(1)
	{
		if(a*c>=q) break;
		p++;
		q=ceil(sqrt(a*q));
	    
	}
	
	printf("Case #%d: %d\n",k+1,p);
	
}
}
