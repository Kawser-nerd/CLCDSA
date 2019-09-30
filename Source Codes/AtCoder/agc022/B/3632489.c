#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	//?????
	int n;
	
	//??????
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp,temp1,temp2;
	//????????
	scanf("%d",&n);
	
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	if(n<8){
		if(n==3) printf("2 5 63");
		if(n==4) printf("2 5 20 63");
		if(n==5) printf("2 3 4 6 9");
		if(n==6) printf("2 3 4 6 9 12");
		if(n==7) printf("2 3 4 6 8 9 10");
		
		return 0;
	}
	
	j=0;
	for(i=n;i>0;i=i-8){
		if(i>=8){
			if(j!=0) printf(" ");
			printf("%d %d %d %d %d %d %d %d",j+2,j+3,j+4,j+6,j+8,j+9,j+10,j+12);
			j=j+12;
		}else if(i%2==1){
			printf(" %d",j+6);
			i--;
		}
		if(i==2){
			printf(" %d %d",j+2,j+4);
		}else if(i==4){
			printf(" %d %d %d %d",j+2,j+3,j+4,j+9);
		}else if(i==6){
			printf(" %d %d %d %d %d %d",j+2,j+3,j+4,j+8,j+9,j+10);
		}
	}
	
	
	
//	printf("??????\n");
	//??
	
	//printf("%d",ans);
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^