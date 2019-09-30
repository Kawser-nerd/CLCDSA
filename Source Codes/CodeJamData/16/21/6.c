#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)

const int digits[] = {0, 6, 4, 8, 3, 2, 5, 7, 9, 1};
const char* str[] = {"ZERO", "SIX", "FOUR", "EIGHT", "THREE", "TWO", "FIVE", "SEVEN", "NINE", "ONE"};

char input[MAX], out[MAX];
int pos[12], counter[256], dp[12][256];

bool found(int i){
    int j;
    for (j = 0; j < 256; j++){
        if (counter[j] < dp[i][j]) return false;
    }

    for (j = 0; str[i][j]; j++) counter[str[i][j]]--;
    return true;
}

void fft(int n, char* ar){
    int i, j, x, g = n, flag = 0;
    while ((g != 1) || flag){
        flag = 0;
        if (g != 1) g *= 0.77425;

        for (i = 0; (i + g) < n; i++){
            if (ar[i] > ar[i + g]){
                flag = 1;
                x = ar[i], ar[i] = ar[i + g], ar[i + g] = x;
            }
        }
    }
}

int main(){
    read();
    write();

    int T = 0, t, i, j, k, l, x, n;
    for (i = 0; i < 10; i++) pos[digits[i]] = i;

    for (i = 0; i < 10; i++){
        for (j = 0; str[i][j]; j++){
            dp[i][str[i][j]]++;
        }
    }

    scanf("%d", &t);
    while (t--){
        clr(counter);
        scanf("%s", input);
        for (j = 0; input[j]; j++) counter[input[j]]++;

        i = 0, n = 0;
        while (i < 10){
            if (found(i)) out[n++] = digits[i] + 48;
            else i++;
        }
        fft(n, out);

        out[n] = 0;
        printf("Case #%d: %s\n", ++T, out);
    }
    return 0;
}
