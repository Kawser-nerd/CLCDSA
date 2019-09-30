#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(void)
{
	//?????
	
	int n,x;
	int num[200010];
	int i,j;
	
	//????????
	
	scanf("%d %d",&n,&x);
	
	for(i=0;i<200010;i++){
		num[i]=0;
	}
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	if(n==2){
		if(x==2){
			printf("Yes\n1\n2\n3\n");
		}else{
			printf("No");
		}
		return 0;
	}
	
	if(x==1||x==2*n-1){
		printf("No\n");
		return 0;
	}else if(x!=2*n-2){
		printf("Yes\n");
		num[n-2]=x+2;
		num[n-1]=x-1;
		num[ n ]=x;
		num[n+1]=x+1;
		
		j=1;
		for(i=0;i<n-2;i++){
			if(i+1!=x-1){
				num[i]=j;
				j++;
			}else{
				j=j+4;
				num[i]=j;
				j++;
			}
		}
		
		
		for(i=n+2;i<2*n;i++){
			if(i-3!=x-1){
				num[i]=j;
				j++;
			}else{
				j=j+4;
				num[i]=j;
				j++;
			}
		}
		
	}else if(x==2*n-2){
		printf("Yes\n");
		num[n-2]=x-2;
		num[n-1]=x+1;
		num[ n ]=x;
		num[n+1]=x-1;
		
		for(i=0;i<n-2;i++){
			num[i]=i+1;
		}
		
		for(i=n+2;i<2*n;i++){
			num[i]=i-3;
		}
	}
//	printf("??????\n");
	
	//??
	for(i=0;i<2*n-1;i++){
		printf("%d\n",num[i]);
	}
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&x);
  ^