#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//?????
	int n;
	int a[60];
	int maxid,minid;
	
	//??????
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp,temp1,temp2;
	int max,min;
	int len;
	//????????
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	max=a[0];
	min=a[0];
	maxid=0;
	minid=0;
	
	for(i=0;i<n;i++){
		if(max<a[i]){
			max=a[i];
			maxid=i;
		}
		if(min>a[i]){
			min=a[i];
			minid=i;
		}
	}
	
	if(max+min>0){
		printf("%d\n",2*n-1);
		for(i=0;i<n;i++){
			printf("%d %d\n",maxid+1,i+1);
		}
		for(i=1;i<n;i++){
			printf("%d %d\n",i,i+1);
		}
	}else{
		printf("%d\n",2*n-1);
		for(i=0;i<n;i++){
			printf("%d %d\n",minid+1,i+1);
		}
		for(i=n-1;i>0;i--){
			printf("%d %d\n",i+1,i);
		}
	}
	
//	printf("??????\n");
	//??
	
	//printf("%d\n",ans);
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^