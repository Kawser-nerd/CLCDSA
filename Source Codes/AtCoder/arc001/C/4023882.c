#include <stdio.h>

int dif(int a, int b){
    return a > b ? a - b : b - a;
}

int main(){
    int a, b;
    int count = 0, d;
    
    scanf("%d %d", &a, &b);
    
    d = dif(a, b);
    
    if (d >= 10) {
        count += d / 10;
        d %= 10;
    }
    if (d >= 8) {
        count += 1 + 10 - d;
    }else if(d >= 3){
        count += 1 + dif(5, d);
    }else{
        count += d;
    }
    
    printf("%d\n", count);
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &a, &b);
     ^