#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int c[50][26] = {};
    for (int i = 0; i < n; ++i) {
        char s[51];
        scanf("%s", s);
        for (int j = 0; s[j] != '\0'; ++j)
            c[i][s[j] - 'a'] += 1;
    }

    for (int i = 0; i < 26; ++i) {
        int mi = 10000000;
        for (int j = 0; j < n; ++j)
            mi = min(mi, c[j][i]);
        for (int j = 0; j < mi; ++j)
            printf("%c", i + 'a');
    }
    printf("\n");

    return 0;
}