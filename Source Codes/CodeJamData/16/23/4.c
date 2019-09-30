#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
        int N;
        int j;
        fscanf(fin, "%d", &N);
        char topic1[N][21];
        char topic2[N][21];
        for (j = 0; j < N; ++j) {
            fscanf(fin, "%s %s", topic1[j], topic2[j]);
        }
        int k;
        int max = 0;
        for (k = 1; k < (1<<(N+1)) - 1; ++k) {
            int l;
            int good = 1;
            int fake = 0;
            for (l = 0; l < N; ++l) {
                if (((k>>l) & 0x1) != 0) {
                    fake++;
                    int m;
                    int found1 = 0;
                    for (m = 0; m < N; ++m)
                        if (m != l && ((k>>m)&0x1) == 0 && strcmp(topic1[m], topic1[l]) == 0) {
                            found1 = 1;
                            break;
                        }
                    if (!found1) {
                        good = 0;
                        break;
                    }
                    found1 = 0;
                    for (m = 0; m < N; ++m)
                        if (m != l && ((k>>m)&0x1) == 0 && strcmp(topic2[m], topic2[l]) == 0) {
                            found1 = 1;
                            break;
                        }
                    if (!found1) {
                        good = 0;
                        break;
                    }
                }
            }
            if (good && fake > max) {
                max = fake;
            }
        }
        fprintf(fout, "Case #%d: %d\n", i+1, max);
    }
    fclose(fout);
    fclose(fin);
    return 0;
}
