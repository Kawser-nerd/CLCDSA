#include<stdio.h>
 
int main(void){
	int a[3][3],i,j,flag=1;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			if(a[i][j] - a[i+1][j] != a[i][j+1] - a[i+1][j+1]){
				flag = 0;
			}
		}
	}
	flag ? printf("Yes\n") : printf("No\n");
} ./Main.c: In function ‘main’:
./Main.c:7:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&a[i][j]);
    ^