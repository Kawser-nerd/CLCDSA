#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pm(int x)
{
	if(x%2==1){
		return 1;
	}else{
		return -1;
	}
}


int compare_int(const void *a, const void *b)
{
	long *A = (long *)a;
	long *B = (long *)b;
	if (*A < *B) return 1;
	if (*A > *B) return -1;
	return 0;
}

int main(void)
{
	//?????
	int n,m;
	int i,j,k;
	long int x[1010];
	long int y[1010];
	long int z[1010];
	long int sum[1010];
	long int temp;
	long int max=0;
	
	//????????
	scanf("%d %d",&n,&m);
	
	for(i=0;i<n;i++){
		scanf("%ld %ld %ld",&x[i],&y[i],&z[i]);
	}
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	
	for(i=0;i<8;i++){
		for(j=0;j<n;j++){
			sum[j]=x[j]*pm(i)+y[j]*pm(i/2)+z[j]*pm(i/4);
		}
		qsort(sum, n, sizeof(long int), compare_int);
		temp=0;
		for(j=0;j<m;j++){
			temp=temp+sum[j];
		}
		if(temp>max){
			max=temp;
		}
	}
	
	
	
	
	
//	printf("??????\n");
	
	//??
	printf("%ld",max);
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:40:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld %ld",&x[i],&y[i],&z[i]);
   ^