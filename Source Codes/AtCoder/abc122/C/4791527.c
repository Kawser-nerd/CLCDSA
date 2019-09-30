#include <stdio.h>
int main(){
    int N, Q;
    scanf("%d%d", &N, &Q);
    char S[N];
    int l[100000], r[100000], i;
    int A[100001]={0};
    scanf("%s", S);
    for(i=0;i<Q;i++){
        scanf("%d%d", &l[i], &r[i]);
    }
    for(i=0;i<N;i++){
        if( S[i-1]=='A' && S[i]=='C' ){
            A[i]++;
        }
        A[i] = A[i] + A[i-1];
    }
    for(i=0;i<Q;i++){
        printf("%d\n",A[ r[i]-1 ] - A[ l[i]-1 ]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &N, &Q);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d", &l[i], &r[i]);
         ^