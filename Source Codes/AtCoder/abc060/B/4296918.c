#include <stdio.h>

int main(void)
{
	int a,b,c,i;
	scanf("%d%d%d",&a,&b,&c);
	for(i;i<b;i++)
		{
		if(a*(b+i)%b==c){printf("YES"); break;}
		else if(i==b-1 && a*(b+i)%b!=c){printf("NO");}
		}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^