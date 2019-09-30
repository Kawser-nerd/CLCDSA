#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int compare_int(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}


int main(void)
{
	//?????
	int n,h;
	int a[100010];
	int b[100010];
	int amax=0;
	int maxnumber;
	int count=0;
	int i;
	int flag=0;
	
	//????????
	scanf("%d %d",&n,&h);
	
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	for(i=0;i<n;i++){
		if(amax<a[i]){
			amax=a[i];
			maxnumber=i;
		}
	}
	
	qsort(b, n, sizeof(int), compare_int);
	
	
	i=0;
	while(flag==0&&i<n){
		if(b[i]>amax&&h>0){
			h=h-b[i];
			count++;
			i++;
//			printf("%d????????HP=%d\n",count,h);
		}else{
			flag=1;
		}
	}
	
	if(h>0){
		count=count+(h+amax-1)/amax;
	}
//	printf("??????\n");
	
	//??
	
		printf("%d\n",count);
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&h);
  ^
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a[i],&b[i]);
   ^