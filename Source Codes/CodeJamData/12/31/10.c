#include <stdio.h>
#include <stdlib.h>

#define FILE_IN "data.in"
#define FILE_OUT "data.out"

#define DEBUG 0

int main(int argc, char **argv)
{
        FILE *file_in, *file_out;
        int t, n;
        int i, j, k, jj;
        int a[1001][11];
        int destination_reached[1001], dest_added;
        int not_found;

        if(!(file_in = fopen(FILE_IN, "r")))
                return -1;

        if(!(file_out = fopen(FILE_OUT, "w")))
                return -1;

        fscanf(file_in, "%d", &t);
        for(i = 1; i <= t; i++)
        {
                fprintf(file_out, "Case #%d:", i);

                fscanf(file_in, "%d", &n);
                for(j = 1; j <= n; j++)
                {
                        fscanf(file_in, "%d", a[j]);
                                for(k = 1; k <= a[j][0]; k++)
                                {
                                        fscanf(file_in, "%d", a[j]+k);
                                }
                }

                not_found = 1;
                for(j = 1; (j <= n) && not_found; j++)
                {
                        for(k = 1; k <= n; k++)
                                destination_reached[k] = 0;

                        dest_added = 0;

                        for(k = 1; k <= a[j][0]; k++)
                        {
                                destination_reached[a[j][k]] = 1;
                                dest_added = 1;
                        }

                        while(dest_added && not_found)
                        {
                                dest_added = 0;
                                for(jj = 1; (jj <= n) && not_found; jj++)
                                {
                                        if(destination_reached[jj] == 1)
                                        {
                                                destination_reached[jj] = 2;
                                                for(k = 1; k <= a[jj][0]; k++)
                                                        //TODO
                                                        if(destination_reached[a[jj][k]])
                                                                not_found = 0;
                                                        else
                                                        {
                                                                destination_reached[a[jj][k]] = 1;
                                                                dest_added = 1;
                                                        }
                                        }
                                }
                        }
                }

                if(not_found)
                        fprintf(file_out, " No");
                else
                        fprintf(file_out, " Yes");
                fprintf(file_out, "\n");
        }


        fclose(file_in);
        fclose(file_out);

        return 0;
}

