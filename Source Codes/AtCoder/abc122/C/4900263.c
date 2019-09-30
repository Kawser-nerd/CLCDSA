#include <stdio.h>
#include <string.h>

int main(){
    int N, Q;
    scanf("%d%d", &N, &Q);
    char S[N+1];
    scanf("%s", S);
    int t[N+1];
    t[1]=0;
    for(int i=0; i<N; i++){
        if(S[i]=='A' && S[i+1]=='C'){
            t[i+1]=t[i]+1;
        }else{
            t[i+1]=t[i];
        }
    }
    int l[Q], r[Q];
    for(int i=0; i < Q; i++){
        scanf("%d%d", &l[i], &r[i]);
    }
    for(int i=0; i< Q; i++){
        printf("%d\n", t[r[i]-1]-t[l[i]-1]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &N, &Q);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^
./Main.c:20:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d", &l[i], &r[i]);
         ^