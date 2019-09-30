#include <stdio.h>

void InitCategory(int cat[])
{
    int i;
    for(i=0;i<9;i++)
        cat[i] = 0;
}

void AddCategory(int cat[], long long int x, long long int y)
{
    int nx = (int)(x % 3);
    int ny = (int)(y % 3);

    cat[nx * 3 + ny]++;
}
long long int CountCategory(int cat[])
{
    int i, j, k;
    int used_time[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    long long int ans = 0;

    for (i=0;i<9;i++)
        for (j=i;j<9;j++)
            for (k=j;k<9;k++)
                if ( (i/3 + j/3 + k/3) % 3 == 0 &&
                     (i%3 + j%3 + k%3) % 3 == 0)
                {
                    long long int temp_count = 1;

                    temp_count *= cat[i] - used_time[i];
                    used_time[i]++;
                    temp_count /= used_time[i];
                    temp_count *= cat[j] - used_time[j];
                    used_time[j]++;
                    temp_count /= used_time[j];
                    temp_count *= cat[k] - used_time[k];
                    used_time[k]++;
                    temp_count /= used_time[k];

                    ans += temp_count;
                    #ifdef DEBUG
                    if( temp_count != 0)
                        printf("%d %d %d -> %d\n", i, j, k, temp_count);
                    #endif
                    used_time[i]--;
                    used_time[j]--;
                    used_time[k]--;
                }
    return ans;
}

int main(void)
{
    int n, i;
    long long int A, B, C, D;
    long long int x0, y0;
    long long int M;
    int category[9];
    int ncase = 0;
    int icase;

    scanf("%d", &ncase);

    for (icase = 1; icase <= ncase; icase++)
    {
        InitCategory(category);
        scanf("%d%lld%lld%lld%lld%lld%lld%lld",
                &n, &A, &B, &C, &D, &x0, &y0, &M);
        AddCategory(category, x0, y0);
        #ifdef DEBUG
        printf("%lld, %lld, %lld, %lld, %lld\n", A, B, C, D, M);
        printf("%lld, %lld\n", x0, y0);
        #endif
        for(i=1;i<n;i++)
        {
            x0 = (A*x0 + B) % M;
            y0 = (C*y0 + D) % M;
            #ifdef DEBUG
            printf("%lld, %lld\n", x0, y0);
            #endif
            AddCategory(category, x0, y0);
        }
        #ifdef DEBUG
        for(i=0;i<9;i++)
            printf("%d ", category[i]);
        printf("\n");
        #endif
        printf("Case #%d: %lld\n", icase, CountCategory(category));
    }

    return 0;
}
    
