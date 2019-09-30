#include <stdio.h>
int main(void){
    int n,i,m,f=0;
    scanf("%d",&n);
    m=n;
    for(i=0;i<10;i++){
        f+=m%10;
        m/=10;
    }
    printf("%s\n",(n%f==0?"Yes":"No"));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^