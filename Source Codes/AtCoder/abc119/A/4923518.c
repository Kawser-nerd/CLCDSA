#include<stdio.h>

int main(void)
{
	int yyyy,mm,dd;

	scanf("%d/%d/%d",&yyyy,&mm,&dd);
	if(yyyy<=2018){
		printf("Heisei\n");
	}else if((yyyy<=2019) && (mm>=5)){
		printf("TBD\n");
	}else if((yyyy==2019) && (mm>=1) && (mm<=4)){
		printf("Heisei\n");
	}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d/%d/%d",&yyyy,&mm,&dd);
  ^