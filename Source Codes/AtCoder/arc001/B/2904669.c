#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(void){
    int a,b,tmp,ans=0;
    scanf("%d%d",&a,&b);
    if (a>b){
        tmp=a;
        a=b;
        b=tmp;
    }
    while (a!=b){
        if (a<=b-10){
            a=a+10;
            ans++;
        } else if (a<=b-8){
            ans+=10-(b-a)+1;
            a=b;
        } else if (a<=b-3){
            ans+=abs(b-(a+5))+1;
            a=b;
        } else {
            ans+=b-a;
            a=b;
        }
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^