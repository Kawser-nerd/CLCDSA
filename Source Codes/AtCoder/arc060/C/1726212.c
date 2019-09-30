#include<stdio.h>
int n,x[100010],d[50][100010],i,j,a,b;
int main(){
  long long s,l;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&x[i]);
  scanf("%lld",&l);
  for(i=j=s=0;i<n;i++){
    for(;j<n;j++){
      if(x[j]-x[i]>l)break;
    }
    d[0][i]=j-1;
  }
  //for(i=0;i<n;i++)printf("%d ",d[0][i]);printf("\n");
  for(i=0;i<40;i++){
    for(j=0;j<n;j++)d[i+1][j]=d[i][d[i][j]];
  }
  scanf("%d",&n);
  while(n--){
    scanf("%d %d",&a,&b);
    s=0;
    a--;
    b--;
    if(a>b){
      i=a;
      a=b;
      b=i;
    }
    for(j=40;j--;){//printf("%d %d\n",j,d[j][a]);
      if(d[j][a]<b){
	a=d[j][a];//printf("%d ",j);
	s+=1<<j;
      }
    }
    printf("%lld\n",s+1);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&x[i]);
                   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&l);
   ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^