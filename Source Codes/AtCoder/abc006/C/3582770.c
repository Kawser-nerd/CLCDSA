#include <stdio.h>

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    if(4 * n - m < 0){
        printf("-1 -1 -1\n");
    }else{
        int k = 4 * n - m;
        int a = -1, b = -1, c = -1;
        for(int a_check = 0; k - 2 * a_check >= 0; a_check++){
            int b_check = k - 2 * a_check;
            if(b_check % 2 != m % 2) continue;

            int c_check = n - a_check - b_check;
            if(b_check >= 0 && c_check >= 0){
                a = a_check;
                b = b_check;
                c = c_check;
                break;
            }
        }
        printf("%d %d %d\n", a, b, c);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^