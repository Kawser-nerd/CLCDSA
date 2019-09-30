#include <stdio.h>
#include <string.h>

int main(void){
    char S[101];
    char T[101];
    scanf("%s", S);
    scanf("%s", T);
    int n = strlen(S);
    int count = 0;
    for(int i = 0; i < n ; i++){
         if(count != -1 && S[i] == T[0]){
            count = 0;
            for(int j = 0; j < n; j++){
                if(S[(i + j) % n] == T[j]){
                    count += 1;
                }
                if (count == n){
                    count = -1;
                    break;
                }
            }
         }
    }
    printf("%s\n", (count == -1) ? "Yes" : "No");
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", T);
     ^