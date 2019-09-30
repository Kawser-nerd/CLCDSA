//??????
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(){
    int t,x;
    double ans;
    scanf("%d%d",&t,&x);
    ans = (double)t/(double)x;
    printf("%f\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&t,&x);
     ^