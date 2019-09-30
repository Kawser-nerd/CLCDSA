#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int b[26] ={0};

int main(void)
{
    char s[101];
    scanf("%s", s);
    int l = strlen(s);
    for (int i = 0; i < l; ++i){
       b[s[i] -'a'] ++;
    }

    for (int j = 0; j < 26; ++j){
        if (b[j]){
            int k = 0;
            int max = 0;
            for (int i = 0; i < l; ++i){
                if (s[i] == j + 'a'){
                    if (k > max){
                        max = k;
                        k = 0;
                    }
                     k = 0;
                }
                else
                    k++;
            }
            if (k > max)
                b[j] = k;
            else
                b[j] = max;
        }
        else
            b[j] = 200;
    }
       
    int min = 200;
    for (int j = 0; j < 26; ++j){
        if (b[j] < min){
            min = b[j];
        }
    }
    printf("%d\n", min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^