#include <stdio.h>
#include <string.h>

int main(void){
    char S[50];
    scanf("%s", S);
    int Slen = strlen(S);
    int choflag = 0; int cflag = 0;

    if(Slen != 0){
        for(int i = 0; i < Slen; i++){
            if(S[i] == 'c'){
                if(cflag == 1){
                    cflag = 0;
                }else {
                    cflag = 1;
                }
            }else if(S[i] == 'h'){
                if(cflag == 1){
                    cflag = 0;
                }else {
                    choflag = 1;
                    break;
                }
            }else if(S[i] != 'o' && S[i] != 'k' && S[i] != 'u'){
                choflag = 1;
                break;
            }else {
                cflag = 0;
            }
        }
    }

    if(choflag == 0){
        printf("YES\n");
    }else {
        printf("NO\n");
    }
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^