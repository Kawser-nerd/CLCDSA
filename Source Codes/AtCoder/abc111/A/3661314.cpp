#include <cstdio>

int main() {
    char a,b,c;
    scanf("%c%c%c", &a, &b, &c);
    if (a == '1') a = '9';
    else a = '1';
    if (b == '1') b = '9';
    else b = '1';
    if (c == '1') c = '9';
    else c = '1';
    printf("%c%c%c\n", a,b,c);
    return 0;
}