//?????????//
#include <stdio.h>
int max(int a,int b)
{
  int max = a;
  if (b > a)	max =b;
  return max;
}
int main(void)
{
  //??//
  int n;
  scanf("%d",&n);
  int l[n];
  int i;
  for (i =0; i < n; i++ )	{
    scanf("%d",&l[i]);
  }
  //??//
  //????????????//
  int maxi = 0;
  int place = 0;
  for(i =0; i< n; i++)	{
    maxi = max(maxi,l[i]);
    if(maxi == l[i]) place =i; 
  }
  //????maxi?????,place?????????????????????//
  int sum = 0;
  for(i = 0; i <n; i++)	{
    sum = sum + l[i];
  }
  sum = sum - l[place];
  //???sum???????????????//
  if(sum > maxi)	printf("Yes");
  else printf("No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&l[i]);
     ^