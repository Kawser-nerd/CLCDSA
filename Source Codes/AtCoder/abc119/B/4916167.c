#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int N;
    float sum;
    float* money;
    char (* money_type)[4];
    const char* JPY = "JPY";
    if (scanf("%d", &N) != EOF) {
        money = malloc(sizeof(float)*N);
        money_type = malloc(sizeof(char*)*N);
        for (int i = 0; i < N; i++) {
            if (scanf("%f %s", &(money[i]), &(money_type[i])) != EOF) {
                if (!(strncmp(money_type[i], JPY, 3))) {
                    sum += money[i];
                } else {
                    sum += money[i]*380000.0;
                }
            }
        }
        printf("%g\n", sum);
    } else {
        return 1;
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:23: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[4]’ [-Wformat=]
             if (scanf("%f %s", &(money[i]), &(money_type[i])) != EOF) {
                       ^