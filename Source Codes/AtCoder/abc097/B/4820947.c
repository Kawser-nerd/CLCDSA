#include <stdio.h>
#include <math.h>

int main(void){
    int x;
    scanf("%d", &x);
    int s[1000] = {0};
    s[0] += 1;
    for(int i = 2; i < 32; i++){
        for(int j = 2; pow(i, j) <= 1000; j++){
            s[(int) pow(i, j)-1] += 1;
        }
    }
    
    int ans = 1;
    for(int i = x; i>= 0; i--){
        if(s[i - 1] > 0){
            ans = i; 
            break;
        }
    }
    printf("%d\n", ans);
    
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &x);
     ^