#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int list, heights[100000], ans[2000];
int compare(const void* a, const void* b)
{
        return *(int*)a-*(int*)b;
}
int main()
{
        int t, cn;
        scanf("%d", &t);
        for(cn=1; cn<=t; cn++)
        {
                int n, i, j, c=0;
                for(i=0;i<100000;i++)
                        heights[i]=0;
                scanf("%d", &n);
                for(i=0;i<2*n-1;i++)
                {
                        for(j=0;j<n;j++)
                        {
                                scanf("%d", &list);
                                heights[list]++;
                        }
                }
                for(i=0;i<100000;i++)
                {
                        if(heights[i]%2==0)
                                continue;
                        ans[c++]=i;
                }
                qsort(ans, c, 4, compare);
                printf("Case #%d:", cn);
                for(i=0;i<c;i++)
                        printf(" %d", ans[i]);
                printf("\n");
        }
        return 0;
}
