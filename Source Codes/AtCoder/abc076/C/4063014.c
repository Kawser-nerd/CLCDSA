#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s[51],t[51];
	scanf("%s%s",s,t);
	int i,j,count,a,b,x=0,index;
	a=strlen(s);
	b=strlen(t);
	for(i=0;i<a;i++)
	{
    	count=0;
		for(j=0;j<b;j++)
		{
			if((s[i+j]==t[j])||(s[i+j]=='?'))
				count++;
		}
		if(count==b)
		{
			x++;
			index=i;
		}
	}
	
	if(x==0) printf("UNRESTORABLE");
	else
	{
		for(j=0;j<b;j++)
		{
			s[index+j]=t[j];
		}
		for(i=0;i<a;i++)
		{
			if(s[i]=='?')
				s[i]='a';
		}
		printf("%s",s);
	}
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s",s,t);
  ^