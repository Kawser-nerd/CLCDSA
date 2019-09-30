#include <cstdio>

int main() {
    char s[101];
    int i;
    scanf("%s", s);
    scanf("%d", &i);
    printf("%c\n", s[i - 1]);
}