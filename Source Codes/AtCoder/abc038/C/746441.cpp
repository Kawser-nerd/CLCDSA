#include <cstdio>

long long res = 0;

int main(){
    int N;
    int A[100000];

    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", A+i);
    }

    for(int i=0,j=0;i<N;){
        while(j < N and (j == N-1 || A[j] < A[j+1])){
            ++j;
        }

        if(j == N){--j;}
        
        // printf("%d, %d\n", i, j);
        res += 1ll * (j-i+1) * (j-i+2) / 2;
        i = j + 1; j = i;
    }

    printf("%lld\n", res);
}