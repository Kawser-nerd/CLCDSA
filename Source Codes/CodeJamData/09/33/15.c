#include  <stdio.h>
#include  <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int used_flag[110];
int to_be_rel[101];
int prison[10010];
int P, Q, min, count;

int count_coins(int pos)
{
    int count = 0, I;
    for (I=pos-1 ; I>=0 ; I--)
    {
        if (0 == prison[I])
            count++;
        if (1 == prison[I])
            break;
    }
    for (I=pos+1 ; I<=P ; I++)
    {
        if (0 == prison[I])
            count++;
        if (1 == prison[I])
            break;
    }
    return count;
}

int recuv()
{
    int I, tmp;
    for (I=0 ; I<Q ; I++)
    {
        if (1 == used_flag[I])
            continue;
        prison[to_be_rel[I]] = 1;
        used_flag[I] = 1;
        used_flag[109] += 1;
        tmp = count_coins(to_be_rel[I]);
        count += tmp;
        if (Q == used_flag[109])
            min = MIN(min, count);
        recuv();
        count -= tmp;
        used_flag[I] = 0;
        used_flag[109] -= 1;
        prison[to_be_rel[I]] = 0;
    }
}

int main(int argc, char *argv[])
{
    int x, I, J;
    FILE *pfin = fopen("C-small-attempt0.in", "r");
    FILE *pfout = fopen("C-small.out", "w");
    fscanf(pfin, "%d", &x);
    for (I=0 ; I<x ; I++)
    {
        fscanf(pfin, "%d %d", &P, &Q);
        for (J=0 ; J<Q ; J++)
            fscanf(pfin, "%d", &to_be_rel[J]);
        memset(prison, 0, sizeof(int) * 10010);
        memset(used_flag, 0, sizeof(int) * 110);
        prison[0] = 1;
        min = 0x7fffffff;
        count = 0;
        recuv();
        fprintf(pfout, "Case #%d: %d\n", I + 1, min);
    }
}
