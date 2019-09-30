#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int matches(int nr, char *m, int len)
{
    int i;
    for (i = 0; i < len; ++i) {
        int d = nr % 10;
        nr = nr / 10;
        if (m[len - i - 1] == '?')
            continue;
        if (m[len - i - 1] != '0' + d)
            return 0;
    }
    return 1;
}

char *printme(char *cc, int len, int nr)
{
    cc[len] = 0;
    int i;
    for (i = 0; i < len; ++i) {
        int d = nr % 10;
        cc[len - i - 1] = d + '0';
        nr = nr / 10;
    }
    return cc;
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
        char c[20], j[20];
        memset(c, 0, sizeof(c));
        memset(j, 0, sizeof(j));
        fscanf(fin, "%s %s", c, j);
        int len = strlen(c);
        int resc = pow(10, len)-1;
        int resj = pow(10, len)-1;
        int min = resc;
        int cmin = 0, jmin = 0;
        int ii, ij;
        for (ij = resj; ij >= 0; --ij) {
            for (ii = resc; ii >= 0; --ii) {
                if (matches(ii, c, len) && matches(ij, j, len)) {
                    int dif = abs(ii -ij);
                    if (dif <= min) {
                        min = dif;
                        cmin = ii;
                        jmin = ij;
                    }
                }
            }
        }
        char cc[20], jj[20];
        fprintf(fout, "Case #%d: %s %s\n", i+1, printme(cc, len, cmin), printme(jj, len, jmin));
    }
    fclose(fout);
    fclose(fin);
    return 0;
}
