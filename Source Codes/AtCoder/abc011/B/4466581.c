#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ??????????
char toLow (char c) {
    if ((c>='A') && (c<='Z')) {
        return (c+0x20);
    } else {
        return c;
    }
}
// ??????????
char toUp (char c) {
    if ((c>='a') && (c<='z')) {
        return (c-0x20);
    } else {
        return c;
    }
}

int main(int argc, char const *argv[]) {
    // ???
    char name[13];
    // ??
    scanf("%s", name);
    int n = strlen(name);
    // ??
    for (size_t i = 0; i < n; i++) {
        name[i] = toLow(name[i]);
    }
    name[0] = toUp(name[0]);
    // ??
    printf("%s\n", name);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", name);
     ^