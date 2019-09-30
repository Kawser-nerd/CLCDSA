#include <stdio.h>
#include <string.h>

int test(char *str) {
    int i, e=0, len=strlen(str);
    for (i=0; i<len; i++) {
        if (str[i] == '(')
            e++;
        else
            e--;
        if (e < 0)
            return -1;
    }
    if (e != 0)
        return 1;
    else
        return 0;
}

void pushfront(char *str) {
    char abc[256];
    strcpy(abc, str);
    str[0] = '(';
    strcpy(str+1, abc);
}
void pushback(char *str) {
    int itr = strlen(str);
    str[itr] = ')';
    str[itr+1] = '\0';
}

int main() {
    int n, ret;
    char str[256];
    scanf("%d\n", &n);
    fgets(str, sizeof(str), stdin);
    str[n] = '\0';
    while ((ret = test(str)) != 0) {
        if (ret > 0)
            pushback(str);
        else
            pushfront(str);
    }
    printf("%s\n", str);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n", &n);
     ^
./Main.c:36:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(str, sizeof(str), stdin);
     ^