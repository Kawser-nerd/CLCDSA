#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXMOD 100005
#define MAXN 105
#define INFINITY 2000000000000000005LL

void sort (int a[MAXN], int l, int r)
{
    int i, j, x, y;
    i = l; j = r; x = a[(l+r)/2];
    while (i <= j)
    {
        while (a[i] > x) i++;
        while (a[j] < x) j--;
        if (i <= j)
        {
            y = a[i]; a[i] = a[j]; a[j] = y;
            i++; j--;
        }
    }
    if (l < j) sort(a,l,j);
    if (i < r) sort(a,i,r);
}

int main ()
{
    int T, iT;
    scanf("%d",&T);
    static int data[MAXN];
    static long long int a[MAXMOD];
    static long long int b[MAXMOD];
    static char flag[MAXMOD];
    for (iT = 0; iT < T; iT++)
    {
        long long int L;
        int N;
        scanf("%lli %d",&L,&N);
        int max = 0;
        int i;
        for (i = 0; i < N; i++)
        {
            scanf("%d",&(data[i]));
            if (data[i] > max) max = data[i];
        }
        int need = (int)(L % (long long int)(max));
        for (i = 1; i < max; i++) a[i] = INFINITY;
        sort(data,0,N-1);
        a[0] = 0;
        memset(b,0,sizeof(b));
        long long int res = INFINITY;
        if (need == 0)
        {
            res = L / (long long int)(max);
        }
        else
        {
            for (i = 0; i < N; i++)
            {
                if (data[i] != max)
                {
                    memset(flag,0,sizeof(flag));
                    int j, k, minpos;
                    long long int min;
                    for (j = 0; j < max; j++)
                    {
                        if (!flag[j])
                        {
                            //printf("<J = %d>\n",j);
                            min = a[j];
                            minpos = j;
                            k = j;
                            do
                            {
                                k = (k + data[i]) % max;
                                //printf("%d\n",k);
                                if (a[k] < min)
                                {
                                    min = a[k];
                                    minpos = k;
                                }
                            } while (k != j);
                            //printf("<MINPOS = %d>\n",minpos);
                            k = minpos;
                            do
                            {
                                flag[k] = 1;
                                if ((a[k] + 1) < a[(k+data[i]) % max])
                                {
                                    a[(k+data[i]) % max] = a[k] + 1;
                                    b[(k+data[i]) % max] = b[k];
                                    if ((k+data[i]) >= max) b[(k+data[i]) % max]++;
                                    //printf("a[%d] = %d\n",(k+data[i]) % max,a[(k+data[i]) % max]);
                                }
                                k = (k + data[i]) % max;
                                //printf("%d\n",k);
                            } while (k != minpos);
                            //printf("---------------------------------------\n");
                        }
                    }
                }
                if (a[need] != INFINITY)
                {
                    long long int temp = a[need] + ((L / (long long int)(max)) - b[need]);
                    if (temp < res) res = temp;
                }
            }
        }
        printf("Case #%d: ",iT+1);
        if (res == INFINITY) printf("IMPOSSIBLE\n");
        else printf("%lli\n",res);        
    }
    return 0;
}
