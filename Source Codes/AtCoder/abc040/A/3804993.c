#include<stdio.h>
    int main(void){
    	int n , x , ans ;
    	scanf("%d %d",&n,&x);
	if (  x  <= n / 2  ){
	ans = x - 1;
	}
	else{
	ans = n - x;
	}


    	printf("%d\n",ans );
    	return 0;
    } ./Main.c: In function ‘main’:
./Main.c:4:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%d %d",&n,&x);
      ^