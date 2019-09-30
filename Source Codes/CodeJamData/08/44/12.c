#include <stdio.h>
#include <string.h>

int len;
char str[1024];
char nstr[1024];
int k;
int used[10];
int map[10];

int Count()
{
    int i, j;
    char c = ' ';
    int t = 0;
    for(i=0;i<len/k;i++)
        for(j=0;j<k;j++)
            nstr[i*k+j] = str[i*k+map[j]];
    nstr[len] = 0;
    for(i=0;i<len;i++)
        if ( c != nstr[i])
        {
            t++;
            c = nstr[i];
        }

    return t;
}

int Recur(int lvl)
{
    int i;
    int z;
    int min = 100000;

    if(lvl == k)
        return Count();
    else
        for(i=0;i<k;i++)
            if(used[i] == 0)
            {
                used[i] = 1;
                map[lvl] = i;
                z = Recur(lvl+1);
                if(min > z)
                    min = z;
                used[i] = 0;
            }
    return min;
}

int main(void)
{
    int ncase;
    int i;

    scanf("%d", &ncase);

    for(i=1;i<=ncase;i++)
    {
        printf("Case #%d: ", i);
        scanf("%d", &k);
        scanf("%s", str);
        len = strlen(str);

        printf("%d\n", Recur(0));
    }
    return 0;
}
