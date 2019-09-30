#include <stdio.h>
#include <stdlib.h>

int unhappy[][7] = {
    {0},
    {0},
    {0},
    {2, 5, 8, 0},
    {0},
    {4, 13, 18, 0},
    {5, 0},
    {2, 25, 10, 13, 45, 32, 0},
    {4, 5, 13, 20, 52, 0},
    {50, 53, 41, 68, 0},
    {4, 0}
};

int happy(int n, int b)
{
    int next, i;
    if (b==2 || b==4)
        return 1;
    
    while (n != 1)
    {
        next = 0;
        while (n>0)
        {
            next += (n%b)*(n%b);
            n/=b;
        }
        n = next;
        for (i=0; unhappy[b][i]; i++)
            if (n == unhappy[b][i])
                return 0;
    }
    return 1;
}

int main()
{
    int case_count, case_index;
    char in[20], *p;
    int base_list[10];
    int n, i, uh;
    
    scanf("%d", &case_count);
    getchar();
    for (case_index=1; case_index<=case_count; case_index++)
    {
        fgets(in, 20, stdin);
        p=in;
        for (i=0; *p!='\0'; i++)
        {
            base_list[i] = (int) strtol(p, &p, 10);
            p++;
        }
        base_list[i] = 0;
        
        n = uh = 1;
        while (uh)
        {
            n++;
            uh = 0;
            for (i=0; base_list[i]; i++)
                uh = uh || !happy(n, base_list[i]);
        }
        printf("Case #%d: %d\n", case_index, n);
    }
    return 0;
}
