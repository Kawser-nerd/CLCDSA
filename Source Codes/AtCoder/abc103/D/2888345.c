#include <stdio.h>
#include <stdlib.h>

struct pair{
	int a;
	int b;
};
int compare_int(const void *a, const void *b)
{
	return ((struct pair*)a)->b - ((struct pair*)b)->b;
}

int main(void){
	int n,m;
	scanf("%d %d",&n,&m);
	int i,j;
	struct pair arr[m];
	for(i=0;i<m;i++){
		scanf("%d %d",&arr[i].a,&arr[i].b);
	}
	qsort(arr,m,sizeof(struct pair), compare_int);
	int max = 0;
	int ans = 0;
	for(i=0;i<m;i++){
		if(max<arr[i].a){
			max = arr[i].b -1;
			ans ++;
		}
	}
	/*printf("--------\n");
	for(i=0;i<m;i++){
		printf("%d %d\n",a[i],b[i]);
	}*/
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&arr[i].a,&arr[i].b);
   ^