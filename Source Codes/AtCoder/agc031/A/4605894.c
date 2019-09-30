#include <stdio.h>

int alpha[26];

int main(void){
    long n;
    scanf("%ld\n", &n);
    for(long i=0; i<n; i++){
        int c = getchar_unlocked();
        alpha[c-'a']++;
    }
    long ans = 1;
    for(long i=0; i<26; i++){
        ans = ans * (alpha[i]+1) % 1000000007;
    }
    printf("%ld\n", ans-1);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld\n", &n);
     ^