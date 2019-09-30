#include <string.h>
int main(void){
    int N;
    scanf("%d", &N);
    char w[N][11];
    int ans = 1;
    char w1 = '\0';
    char wl = '\0';
    for(int i = 0; i < N; i++){
        scanf("%s", w[i]);
        w1 = w[i][0];
        if(i > 0){
            if(w1 != wl){
                ans = 0;
            }
            for(int j = 0; j < i; j++){
                if(strcmp(w[j], w[i]) == 0){
                    ans = 0;
                    break;
                }
            }
        }
        wl = w[i][strlen(w[i]) - 1]; 
    }
    printf("%s\n", ans ? "Yes": "No");
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
     scanf("%d", &N);
     ^
./Main.c:4:5: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:5: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:25:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     printf("%s\n", ans ? "Yes": "No");
     ^
./Main.c:25:5: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:25:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’