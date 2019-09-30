#include <stdio.h>
#include <string.h>

int check(int num);

int main(void) {
    int n, i, count = 0;
    scanf("%d",&n);
    for(i = 1; ;i++ ) {
        if(check(i)) {
            count++;
        }
        if(count == n) {
            printf("%d\n",i);
            return 0;
        }
    }
}

int check(int num) {
    int ket;
    ket = num % 10;
    while(num != 0) {
        if(ket != num % 10) {
            return 0;
        }
        num /= 10;
    }
    return 1;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^