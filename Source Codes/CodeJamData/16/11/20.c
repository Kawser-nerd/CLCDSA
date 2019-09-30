#include<stdio.h>
char s[10000];
void func(int i)
{
	if(s[i]=='\0')
		return;
	if(s[i]>=s[0])
	{
		char temp=s[i];
		int j;
		for(j=i;j>0;j--)
		{
				s[j]=s[j-1];
		}
		s[0]=temp;
	}
	func(i+1);
}
int main()
{
int t,i;
scanf("%d",&t);
for(i=1;i<=t;i++)
{
scanf("%s",s);
func(1);
printf("Case #%d: %s\n",i,s);
}
return 0;
}
