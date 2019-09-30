#include <stdio.h>

int main() {
	
	char x[110];
	unsigned long long int y;
	int f=0;
	
	scanf("%s", x);
	scanf("%llu", &y);
	
	for(int i=0;i<y;i++)
	{
		if((x[i]-'0')>1)
		{
			printf("%d\n", (x[i]-'0'));
			f=1;
			break;
		}
	}
	
	if(f==0)
	{
		printf("1\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", x);
  ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu", &y);
  ^