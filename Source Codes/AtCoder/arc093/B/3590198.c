#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	//?????
	int a,b;
	int i,j,k;
	
	//????????
	scanf("%d %d",&a,&b);
	
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	if(a==1&&b==1){
		printf("2 2\n##\n..");
	}else if(a!=1&&b!=1){
		printf("100 100\n");
		a=a-2;
		b=b-2;
		for(i=0;i<50;i++){
			for(j=0;j<50;j++){
				if(i%2==0&&j%2==0){
					if(a>0){
						printf(".");
						a=a-1;
					}else{
						printf("#");
					}
				}else{
					printf("#");
				}
			}
			for(j=0;j<50;j++){
				if(i%2==0&&j%2==1){
					if(b>0){
						printf("#");
						b=b-1;
					}else{
						printf(".");
					}
				}else{
					printf(".");
				}
			}
			printf("\n");
		}
		for(i=0;i<50;i++){
			for(j=0;j<50;j++){
				printf(".");
			}
			for(j=0;j<50;j++){
				printf("#");
			}
			printf("\n");
		}
	}else if(a==1){
		printf("100 100\n");
		b=b-1;
		for(i=0;i<50;i++){
			for(j=0;j<50;j++){
				printf("#");
			}
			for(j=0;j<50;j++){
				if(i%2==0&&j%2==1){
					if(b>0){
						printf("#");
						b=b-1;
					}else{
						printf(".");
					}
				}else{
					printf(".");
				}
			}
			printf("\n");
		}
		for(i=0;i<50;i++){
			for(j=0;j<50;j++){
				printf("#");
			}
			for(j=0;j<50;j++){
				printf("#");
			}
			printf("\n");
		}
	}else{
		printf("100 100\n");
		a=a-1;
		for(i=0;i<50;i++){
			for(j=0;j<50;j++){
				if(i%2==0&&j%2==0){
					if(a>0){
						printf(".");
						a=a-1;
					}else{
						printf("#");
					}
				}else{
					printf("#");
				}
			}
			for(j=0;j<50;j++){
				printf(".");
			}
			printf("\n");
		}
		for(i=0;i<50;i++){
			for(j=0;j<50;j++){
				printf(".");
			}
			for(j=0;j<50;j++){
				printf(".");
			}
			printf("\n");
		}
	}
	
	
		
//	printf("??????\n");
	
	//??
	
	//	printf("%ld",ans);
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&a,&b);
  ^