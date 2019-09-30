#include <stdio.h>
#include <stdlib.h>
int compare_int(const void *a, const void *b){
    return *(int*)b - *(int*)a;
}
void sort(int *v,int size)
{
  int i,j,temp;
  for(i=0;i<size;i++)	{
    for(j=0;j<size-1 ;j++)	{
      if(v[j] < v[j+1])	{
        temp = v[j];
        v[j] = v[j+1];
        v[j+1] = temp;
      }
    }
  }
}
 
//sort???????????????//
int main (void)
{
  int n,m;
  scanf("%d %d",&n,&m);
  int x[m];
  int i;
  for (i = 0; i < m; i++)	{
    scanf("%d",&x[i]);
  }
  //??????//
  if(n >= m)	printf("0");
  else	{
    qsort(x,m,sizeof(int),compare_int);
    //???gap?????sort???//
    int gap[m-1];
    for (i=0;i < m-1; i++)	{
      if (x[i+1] > x[i])  gap[i] = x[i+1] - x[i];
      else gap[i] = x[i] - x[i+1];
    }
    qsort(gap,m-1,sizeof(int),compare_int);
    int ans = 0;
    for (i = 0; i < m-n; i++) {
      ans = ans + gap[m-2-i];
    }
    printf("%d",ans);
  }
} ./Main.c: In function ‘main’:
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x[i]);
     ^