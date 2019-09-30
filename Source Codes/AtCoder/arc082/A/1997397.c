#include<stdio.h>
int main()
{
int n, x[100002]={0}, s, i, max;
scanf("%d",&n);
for(i=0;i<n;i++)
{
  scanf("%d",&s);
  x[s]++;
}
 max = 0;
for(i=0;i<=100000;i++)
{
  s=x[i]+x[i+1]+x[i+2];
  if(s>max )
  {
    max = s;
  }
}
printf("%d\n", max);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&n);
 ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&s);
   ^
./Main.c:14:18: warning: iteration 100000u invokes undefined behavior [-Waggressive-loop-optimizations]
   s=x[i]+x[i+1]+x[i+2];
                  ^
./Main.c:12:1: note: containing loop
 for(i=0;i<=100000;i++)
 ^