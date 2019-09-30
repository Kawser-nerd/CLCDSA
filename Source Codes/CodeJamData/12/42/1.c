#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int r;
    int i;
} student;

int cmp(const void *a, const void *b)
{
    return ((student *)b)->r - ((student *)a)->r;
}

int maximum(int a, int b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int t, i, j;
    int a[1000][2];
    student s[1000];
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, w, l, p;
        
        scanf("%d %d %d", &n, &w, &l);
        
        for (j = 0; j < n; j++) {
            scanf("%d", &s[j].r);
            
            s[j].i = j;
            
            a[j][0] = a[j][1] = -1;
        }
        
        qsort(s, n, sizeof(student), cmp);
        
        j = 0;
        p = -s[0].r;
        
        while (1) {
            int now = -s[j].r, tmp = p;
            
            for (; j < n; j++) {
                if (now + s[j].r > l) {
                    p = tmp;
                    
                    break;
                }
                
                a[s[j].i][0] = maximum(p + s[j].r, 0);
                a[s[j].i][1] = now + s[j].r;
                
                tmp = maximum(tmp, p + s[j].r * 2);
                now = now + s[j].r * 2;
            }
            
            if (j == n) break;
        }
        
        printf("Case #%d:", i + 1);
        
        for (j = 0; j < n; j++) printf(" %d %d", a[j][0], a[j][1]);
        
        puts("");
    }
    
    return 0;
}
