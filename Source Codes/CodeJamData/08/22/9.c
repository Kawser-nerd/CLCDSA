#include <stdio.h>
#define NMAX 1001
FILE *fi, *fo;
int a, b, p;
int sol[NMAX];
int cnt [NMAX];

int prime (int p)
{
    int d, sqr;
    for (sqr = 1; sqr*sqr <= p; sqr++);
    if (p == 2) return 1;
    if (p%2 == 0 ) return 0;
    for (d=3;d<sqr;d+=2) 
        if (p%d == 0) return 0;
     return 1;
    }
int main()
{
    int c, nc, i, j,  x;
    fi = fopen ("input", "r");
    fo = fopen ("output", "w");
    
    fscanf(fi, "%d", &nc);
    for (c = 1; c<=nc; ++c)
    {
        fscanf(fi, "%d %d %d", &a, &b, &p);
        for (i= 0;i<=b;i++) sol[i] = cnt[i] = 0;
        while (p<=b)
        {
              if (prime(p))
              {
              x = a;
              while (x%p!=0) x++;
              for (i = x; i<=b;i+=p) 
              {
                  x = sol[i];
                  sol[i] = p;
                  if (x!=0)
                     for (j=a;j<=b;j++)
                         if (sol[j] == x) sol[j] = p;
                  } 
              }
              p++;
              }
        for (i=a;i<=b;i++)
        {
           // fprintf(fo, "%d %d\n", i, sol[i]);
            if (sol[i] == 0) cnt[0]++; 
            else cnt[sol[i]] = 1;
        }
        x = 0;
        for (i = 0; i<=b;i++) x+=cnt[i];
        
        fprintf(fo, "Case #%d: %d\n", c, x);
        }
    
    fclose(fi);
    fclose(fo);
    return 0;
    }
