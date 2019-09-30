#include <stdio.h>
int main(void){
    int n,d,x,a,i,j,s=0;
    scanf("%d%d%d",&n,&d,&x);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        s++;
        j=1+a;
        while(j<=d){
            s++;
            j+=a;
        }
    }
    printf("%d\n",s+x);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&d,&x);
     ^
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a);
         ^