#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define llong long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))


int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}



int main(void)
{
	//?????
	int n;
	int a[100010];
	
	
	//??????
	int i,j,k,l;
	int flag=0;
	llong int ans=0;
	int count=0;
	int sum=0;
	long int temp,temp1,temp2;
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
	
	
	qsort(a, n, sizeof(int), compare_int);
	
//	for(i=0;i<n;i++){
//		printf("%d ",a[i]);
//	}
	
	temp=0;
	for(i=0;i<n;i++){
		if(n%2==1){
			if((i+1)/2*2!=a[i]){
				flag=1;
//				printf("i=%d?flag a[i]=%d,%d\n",i,a[i],(i+1)/2*2);
			}
		}else{
			if(1+i/2*2!=a[i]){
				flag=1;
//				printf("i=%d?flag\n",i);
			}
		}
	}
	
//	printf("flag=%d\n",flag);
	
	if(flag==1){
		printf("0");
	}else{
		temp=1;
		for(i=0;i<n/2;i++){
			temp=temp*2;
			temp=temp%1000000007;
		}
		printf("%ld",temp);
	}
	
	
//	printf("??????\n");
	//??
	
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:37:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:40:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^