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
	int a[200010];
	int r=0;
	
	//??????
	int i,j,k;
	int flag=0;
	int ans=0;
	long int count=0;
	int sum=0;
	int temp,temp1,temp2;
	int max,min;
	int len;
	//????????
	
	//????????
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	
	for(i=0;i<n;i++){
		flag=0;
		while(flag==0){
//			printf("a[i]=%d,sum=%d\n",a[i],sum);
//			printf("a[r]=%d,sum=%d,a[r]|sum=%d,a[r]+sum=%d\n",a[r],sum,a[r]|sum,a[r]+sum);
			temp1=a[r]|sum;
			temp2=a[r]+sum;
			if(temp1==temp2&&r<n){
				sum=sum+a[r];
				r++;
			}else{
				count=count+r-i;
//				printf("i=%d,r=%d count=%d\n",i,r,count);
				sum=sum-a[i];
				flag=1;
			}
		}
	}
	
	
//	printf("??????\n");
	
	//??
	
	printf("%ld",count);
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:36:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^