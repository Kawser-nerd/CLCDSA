#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 20010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)

int t, n;
char str[2][MAX];

int main(){
    read();
    write();
    int T = 0, i, j, k, l, f, x, res;

    scanf("%d", &t);
    while (t--){
        scanf("%s", str[0]);
        n = strlen(str[0]), res = 0, f = 0;

        strcpy(str[1], str[0]);
        while (n >= 2){
            for (i = 0, k = 0; (i + 1) < n; i++){
                if (str[f][i] == str[f][i + 1]){
                    k = 1, l = n;
                    res += 10, n = 0;
                    for (j = 0; j < i; j++) str[f ^ 1][n++] = str[f][j];
                    for (j = i + 2; j < l; j++) str[f ^ 1][n++] = str[f][j];
                    break;
                }
            }

            f ^= 1;
            if (!k){
                res += (5 * (n >> 1));
                break;
            }
        }

        printf("Case #%d: %d\n", ++T, res);
    }
    return 0;
}
