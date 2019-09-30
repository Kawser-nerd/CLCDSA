#include <stdio.h>
#include <stdlib.h>
#include <math.h>

    int a[501][501];
    int sum[501][501][501];
    int mxsum[501][501][501];
    int mysum[501][501][501];
    int hsum[501][501],vsum[501][501];
    int mxhsum[501][501],mxvsum[501][501];
    int myhsum[501][501],myvsum[501][501];

int main(void)
{
    FILE *input, *output;

    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    int ng, ig;
    fscanf(input, "%d", &ng);
    int i, j, k, r, c, d;
    for (ig = 0; ig < ng; ig++)
    {
        fscanf(input, "%d%d%d\n", &r, &c, &d);
        for (i = 1; i <= r; i++)
        {
            for (j = 1; j <= c; j++)
            {
                char c1;
                fscanf(input, "%c", &c1);
                a[i][j] = c1 - '0' + d;
            }
            fscanf(input, "\n");
        }

/*        for (i = 1; i <= r; i++)
        {
            for (j = 1; j <= c; j++)
            {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
*/


        for (i = 1; i <= r; i++)
        {
            hsum[i][0] = 0;
            mxhsum[i][0] = 0;
            myhsum[i][0] = 0;
            for (j = 1; j <=c; j++)
            {
                hsum[i][j] = hsum[i][j - 1] + a[i][j];
                mxhsum[i][j] = mxhsum[i][j - 1] + a[i][j] * j;
                myhsum[i][j] = myhsum[i][j - 1] + a[i][j] * i;
            }
        }
        for (i = 1; i <= c; i++)
        {
            vsum[i][0] = 0;
            mxvsum[i][0] = 0;
            myvsum[i][0] = 0;
            for (j = 1; j <=r; j++)
            {
                vsum[i][j] = vsum[i][j - 1] + a[j][i];
                mxvsum[i][j] = mxvsum[i][j - 1] + a[j][i] * i;
                myvsum[i][j] = myvsum[i][j - 1] + a[j][i] * j;
            }
        }

        for (i = 1; i <= r; i++)
            for (j = 1; j <= c; j++)
            {
                sum[i][j][1] = a[i][j];
                mxsum[i][j][1] = a[i][j] * j;
                mysum[i][j][1] = a[i][j] * i;
            }

        int ans = 0;

        for (k = 2; k <= r && k <= c; k++)
            for (i = 1; i <= r; i++)
                for (j = 1; (i + k) <= (r + 1) && (j + k) <= (c + 1); j++)
                {
                    sum[i][j][k] = sum[i][j][k - 1] +
                        hsum[i + k - 1][j + k - 1] - hsum[i + k - 1][j - 1] +
                        vsum[j + k - 1][i + k - 1] - vsum[j + k - 1][i - 1] - a[i + k - 1][j + k - 1];
                    mxsum[i][j][k] = mxsum[i][j][k - 1] +
                        mxhsum[i + k - 1][j + k - 1] - mxhsum[i + k - 1][j - 1] +
                        mxvsum[j + k - 1][i + k - 1] - mxvsum[j + k - 1][i - 1] - a[i + k - 1][j + k - 1] * (j + k - 1);
                    mysum[i][j][k] = mysum[i][j][k - 1] +
                        myhsum[i + k - 1][j + k - 1] - myhsum[i + k - 1][j - 1] +
                        myvsum[j + k - 1][i + k - 1] - myvsum[j + k - 1][i - 1] - a[i + k - 1][j + k - 1] * (i + k - 1);

                    if (k > 2)
                    {
                        double mall = sum[i][j][k] - a[i][j] - a[i + k - 1][j] - a[i][j + k - 1] - a[i + k - 1][j + k - 1];
                        double mxall = mxsum[i][j][k] - a[i][j]*j - a[i + k - 1][j]*j - a[i][j + k - 1]*(j + k - 1) - a[i + k - 1][j + k - 1]*(j + k - 1);
                        double myall = mysum[i][j][k] - a[i][j]*i - a[i + k - 1][j]*(i + k - 1) - a[i][j + k - 1]*i - a[i + k - 1][j + k - 1]*(i + k - 1);
                        double k1 = k;

                        if (fabs((mxall / mall) - (j + (k1 - 1)/2)) < 1e-6 && fabs((myall / mall) - (i + (k1 - 1)/2)) < 1e-6)
                        {
                            ans = k;
                        }
                    }

                }

        if (ans) fprintf(output, "Case #%d: %d", ig + 1, ans);
        else fprintf(output, "Case #%d: IMPOSSIBLE", ig + 1);
        fprintf(output, "\n");
    }

    fclose(input);
    fclose(output);

    return 0;
}
