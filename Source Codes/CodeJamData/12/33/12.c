#include <stdio.h>
#include <stdlib.h>

#define FILE_IN "data.in"
#define FILE_OUT "data.out"

#define DEBUG 0
unsigned long long int max;

void try(unsigned long long int *a, unsigned long long int *aa, unsigned long long int *b, unsigned long long int *bb,
                unsigned long long int buff_a, unsigned long long int buff_b,
                unsigned long long int n, unsigned long long int m,
                unsigned long long int i, unsigned long long int j, unsigned long long int count)
{
        unsigned long long int min;

        if((aa[i] == bb[j]) && buff_a && buff_b)
        {
                min = (buff_a < buff_b ? buff_a : buff_b);
                buff_a -= min;
                buff_b -= min;
                count += min;
        }


        if(max < count)
        {
                max = count;
        }

        // case 1: we drop boxes
        if(i < n - 1)
                try(a, aa, b, bb, a[i + 1], buff_b, n, m, i + 1, j, count);
        // case 2: we drop toys
        if(j < m - 1)
                try(a, aa, b, bb, buff_a, b[j + 1], n, m, i, j + 1, count);
}

int main(int argc, char **argv)
{
        FILE *file_in, *file_out;
        unsigned long long int t, n, m;
        unsigned long long int i, j, a[100], aa[100], b[100], bb[100];

        if(!(file_in = fopen(FILE_IN, "r")))
                return -1;

        if(!(file_out = fopen(FILE_OUT, "w")))
                return -1;

        fscanf(file_in, "%llu", &t);
        for(i = 1; i <= t; i++)
        {
                fprintf(file_out, "Case #%llu:", i);

                fscanf(file_in, "%llu", &n);
                fscanf(file_in, "%llu", &m);
                for(j = 0; j < n; j++)
                {
                        fscanf(file_in, "%llu", a + j);
                        fscanf(file_in, "%llu", aa + j);
                }

                for(j = 0; j < m; j++)
                {
                        fscanf(file_in, "%llu", b + j);
                        fscanf(file_in, "%llu", bb + j);
                }

                max = 0;

                try(a, aa, b, bb, a[0], b[0], n, m, 0, 0, 0);

                fprintf(file_out, " %llu", max);
                fprintf(file_out, "\n");
        }


        fclose(file_in);
        fclose(file_out);

        return 0;
}

