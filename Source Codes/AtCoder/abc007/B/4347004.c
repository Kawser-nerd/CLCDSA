#include <stdio.h>
#include <string.h>
#define String_max 102

int main(int argc, char const *argv[]) {
    // ??
    char A[String_max];
    // ??
    scanf("%s", A);
    int length = strlen(A);
    // ??
    if (length==1 && A[0]=='a') {
        printf("-1\n");
    } else {
        printf("a\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", A);
     ^