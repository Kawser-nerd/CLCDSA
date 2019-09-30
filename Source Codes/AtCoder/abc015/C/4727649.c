#include <stdio.h>
#include <stdlib.h>

int n, k;
int t[5][5];
int *list;

int xor()
{
    int tmp;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            tmp = list[i];
        } else {
            tmp = tmp ^ list[i];
        }
    }
    return tmp;
}

void is_valid(int i)
{
    if (i == n) {
        if (xor() == 0) {
            puts("Found");
            exit(0);
        }
        return;
    }
    for (int j = 0; j < k; ++j) {
        list[i] = t[i][j];
        is_valid(i + 1);
    }
}

int main(int argc, char **argv)
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            scanf("%d", &t[i][j]);
        }
    }
    list = (int *) calloc(n, sizeof(int));
    is_valid(0);
    puts("Nothing");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:38:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &k);
     ^
./Main.c:41:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &t[i][j]);
             ^