#include <stdio.h>
#include <stdlib.h>

int main() {
    long H,W,N,i,j,k,a=0,*A;

    scanf("%ld %ld %ld",&H,&W,&N);
    A=(long *)malloc((H+1)*sizeof(long));
    for(i=1;i<=H;i++) {
        A[i]=0;
    }

    for(k=0;k<N;k++) {
        scanf("%ld %ld",&i,&j);
        if(i<j) continue;
        if(A[i]==0 || A[i]>j) A[i]=j;
    }

    for(i=1;i<=H;i++) {
        if(A[i]==0) continue;

        if(A[i]==i-a) {
            a++;
            continue;
        }

        if(A[i]<i-a) {
            k=1;
            break;
        }
    }

    printf("%ld\n",i-1);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld %ld",&H,&W,&N);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld %ld",&i,&j);
         ^