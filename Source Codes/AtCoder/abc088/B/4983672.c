#include <stdio.h>
#include <stdlib.h>
int compare_int(const void *a, const void *b)
{
    return *(int*) b- *(int*)a;
}
int main(void){
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),compare_int);
	int alice = 0;
	int bob=0;
	int flag=0;
	for(i=0;i<n;i++){
		if(flag==0){
			alice += a[i];
			flag = 1;
		}else{
			bob += a[i];
			flag = 0;
		}
	}
	printf("%d",alice - bob);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^