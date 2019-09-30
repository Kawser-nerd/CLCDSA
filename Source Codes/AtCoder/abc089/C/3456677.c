#include<stdio.h>

int main(void){
    long int i,N;
    scanf("%ld",&N);
    if(N <= 2){
        printf("0");
        return 0;
    }
    char S[10];
    long int count[5] = {0,0,0,0,0};
    
    for(i = 0;i < N;i++){
        scanf("%s",S);
        if(S[0] == 'M') count[0]++;
        if(S[0] == 'A') count[1]++;
        if(S[0] == 'R') count[2]++;
        if(S[0] == 'C') count[3]++;
        if(S[0] == 'H') count[4]++;
    }
    
    long int ans = 0;
    ans += count[0]*count[1]*count[2];
    ans += count[0]*count[1]*count[3];
    ans += count[0]*count[1]*count[4];
    ans += count[0]*count[2]*count[3];
    ans += count[0]*count[2]*count[4];
    ans += count[0]*count[3]*count[4];
    ans += count[1]*count[2]*count[3];
    ans += count[1]*count[2]*count[4];
    ans += count[1]*count[3]*count[4];
    ans += count[2]*count[3]*count[4];

    printf("%ld",ans);

} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&N);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",S);
         ^