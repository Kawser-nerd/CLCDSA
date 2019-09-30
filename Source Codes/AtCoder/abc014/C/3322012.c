#include <stdio.h>
int main(void){
    int n,a,b,c[1000001]={};
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d%d",&a,&b);
        c[a]++;
        c[b+1]--;
    }
    for (int i=1; i<1000001; i++){
        c[i]+=c[i-1];
        c[0]=fmax(c[0],c[i]);
    }
    printf("%d\n",c[0]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:14: warning: implicit declaration of function ‘fmax’ [-Wimplicit-function-declaration]
         c[0]=fmax(c[0],c[i]);
              ^
./Main.c:12:14: warning: incompatible implicit declaration of built-in function ‘fmax’
./Main.c:12:14: note: include ‘<math.h>’ or provide a declaration of ‘fmax’
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&a,&b);
         ^