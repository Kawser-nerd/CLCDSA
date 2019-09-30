int comp(int *a, int *b)
{
    return *a - *b;
}

int main()
{
    int T;
    int t;
    scanf("%d", &T);
    for (t = 0; t < T; t++)
    {
        int n; 
        scanf("%d", &n);
        int a[20]; // n == 20
        int i;
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        qsort(a, 20, sizeof(int), comp);
        int j;
        int sig = 0;
        printf("Case #%d:\n", t + 1);
        for (i = 1; i < (1l<<20); i++)
        {
            for (j = 1; j < (1l<<20); j++)
                if ((i & j) == 0)
                {
                    int k;
                    int s1 = 0;
                    for (k = 0; k < 20; k++)
                        if (i & (1 << k))
                            s1 += a[k];
                    int s2 = 0;
                    for (k = 0; k < 20; k++)
                        if (j & (1 << k))
                            s2 += a[k];
                    if (s1 == s2)
                    {
                        for (k = 0; k < 20; k++)
                            if (i & (1 << k))
                                printf("%d%s", a[k], i >> (k + 1) ? " " : "\n");
                        for (k = 0; k < 20; k++)
                            if (j & (1 << k))
                                printf("%d%s", a[k], j >> (k + 1) ? " " : "\n");
                        sig = 1;
                        break;
                    }
                    else if (s1 < s2)
                        break;
            }
            if (sig == 1)
                break;
        }   
        if (sig == 0)
            printf("Impossible\n");
    }
    return 0;
}
