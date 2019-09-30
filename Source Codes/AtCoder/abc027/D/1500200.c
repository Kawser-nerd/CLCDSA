#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char s[100001];
static int num_minus, num_plus, num_m, num_m2, a[100000], m_left, m_right;
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
void print_a(void) {
    int i;
    for (i = 0; i < num_m; ++i)
        printf("(%d, %d), ", i, a[i]);
    putchar('\n');
}
int main(void) {
    int i, len;
    scanf("%s", s);
    len = strlen(s);
    for (i = len - 1; i >= 0; --i)
        if (s[i] == '-')
            ++num_minus;
        else if (s[i] == '+')
            ++num_plus;
        else if (s[i] == 'M')
            a[num_m++] = num_plus - num_minus;
    qsort(a, num_m, sizeof(int), cmp);
    num_m2 = num_m / 2;
    for (i = 0; i < num_m2; ++i)
        m_left += a[i];
    for (i = num_m2; i < num_m; ++i)
        m_right += a[i];
    printf("%d\n", m_right - m_left);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^