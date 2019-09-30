#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *digits[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
int ignore[2048];
int ignored;

void remove_chars(char *s, int len, int d, int nr)
{
    int i;
    int j;
    int k;
    int dlen = strlen(digits[d]);
    for (j = 0; j < nr; ++j) {
        for (k = 0; k < dlen; ++k) {
            for (i = 0; i < len; ++i) {
                if (!ignore[i] && s[i] == digits[d][k]) {
                    ignore[i] = 1;
                    ignored ++;
                    break;
                }
            }
        }
    }
}

int count_char(char *s, int len, char c)
{
    int i;
    int ret = 0;
    for (i = 0; i < len; ++i)
        if (!ignore[i] && s[i] == c)
            ret++;
    return ret;
}

int main(int argc, const char *argv[])
{
    if (argc != 3) {
        printf("USAGE:\n\t%s in out\n", argv[0]);
        return -1;
    }
    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL) {
        printf("Failed to open in file %s\n", argv[1]);
        return -1;
    }

    FILE *fout = fopen(argv[2], "w");
    if (fout == NULL) {
        printf("Failed to open out file %s\n", argv[2]);
        fclose(fin);
        return -1;
    }
    int T;
    fscanf(fin, "%d", &T);
    int i;
    for (i = 0; i < T; ++i) {
        char S[2048];
        memset(ignore, 0, sizeof(ignore));
        ignored = 0;
        int d[10];
        memset(S, 0, sizeof(S));
        fscanf(fin, "%s", S);
        int len = strlen(S);
        memset(d, 0, sizeof(d));
        {
            d[0] = count_char(S, len, 'Z');
            remove_chars(S, len, 0, d[0]);
            d[2] = count_char(S, len, 'W');
            remove_chars(S, len, 2, d[2]);
            d[6] = count_char(S, len, 'X');
            remove_chars(S, len, 6, d[6]);
            d[7] = count_char(S, len, 'S');
            remove_chars(S, len, 7, d[7]);
            d[4] = count_char(S, len, 'U');
            remove_chars(S, len, 4, d[4]);
            d[5] = count_char(S, len, 'F');
            remove_chars(S, len, 5, d[5]);
            d[1] = count_char(S, len, 'O');
            remove_chars(S, len, 1, d[1]);
            d[8] = count_char(S, len, 'G');
            remove_chars(S, len, 8, d[8]);
            d[3] = count_char(S, len, 'H');
            remove_chars(S, len, 3, d[3]);
            d[9] = count_char(S, len, 'I');
            remove_chars(S, len, 9, d[9]);
        }
        fprintf(fout, "Case #%d: ", i+1);
        int i, j;
        for (i = 0; i < 10; ++i)
            for (j = 0; j < d[i]; ++j)
                fprintf(fout, "%d", i);
        fprintf(fout, "\n");
    }
    fclose(fout);
    fclose(fin);
    return 0;
}
