#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[21];
    int people;
} CITY;

int main() {
    int n, p, sum = 0, half = 0;
    int flag = -1;
    char s[21];
    CITY *city;
   
    scanf("%d", &n);

    city = (CITY *)malloc(sizeof(CITY) * n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", s, &p);
        sum += p;
        strncpy(city[i].name, s, 20);
        city[i].people = p;
    }

    half = sum / 2 + 1;

    for (int i = 0; i < n; i++) {
        if (city[i].people >= half) {
            flag = i;
            break;
        }
    }

    if (flag < 0) {
        printf("atcoder\n");
    } else {
        printf("%s\n", city[flag].name);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:20:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s %d", s, &p);
         ^