ch#include<stdio.h>
#include<string.h>

char num[50];
int op[50];
int L, Res;

void process()
{
     long long n, k;
     int p, i, l, j;
     n = 0;
     for(l = 0,i = 1; i <= L; ++i)
     {
         if(op[i] || i == L)
         {
             k = 0;
             for(j = l; j < i; ++j)
                 k = k * 10 + num[j] - '0';
             if(l == 0 || op[l] == 1) n += k;
             else n -= k;
             l = i;
         }
     }
     if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) ++Res;
}
void A(int p)
{
     if(p == L)
     {
          process();
     }
     else
     {
         op[p] = 0;
         A(p + 1);
         op[p] = 1;
         A(p + 1);
         op[p] = 2;
         A(p + 1);
     }
}

int main()
{
    int t, ctr = 0;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", num);
        L = strlen(num);
        Res = 0;
        memset(op, 0, sizeof(op));
        A(1);
        printf("Case #%d: %d\n", ++ctr, Res);
    }
}
