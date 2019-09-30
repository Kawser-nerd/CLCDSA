#include <stdio.h>
#include <string.h>

#define BOTH 0
#define TAKA 1
#define HASI 2

#define DEBUG
#undef DEBUG

int main(int argc, char *argv[])
{
    int  N, M;
    int  from, to;
    int  old, new;
    char swapflag;
    int  i, j, k;
    int  ans;

    char bridge[700][700] = {0};
    long state[700] = {0};
   int  citynum[700 / 2 * 3] = {0};
    int  tmpstatearray[700/2] = {0};

    int tmpstatecnt = 0;

    /* N M???? */
    (void)scanf("%d %d%*c",&N, &M);

    /* ????? */
    for (i=0; i<M; i++)
    {
        (void)scanf("%d %d%*c",&from, &to);
        from-=1;
        to-=1;
        if (from < to)
        {
            bridge[from][to] = 1;
        }
        else
        {
            bridge[to][from] = 1;
        }
    }

    /* ??????? */
    for (i=0; i<N; i++)
    {
        for(j=i+1; j<N; j++)
        {
            if (bridge[i][j]==0)
            {
#ifdef DEBUG
                printf("%3d<-//->%3d\n", i+1, j+1);
#endif
                if (state[i] != BOTH && state[j] != BOTH)
                {
                    if (state[i] == state[j])
                    {
                        /* ?? */
                        printf("-1\n");
                        return 0;
                    }
                    else
                    {
                        /* ?????????????????? */
                       if (state[i] < state[j])
                        {
                            old = state[j] >> 2;
                            new = state[i] >> 2;
                        }
                        else
                        {
                            old = state[i] >> 2;
                            new = state[j] >> 2;
                        }

                        if ((state[i] & 0x3) == (state[j] & 0x3))
                        {
                            swapflag = 1;
                        }
                        else
                        {
                            swapflag = 0;
                        }
#ifdef DEBUG
                        printf("change state base %d to %d (swapflag %d)\n", old << 2, new << 2, swapflag);
#endif
                        for (k=0; k<N; k++)
                        {
                            if ((state[k] >> 2) == old)
                            {
#ifdef DEBUG
                                printf("city : %3d old state : %d ", k+1, state[k]);
#endif
                                state[k] = ((state[k] & 0x3) ^ (0x3 * swapflag)) | (new << 2);
#ifdef DEBUG
                                printf("new state : %d\n", state[k]);
#endif
                            }
                        }
                    }
                }
                else if (state[i] != BOTH)
                {
                    state[j] = state[i] ^ 0x3;
#ifdef DEBUG
                    printf("city : %3d state : %d\n", j+1, state[j]);
#endif
                }
                else if (state[j] != BOTH)
                {
                    state[i] = state[j] ^ 0x3;
#ifdef DEBUG
                    printf("city : %3d state : %d\n", i+1, state[i]);
#endif
                }
                else
                {
                    state[i] = TAKA | (tmpstatecnt << 2);
                    state[j] = HASI | (tmpstatecnt << 2);
                    tmpstatearray[tmpstatecnt-1] = tmpstatecnt;
                    tmpstatecnt++;
#ifdef DEBUG
                    printf("city : %3d state : %d\n", i+1, state[i]);
                    printf("city : %3d state : %d\n", j+1, state[j]);
#endif
                }
            }
        }
    }

    /* ?????? */
#ifdef DEBUG
        printf("check citynum\n");
#endif
    for (i=0; i<N; i++)
    {
#ifdef DEBUG
        printf("city : %3d state : %d\n", i+1, state[i]);
#endif
        citynum[state[i]]++;
    }

    /* ??????? */
    for (i=1; i<tmpstatecnt; i++)
    {
        /* ?????????????? */
        if ( (citynum[TAKA] < citynum[HASI]) == (citynum[TAKA | (i << 2)] < citynum[HASI| (i << 2)]) )
        {
            citynum[TAKA] += citynum[HASI | (i << 2)];
            citynum[HASI] += citynum[TAKA | (i << 2)];
        }
        else
        {
            citynum[TAKA] += citynum[TAKA | (i << 2)];
            citynum[HASI] += citynum[HASI | (i << 2)];
        }
    }

#ifdef DEBUG
    printf("TAKA %d\n", citynum[TAKA]);
    printf("HASI %d\n", citynum[HASI]);
    printf("BOTH %d\n", citynum[BOTH]);
#endif

    /* ???????????????? */
    for (i=0; i<N; i++)
    {
        if (state[i] != BOTH) continue;

        citynum[BOTH]--;
        if (citynum[TAKA] < citynum[HASI])
        {
            state[i] = TAKA;
            citynum[TAKA]++;
        }
        else
        {
            state[i] = HASI;
            citynum[HASI]++;
        }
    }

    /* ???? */
    ans = 0;
    if (citynum[TAKA] >= 2) ans += (citynum[TAKA] * (citynum[TAKA]-1))/2;
    if (citynum[HASI] >= 2) ans += (citynum[HASI] * (citynum[HASI]-1))/2;

    printf("%d\n", ans);

    return(0);
} ./Main.c: In function ‘main’:
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     (void)scanf("%d %d%*c",&N, &M);
     ^
./Main.c:33:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         (void)scanf("%d %d%*c",&from, &to);
         ^