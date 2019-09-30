#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(void)
{
	//?????
	
	int n;
	int p[20010];
	int q[20010];
	int i,j;
	int a[20010];
	int b[20010];
	
	//????????
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&q[i]);
		p[q[i]-1]=i+1;
	}
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	a[0]=p[0];
	b[0]=0;
	
	for(i=1;i<n;i++){
		if(p[i-1]>p[i]){
			a[i]=a[i-1]+1;
			b[i]=p[i]-a[i];
		}else{
			b[i]=b[i-1]-1;
			a[i]=p[i]-b[i];
		}
	}
	
	
/*	for(i=0;i<n;i++){
		if(i!=0) printf(" ");
		printf("%d",a[i]);
	}
	
	printf("\n");
	
	for(i=0;i<n;i++){
		if(i!=0) printf(" ");
		printf("%d",b[i]);
	}
	printf("\n");
*/	
	for(i=0;i<n;i++){
		b[i]=b[i]+a[n-1];
	}
	
	
	
	
//	printf("??????\n");
	
	//??
	for(i=0;i<n;i++){
		if(i!=0) printf(" ");
		printf("%d",a[i]);
	}
	
	printf("\n");
	
	for(i=0;i<n;i++){
		if(i!=0) printf(" ");
		printf("%d",b[i]);
	}
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q[i]);
   ^