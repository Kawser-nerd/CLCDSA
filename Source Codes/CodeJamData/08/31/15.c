#include <stdio.h>
#include <stdlib.h>

int
compare(const void *first, const void *second)
{
    return - *(int *) first + *(int *) second;
}

long long
solve(int p, int k, int length, int freq[1001])
{
    int i, press = 1;
    long long retval = 0;
    
    qsort(freq, length, sizeof(int), compare);
    
    for (i = 0; i < length ; i++) {
        retval += freq[i] * press;
        if (i % k == k - 1) {
            press++;
        }
    }
    return retval;
}

int
main(int argc, char** argv) 
{
    int i, j, casenum;
    FILE *in, *out;
    
    if (argc < 3) {
        fprintf(stderr, "Wrong number of arguments!\n");
        exit(1);
    }
    
    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");
    
    fscanf(in, " %d", &casenum);
    for (i = 0; i < casenum; i++) {
        int p, k, length;
        int freq[1001];
        fscanf(in, " %d %d %d", &p, &k, &length);
        for (j = 0; j < length; j++) {
            fscanf(in, " %d", &freq[j]);
        }
        fprintf(out, "Case #%d: %lld\n", i + 1, solve(p, k, length, freq));
    }
    
    fclose(in);
    fclose(out);
    
    return 0;
}
