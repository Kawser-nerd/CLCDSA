#include <stdio.h>

int main(){
    int a[3],count=0,tmp[100],i,j;
    for (i=0; i<3; i++) scanf("%d",&a[i]);
    for (i=0; i<100; i++) tmp[i]=i+1;
    for (i=0; i<3; i++) {
        for (j=0; j<100; j++) {
            if (tmp[j]==a[i]) {
                tmp[j]=-1;
                count++;
            }
        }
    }
    printf("%d\n",count);
} ./Main.c: In function ‘main’:
./Main.c:5:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for (i=0; i<3; i++) scanf("%d",&a[i]);
                         ^