#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
struct huowu
{
	int w,v;
}g[105];
huowu A[105], B[105], C[105], D[105];
bool cmp(huowu a,huowu b)
{
	return a.v > b.v;
}
int n,W;
int main()
{
	scanf("%d %d",&n,&W);
	int a, b, c, d, f;
	a = b = c = d = f = 0;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d %d",&g[i].w,&g[i].v);
		if(g[i].w == g[1].w)
		{
			A[++a] = g[i];
		}
		else if(g[i].w == g[1].w + 1)
		{
			B[++b] = g[i];
		}
		else if(g[i].w == g[1].w + 2)
		{
			C[++c] = g[i];
		}
		else if(g[i].w == g[1].w + 3)
		{
			D[++d] = g[i];
		}
	}
	sort(A + 1,A + 1 + a,cmp);
	sort(B + 1,B + 1 + b,cmp);
	sort(C + 1,C + 1 + c,cmp);
	sort(D + 1,D + 1 + d,cmp);
	LL swa[110],swb[110],swc[110],swd[110];
	LL sva[110],svb[110],svc[110],svd[110];
	swa[0] = swb[0] = swc[0] = swd[0] = 0;  
    sva[0] = svb[0] = svc[0] = svd[0] = 0;  
    for(int i = 1;i <= a;i++)  
    {  
        swa[i] = swa[i - 1] + A[i].w;  
        sva[i] = sva[i - 1] + A[i].v;  
    }  
    for(int i = 1;i <= b;i++)  
    {  
        swb[i] = swb[i - 1] + B[i].w;  
        svb[i] = svb[i - 1] + B[i].v;  
     }  
     for(int i = 1;i <= c;i++)  
     {  
         swc[i] = swc[i - 1] + C[i].w;  
         svc[i] = svc[i - 1] + C[i].v;  
     }  
     for(int i = 1;i <= d;i++)  
     {  
        swd[i] = swd[i - 1] + D[i].w;  
        svd[i] = svd[i - 1] + D[i].v;  
      }  
    int sumv = 0;  
    int ans = 0;  
	for(int i = 0;i <= a;i++)  
    {  
         for(int j = 0;j <= b;j++)  
         {  
            for(int k = 0;k <= c;k++)  
            {  
             for(int l = 0;l <= d;l++)  
              {  
			      LL sum = swa[i] + swb[j] + swc[k] + swd[l];  
					if(sum <= (LL)W)  
					{  
                      f = max((LL)f,sva[i] + svb[j] + svc[k] + svd[l]);  
					}  
			 }  
            }  
        }  
    }  
    printf("%d\n",f); 
    return 0;  
}