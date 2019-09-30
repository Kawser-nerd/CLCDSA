#include<stdio.h>

int main(){
		int h,m;
		scanf("%d%d",&h,&m);
		printf("%d\n",h==18?0:((17-h)*60+(60-m)));
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&m);
   ^