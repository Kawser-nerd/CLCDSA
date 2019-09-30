#include <stdio.h>
#include <string.h>

int main(void)
{
    enum { S = 7, W = 20 };
    const char *list[S] = {
                "WBWBWWBWBWBW",
                "WBWWBWBWBWWB",
                "WWBWBWBWWBWB",
                "WBWBWBWWBWBW",
                "WBWBWWBWBWWB",
                "WBWWBWBWWBWB",
                "WWBWBWWBWBWB",
    };
    const char *tone[S] = {
                "Do", "Re", "Mi", "Fa", "So", "La", "Si",
    };
    char s[W + 1];
    scanf("%s", s);
    for (size_t i = 0; i < S; ++i) {
        if (strncmp(s, list[i], 12) == 0) {
            puts(tone[i]);
            return 0;
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^