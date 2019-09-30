#include <stdio.h>



int main(void)
{
	//?????
	int n;
	signed int i=0;
	signed int array[50];
	int amari;
	
	//????????
	scanf("%d",&n);
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	while(n!=0){
		i++;
		array[i]=n%-2;
		if(array[i]==-1){
			n=n/-2+1;
			array[i]=1;
		}else{
			n=n/-2;
		}
	}
		
	
//	printf("??????\n");
	
	//??
	if(i==0){
		printf("0");
	}else{
		while(i>0){
			printf("%d",array[i]);
			i--;
		}
	}
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^