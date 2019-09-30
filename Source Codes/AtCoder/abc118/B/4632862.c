#include <stdio.h>
int main (void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n][m];
	  // ????????????OK!//
    for (int i =0; i < n; i ++)	{
      for (int j = 0; j < m; j++)	{
        a[i][j] = -1;
      }
	}
	int k[n];
    for (int i = 0; i <  n; i = i +1)	{
      scanf("%d", &k[i]);
      	for (int j = 0; j < k[i] ; j = j+1)	{
          scanf("%d", &a[i][j]);
        }
    }
	// ????????????????//
   int ch[m];
   // vecot ch?0???????//
   for (int i =0; i < m; i++)	{
     ch[i] = 0;
   }
   for (int i = 0; i < m; i++)	{
     for (int j =0; j < n; j ++)	{
       for (int l = 0; l < k[j]; l++)	{
		   if (a[j][l] == i+1)	ch[i] ++;
	   }
     }
   }
   int ans = 0;
   for (int i = 0; i <m; i ++)	{
     if (ch[i] == n)	ans ++;
   }
   printf("%d", ans);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:15:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d", &k[i]);
       ^
./Main.c:17:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
           scanf("%d", &a[i][j]);
           ^