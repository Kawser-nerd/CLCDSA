#include <stdio.h>
#include <string.h>
#define max_len 100010
#define Min(a, b) a < b ? a : b
void initArray(char a[], int len);
int main(void)
{
    char s[max_len];
    initArray(s, max_len);
    fgets(s, max_len, stdin);
    int len = strlen(s) - 1;
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += s[i] - '0';
    }
    int min = Min(sum, len - sum);
    printf("%d\n", min * 2);
    return 0;
}

void initArray(char a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        a[i] = 0;
    }
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(s, max_len, stdin);
     ^