#include <stdio.h>

#define true 1
#define false 0

typedef unsigned char bool;

#define inf 0x3e3e3e3e;

int min;
int mat[32][32];

int calcHapp(int r, int c)
{
    int sum = 0;
    int i, k;
    
    for(i = 1; i <= r; i++)
        for(k = 1; k <= c; k++)
        {
            sum += (mat[i][k]) ? mat[i-1][k] + mat[i+1][k] + mat[i][k+1] + mat[i][k-1] : 0;
        }
            
    return sum/2;
}

void bcktr(int r, int c, int sizer, int sizec, int cur, int n)
{
    int m;
    int i, k;

#ifdef _DEBUG
    printf("1 - %d %d %d\n", r, c, cur);
#endif
    if(cur == n)
    {
        m = calcHapp(sizer, sizec);
        min = (min > m) ? m : min;
#ifdef _DEBUG
        for(i = 1; i <= sizer; i++)
            for(k = 1; k <= sizec; k++)
                printf("%d%c", mat[i][k], (k<sizec) ? ' ' : '\n');
        printf("MIN:%d - %d\n", min, m);
#endif
        return ;
    }
#ifdef _DEBUG
    printf("2 - %d %d %d\n", r, c, cur);
#endif
    
    if(c < sizec)
        c++;
    else
    {
        r++;
        c = 1;
    }
    
#ifdef _DEBUG
    printf("laco %d %d %d %d\n", r, c, sizer, sizec);
#endif
    for(i = r; i <= sizer; i++)
        for(k = (i > r) ? 1 : c; k <= sizec; k++)
        {
            mat[i][k] = 1;
            bcktr(i, k, sizer, sizec, cur+1, n);
            mat[i][k] = 0;
        }
#ifdef _DEBUG
    printf("endlaco\n");
#endif
        
}

int main()
{
    int T, cont = 0;
    
    scanf("%d\n", &T);
    while(T--)
    {
        int r, c, n, size;
        int i, k;
        
        scanf("%d %d %d\n", &r, &c, &n);
        
        size = r*c;
        if(n <= (size+1)/2)
        {
            printf("Case #%d: 0\n", ++cont);
            continue ;
        }
        
        for(i = 0; i <= r+1; i++)
            for(k = 0; k <= c+1; k++)
                mat[i][k] = 0;
    
        min = inf;
            
        for(i = 1; i <= r; i++)
            for(k = 1; k <= c; k++)
            {
                //if(size-((i-1)*c + k) < n)
                //    continue ;

                mat[i][k] = 1;
                bcktr(i, k, r, c, 1, n);
                mat[i][k] = 0;
            }
        
        printf("Case #%d: %d\n", ++cont, min);
    }
    
return 0;
}
