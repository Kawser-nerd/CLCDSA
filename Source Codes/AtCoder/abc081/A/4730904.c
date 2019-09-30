#include<stdio.h>
int main(void)
{
	char mass[3];
	int i,k=0;
	
	scanf("%s",mass);
	
	for(i=0;i<3;i++){
		if(mass[i]=='1'){
			k++;
		}
	}
	printf("\n%d\n\n",k);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",mass);
  ^