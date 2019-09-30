#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MX 100
int N;
 long long totsol;
char s[MX];
long long sol[MX];
long long m2[MX][2], m3[MX][3], m5[MX][5], m7[MX][7];
 long long num[MX][MX];
int ln;
int isUgly(long long p)
{
    long long n;
    if(p<0)
    n = (-p);
    else
    n = (p);
    if((n%2) == 0 || (n%3) ==0 || (n%5) == 0 || (n%7) == 0)
    return 1;
    return 0;
}
 long long getstr(int i, int j)
{
          long long ret = 0;
         while(i<j)
         {
                   ret *= 10;
                   ret += (s[i]-'0');
                   i++;
         }
         //printf("%lld\n", ret);
         return ret;
}
void computeUgly( long long val, int pos, int pp, int sign)
{
         if(pos >= ln)
         {
                //printf("%lld",num[pp][pos]);
                val += sign*num[pp][pos];
                //printf("=%lld\n", val);
                if(isUgly(val))
                totsol++;
                return;
         }
         /* Insert nothing */
         computeUgly(val, pos+1, pp, sign);
         /* Insert + or -*/
         if(pos > pp)
         {
                //printf("%lld",num[pp][pos]);
                val += sign*num[pp][pos];
                //printf("+");
                computeUgly(val, pos+1, pos, 1);
                //printf("-");
                computeUgly(val, pos+1, pos, -1);
         }
         

}
int main()
{
    int cs, i, j, n;
    scanf("%d",&N);
    for(cs=1; cs<=N; cs++)
    {
     scanf("%s", s);
     ln = strlen(s);
     
     for(i=0;i<ln;i++)
     for(j=(i+1);j<=ln;j++)
     num[i][j] = getstr(i,j);
    
     totsol = 0;
     computeUgly(0, 0, 0, 1);
     printf("Case #%d: %lld\n", cs, totsol);
    }
    system("PAUSE");
    return 0;
}
