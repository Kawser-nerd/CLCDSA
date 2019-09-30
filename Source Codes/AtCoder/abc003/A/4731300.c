#include <stdio.h>
int main (void)
{
	int t,i;
	int wage=0;
	int total_wage,expect;
	scanf("%d",&t);

	for(i=1;i<=t;i++){
	wage = i * 10000;
	total_wage = total_wage + wage;
	}
	expect = total_wage / t;
	printf("%d\n",expect);
	return 0;

} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&t);
  ^