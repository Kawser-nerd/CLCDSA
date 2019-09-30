#include <stdio.h>

int main(){
    int N;
    char S[50];
    
    scanf("%d",&N);
    scanf("%s",S);
    
    int R = 0, B = 0, G = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'R'){
            R++;
        }
        if(S[i] == 'B'){
            B++;
        }
        if(S[i] == 'G'){
            G++;
        }
    }
    
    printf("%d\n",R%2 + B%2 + G%2);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",S);
     ^