#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    scanf("\n");

    char str[512];
    char pattern[64];
    int count[512][64];
    strcpy(pattern, "welcome to code jam");
    int i;
    int j;
    int k;
    for (k = 0; k < N; k ++) {
        scanf("%[^\n]", str);
        scanf("\n");
        
        //initialize the pos arr 
        for (i = 0; i < strlen(str); i ++) {
            for (j = 0; j < strlen(pattern); j++) {
                count[i][j] = 0;
            }
        }
       
        for (i = strlen(str) - 1; i >= 0; i --) {
            for (j = 0; j < strlen(pattern); j ++) {
                if (i == strlen(str) -1) {
                    count[i][j] = 0;
                }
                else {
                    count[i][j] = count[i+1][j];
                }

                if (str[i] == pattern[j]) {
                    if(strlen(pattern) -1 == j) {
                        count[i][j] ++;
                    }
                    else if(strlen(str) -1 == i) {
                        // not matching, string is over but pattern not
                    }
                    else { 
                        count[i][j] += count[i+1][j+1];
                    }
                }
                count[i][j] %= 10000;
            }
        }

        int finalCount = count[0][0] % 10000;
        printf("Case #%d: %04d\n", k + 1, finalCount);
    }
}
