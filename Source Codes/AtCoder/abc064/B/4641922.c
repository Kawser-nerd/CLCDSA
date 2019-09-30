#include <stdio.h>
int main(void){
    int n,a,i,max=-1,min=1001;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        if(a>max) max=a;
        if(a<min) min=a;
    }
    printf("%d\n",max-min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a);
         ^