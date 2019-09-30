#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

int primes[] = {2, 3, 5};
int t, r, n, m, k, counter, T[25], R[25], ar[25];

bool detect(int i){

}

int main(){
    int line, lol, i, j;

    scanf("%d", &t);
    for (line = 1; line <= t; line++){
        scanf("%d %d %d %d", &r, &n, &m, &k);
        printf("Case #%d:\n", line);

        for (lol = 1; lol <= r; lol++){
            counter = 0;
            for (i = 0; i < k; i++) scanf("%d", &ar[i]);

            for (i = 0; i < 3; i++){
                int x = 0;
                for (j = 0; j < k; j++){
                    int y = ar[j], c = 0;
                    while ((y % primes[i]) == 0){
                        y = y / primes[i];
                        c++;
                    }
                    if (c > x) x = c;
                }
                T[i] = x;

                if (i == 0) continue;
                for (j = 0; j < x; j++) R[counter++] = primes[i];
            }

            if (counter != 3){
                if (counter == 2){
                    if (T[0] == 0) R[counter++] = 3;
                    if (T[0] == 1) R[counter++] = 2;
                    if (T[0] == 2) R[counter++] = 4;
                }
                if (counter == 1){
                    if (T[0] == 2 || T[0] == 2) R[counter++] = 2, R[counter++] = 2;
                    if (T[0] == 0){
                        if (T[1] != 0) R[counter++] = 3, R[counter++] = 3;
                        else R[counter++] = 5, R[counter++] = 5;
                    }
                }
                if (counter == 0){
                    R[counter++] = 2, R[counter++] = 2, R[counter++] = 2;
                }
            }

            printf("%d%d%d\n", R[0], R[1], R[2]);
        }
    }
    return 0;
}
