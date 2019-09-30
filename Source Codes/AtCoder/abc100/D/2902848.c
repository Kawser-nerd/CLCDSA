#include <stdio.h>

void selectionSort(long long A[],long long N){
long long i, j, k, min, temp;
    for (i = 0; i < N - 1; i++) {
        min = A[i];                
        k = i;                        
        for (j = i + 1; j < N; j++) {
            if (A[j] < min) { 
                min = A[j];
                k = j;
            }
        } 
        temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }
}

int main(){
long long int N,M,x,y,point[8];
long long int  b[1000],d[1000],p[1000],A[1000],B[1000],C[1000],D[1000],E[1000],F[1000],G[1000],H[1000];


scanf("%lld %lld ",&N,&M);

for(int i = 0;i < N; i++){
    scanf("%lld %lld %lld",&b[i],&d[i],&p[i]);
    A[i] = b[i] + d[i] + p[i];
    B[i] = b[i] + d[i] - p[i];
    C[i] = b[i] - d[i] + p[i];
    D[i] = -b[i] + d[i] + p[i];
    E[i] = -b[i] - d[i] + p[i];
    F[i] = -b[i] + d[i] - p[i];
    G[i] = b[i] - d[i] - p[i];
    H[i] = -b[i] - d[i] - p[i];
}
selectionSort(A,N);
selectionSort(B,N);
selectionSort(C,N);
selectionSort(D,N);
selectionSort(E,N);
selectionSort(F,N);
selectionSort(G,N);
selectionSort(H,N);

for(int i=1;i<=M;i++){
point[0]=point[0]+A[N-i];
point[1]=point[1]+B[N-i];
point[2]=point[2]+C[N-i];
point[3]=point[3]+D[N-i];
point[4]=point[4]+E[N-i];
point[5]=point[5]+F[N-i];
point[6]=point[6]+G[N-i];
point[7]=point[7]+H[N-i];
}
selectionSort(point,8);
printf("%lld\n",point[7]);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%lld %lld ",&N,&M);
 ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld %lld",&b[i],&d[i],&p[i]);
     ^