#include <stdio.h>
#define INF 2000000000

 int main(void)
 {
 	int n,t,a;
 	int res=1,min=INF,diff=0;
 	scanf("%d %d",&n,&t);
 	for(int i=0;i<n;i++){
 		scanf("%d",&a);
 		if(a<min) min=a;
 		else if(a-min>diff) res=1,diff=a-min;
 		else if(a-min==diff) res++;
 	}
 	printf("%d\n",res);
 	return 0;
 } ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&t);
   ^
./Main.c:10:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&a);
    ^