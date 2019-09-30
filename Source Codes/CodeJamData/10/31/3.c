#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct wire
{
    int a, b;
};

int compare_a(const void * x, const void * y)
{
    return (((struct wire *)x)->a) - (((struct wire *)y)->a);
}

int main()
{
    int t, n;
    struct wire wires[MAX], temp;
    int casenum, i, j, count;
    
    scanf("%d", &t);
    for (casenum=1; casenum<=t; casenum++)
    {
        scanf("%d", &n);
        for (i=0; i<n; i++)
            scanf("%d%d", &wires[i].a, &wires[i].b);
        
        qsort(wires, n, sizeof(struct wire), compare_a);
        
        count = 0;
        for (i=n; i>1; i--)
            for (j=1; j<i; j++)
                if (wires[j].b < wires[j-1].b)
                {
                    count++;
                    temp = wires[j];
                    wires[j] = wires[j-1];
                    wires[j-1] = temp;
                }
        
        printf("Case #%d: %d\n", casenum, count);
    }
    return 0;
}
