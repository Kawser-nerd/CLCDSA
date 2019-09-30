#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
static int n = 0;
static int a[100];
static int total;
void readConsole() {
    scanf("%d", &n);
    total = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
        total += *(a+i);
    }
}
int main(int argc, const char * argv[]) {
    readConsole();
    int avg = 0,left = 0,b = 0,i = 0;
    if(total % n != 0) {
        printf("-1\n");
        return 0;
    }
    avg = total / n;
    while(i < n) {
        left = left - avg + a[i];
        if(left) {
            b++;
        }
        i++;
    }
    printf("%d\n", b);
    return 0;
} ./Main.c: In function ‘readConsole’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", a + i);
         ^