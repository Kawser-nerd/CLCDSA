#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define DIV 1000000007
int map[1000][1000], f[1000][1000], w, h;

long long int count(int i, int j){
  long long int sum=0;
  if(f[i][j]!=-1) return f[i][j];
  if(i!=0   && map[i-1][j]>map[i][j]) sum = (sum+count(i-1, j))%DIV;
  if(i!=h-1 && map[i+1][j]>map[i][j]) sum = (sum+count(i+1, j))%DIV;
  if(j!=0   && map[i][j-1]>map[i][j]) sum = (sum+count(i, j-1))%DIV;
  if(j!=w-1 && map[i][j+1]>map[i][j]) sum = (sum+count(i, j+1))%DIV;
  return (f[i][j]=sum+1);
}

int main(void){
  long long int ans=0;
  int i, j;
  scanf("%d %d",&h, &w);
  for(i=0;i<h;i++) for(j=0;j<w;j++){scanf("%d",&map[i][j]);  f[i][j]=-1;}
  for(i=0;i<h;i++) for(j=0;j<w;j++) ans = (ans+count(i, j))%DIV;
  printf("%lld\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&h, &w);
   ^
./Main.c:22:37: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<h;i++) for(j=0;j<w;j++){scanf("%d",&map[i][j]);  f[i][j]=-1;}
                                     ^