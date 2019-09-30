#include <stdio.h>

int main()
{
    int t, casenum;
    int c, d, p, v;
    
    struct {
        double p, x, d;
    } groups[200];
    int groupcount;
    int i;
    double s1, s2;
    double result;
    
    scanf("%d", &t);
    
    for (casenum=1; casenum<=t; casenum++)
    {
        scanf("%d%d", &c, &d);
        groupcount = 0;
        for (i=0; i<c; i++)
        {
            scanf("%d%d", &p, &v);
            groups[groupcount].p = p - (v-1) / 2.0 * d;
            groups[groupcount].x = p + (v+1) / 2.0 * d;
            groups[groupcount].d = (v-1) / 2.0 * d;
            
            while (groupcount > 0 && groups[groupcount].p < groups[groupcount-1].x)
            {
                s1 = groups[groupcount-1].x - groups[groupcount].p;
                if (groups[groupcount-1].d + s1 <= groups[groupcount].d)
                {
                    groups[groupcount-1].p = groups[groupcount-1].p - s1;
                    groups[groupcount-1].x = groups[groupcount].x;
                    groups[groupcount-1].d = groups[groupcount].d;
                }
                else if (groups[groupcount].d + s1 <= groups[groupcount-1].d)
                {
                    groups[groupcount-1].x = groups[groupcount].x + s1;
                }
                else
                {
                    s2 = (groups[groupcount-1].d - groups[groupcount].d + s1) / 2;
                    s1 = (groups[groupcount].d - groups[groupcount-1].d + s1) / 2;
                    groups[groupcount-1].p = groups[groupcount-1].p - s1;
                    groups[groupcount-1].x = groups[groupcount].x + s2;
                    groups[groupcount-1].d = groups[groupcount-1].d + s1;
                }
                groupcount--;
            }
            groupcount++;
        }
        
        result = 0;
        for (i=0; i<groupcount; i++)
            if (groups[i].d > result)
                result = groups[i].d;
        printf("Case #%d: %f\n", casenum, result);
    }
    
    return 0;
}
