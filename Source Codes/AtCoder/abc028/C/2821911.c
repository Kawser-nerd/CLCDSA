#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int max(int a, int b){
    if(a>b){
        return(a);
    } else {
        return(b);
    }
}

int main(void){
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    printf ("%d\n",max(e+d+a,e+c+b));
    
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
     ^