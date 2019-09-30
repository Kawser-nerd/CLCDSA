#include <stdio.h>
#define abs(a) ((a)>(0)?(a):-(a))
int n,A,B,C;
int min(int a,int b,int c,int d){
  int min=a;
  if(b<min)min=b;
  if(c<min)min=c;
  if(d<min)min=d;
  return min;
}
int dfs(int a,int b,int c,int d,int *l){
  if(d==n&&(a*b*c>0)) return abs(a-A)+abs(b-B)+abs(c-C)-30;
  else if(d==n)return 1e9;
  else{
     int r1=dfs(a,b,c,d+1,l);
     int r2=dfs(a+l[d],b,c,d+1,l)+10;
     int r3=dfs(a,b+l[d],c,d+1,l)+10;
     int r4=dfs(a,b,c+l[d],d+1,l)+10;
    return min(r1,r2,r3,r4);
  }
}
int main(){
  int i;
  scanf("%d%d%d%d",&n,&A,&B,&C);
  int l[n];
  for(i=0;i<n;i++)scanf("%d",&l[i]);
  printf("%d",dfs(0,0,0,0,l));
} ./Main.c: In function ‘main’:
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&n,&A,&B,&C);
   ^
./Main.c:26:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&l[i]);
                   ^