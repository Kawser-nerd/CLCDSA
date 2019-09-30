#include <stdio.h>
#define R 100
#define N 3
#define M 5
#define K 7

int vals[8], is_in[1000], visited[1000];

int main () {

    int garbage, i, j, a, b, c, mask, count;
    scanf("%d", &garbage);
    scanf("%d%d%d%d", &garbage, &garbage, &garbage, &garbage);
    printf("Case #1:\n");
    for (i = 0 ; i < R ; i++) {
        memset(is_in, 0, 1000 * sizeof(int));
        for (j = 0 ; j < K ; j++) {
            scanf("%d", &vals[j]);
            is_in[vals[j]]++;
        }
        for (a = 2 ; a <= M ; a++)
            for (b = 2 ; b <= M ; b++)
                for (c = 2 ; c <= M ; c++) {
                    count = 0;
                    memset(visited, 0, 1000 * sizeof(int));
                    for (mask = 0 ; mask < 8 ; mask++) {
                        int val = 1;
                        if (mask & 1)
                            val *= a;
                        if (mask & 2)
                            val *= b;
                        if (mask & 4)
                            val *= c;
                        if (is_in[val] && !visited[val]) {
                            count += is_in[val];
                            visited[val] = 1;
                        }
                    }
                    if (count == K)
                        goto end;
                }
        end:
            printf("%d%d%d\n", a, b, c);
    }
    
    return 0;
    
}
