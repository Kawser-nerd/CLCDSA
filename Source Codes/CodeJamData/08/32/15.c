#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 41
FILE *fi, *fo;

char s[MAX];
int n;
long put;
void desc (long nr, char d[])
{
     int i;
     for (i=0;i<MAX;i++) d[i] = 0;
     i = 0;
     while (nr)
     {
           d[i] = nr%3;
           nr/=3;
           i++;
           }
     }
     
    
int ugly(long long x)
{
    if (x == 0) return 1;
    if (x % 2 == 0) return 1;
    if (x%3 == 0) return 1;
    if (x % 5 == 0) return 1;
    if (x % 7 == 0) return 1;
    return 0;
    }
int main()
{
    int i, c, nc, j, semn, x;
    long long a, res;
    char d[MAX];
    long k, contor;
    fi = fopen ("input", "r");
    fo = fopen ("output", "w");
    
    fscanf(fi, "%d", &nc);

    for (c = 1; c<=nc; ++c)
    {      printf("%d\n", c);
           fscanf(fi, "%s", &s[0]);

           n = strlen(s);
           if (n == 1)
           {
                 if (ugly (s[0]-'0')) contor = 1;
                 else contor = 0;
                 }
           else {
           put = pow(3, n-1);
           contor = 0;
           for (k=0;k<put;k++)
           {
               desc(k, d);
                   i = 0;
                   while (d[i]==0 && i<n) i++;
                   res = 0;
                   
                   for (j=0; j<=i && j<n;j++) res = res * 10 + (s[j] - '0');
     //              fprintf(fo, "%d", res);
                   while (i<n)
                   {
                      x = i;
                      i++;
                      while (d[i] == 0 && i<n) i++;
                      a = 0;
                      for (j = x + 1; j<=i && j<n;j++) a = a * 10 + s[j] - '0';

                      if (d[x] == 1) {  res-=a;}
                      if (d[x] == 2) { res+=a;  }
  
//                      fprintf(fo, "%d", a);
                         }
  //                 fprintf(fo, "=%d\n", res);
                   if (ugly(res)) contor++;
               
           }}
           fprintf(fo, "Case #%d: %ld\n", c, contor);
    }
    fclose(fi);
    fclose(fo);
    return 0;
    }
