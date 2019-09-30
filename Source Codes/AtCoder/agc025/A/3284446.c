#include <stdio.h>

int digsum_rec(int x){
    if(x == 0){
        ////printf("reached 0\n");
        return 0;
    }else{
        ////printf("when %d is divided by 10: q = %d, r = %d\n", x, x / 10, x % 10);
        return digsum_rec(x / 10) + x % 10;
    }
}

int main(void){
    int n;
    scanf("%d", &n);

    int a, b, da, db;
    int minimum = 9 * 6;

    for(a = 1; a <= n / 2; a++){
        b = n - a;
        //printf("a = %d, b = %d, minimum = %d\n", a, b, minimum);
        da = digsum_rec(a);
        db = digsum_rec(b);
        //printf("digsum(a) = %d, digsum(b) = %d, sum of those = %d\n", da, db, da + db);
        if(da + db < minimum){
            minimum = da + db;
            //printf("new minimum = %d\n", minimum);
        }
    }
    printf("%d\n", minimum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^