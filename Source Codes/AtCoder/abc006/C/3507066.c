#include <stdio.h>

int main() {
    int n, m;
    int adult, middle_age, baby;
    int found = 0;

    scanf("%d %d", &n, &m);


    for (int middle_age = 0; middle_age < 2; middle_age++) {
        baby = (m - middle_age - (2 * n)) / 2;
        adult = n - baby - middle_age;

        if (adult >= 0 && 
            middle_age >= 0 && 
            baby >= 0 &&
            (adult + middle_age + baby == n) &&
            (2 * adult) + (3 * middle_age) + (4 * baby) == m
        ) {
            printf("%d %d %d\n", adult, middle_age, baby);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("-1 -1 -1\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^