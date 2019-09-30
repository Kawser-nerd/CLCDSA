#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	//?????
	int h,w;
	static int a[510][510];
	static int map[510][510];
	int i,j;
	int flag=0;
	int ans;
	int count=0;
	//????????
	scanf("%d %d",&h,&w);
	
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			scanf("%d",&a[i][j]);
		}
	}
		
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	for(i=0;i<h;i++){
		for(j=0;j<w-1;j++){
			if(a[i][j]%2==1){
				map[i][j]=1;
				a[i][j]--;
				a[i][j+1]++;
				count++;
			}
		}
		
		if(i!=h-1&&a[i][w-1]%2==1){
			map[i][w-1]=1;
			a[i][w-1]--;
			a[i+1][w-1]++;
			count++;
		}
	}
	
	
	
//	printf("??????\n");
	//??
	
	printf("%d\n",count);
	for(i=0;i<h;i++){
		for(j=0;j<w-1;j++){
			if(map[i][j]==1){
				printf("%d %d %d %d\n",i+1,j+1,i+1,j+2);
			}
		}
		if(map[i][w-1]==1){
			printf("%d %d %d %d\n",i+1,w,i+2,w);
		}
	}
	
//	printf("???????\n");
	
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&h,&w);
  ^
./Main.c:23:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&a[i][j]);
    ^