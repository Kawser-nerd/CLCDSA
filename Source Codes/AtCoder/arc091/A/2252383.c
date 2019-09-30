#include <stdio.h>

int main(void) {
    //code goes 
	long a,b; 
	scanf("%ld %ld",&a,&b);  
	if(a==1 && b==1){
	    printf("1");
	    return 0;
	}
	if(a==1){
	    printf("%ld",b-2);
	    return 0; 
	}
	if(b==1){
	    printf("%ld",a-2);
	    return 0;
	}
	long ans = (a*b) - 2*(a+b) + 4;
	printf("%ld",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld",&a,&b);  
  ^