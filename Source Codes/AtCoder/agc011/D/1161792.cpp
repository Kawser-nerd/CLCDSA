#include<cstdio>

char s[400000];
int main()
{
	int i=0,n,k;bool f=false;
	scanf("%d%d%s",&n,&k,s);
	while(i<n&&k--)
		if((s[i]=='A')^f)s[i]=f?'A':'B';
		else f^=1,s[n+i++]=f?'B':'A';
	if(++k)
	{
		if(n&1)putchar((s[i]=='A')^f^(k&1)?'B':'A');
		for(i=0;i<n>>1;i++)
			putchar('B'),putchar('A');
	}
	else
		if(f)
			for(int j=0;j<n;j++)
				putchar(s[i+j]=='A'?'B':'A');
		else
			puts(s+i);
}