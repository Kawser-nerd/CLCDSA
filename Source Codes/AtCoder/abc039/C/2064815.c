#include <stdio.h>
#include <string.h>

int main() {
    char s[24], buf[24] = "WBWBWWBWBWBWWBWBWWBWBWBW";
    int ans = -1;
    scanf("%s", s);
    for (int i=0; i<12; i++)
        if (strncmp(s, buf+i, 12) == 0) {
            ans = i;
            break;
        }
    switch (ans) {
        case 0: puts("Do"); break;
        case 2: puts("Re"); break;
        case 4: puts("Mi"); break;
        case 5: puts("Fa"); break;
        case 7: puts("So"); break;
        case 9: puts("La"); break;
        case 11: puts("Si"); break;
    }
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^