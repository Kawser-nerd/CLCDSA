#include <stdio.h>
int max(int a, int b){
  return (a>b)?a:b;
}
int min(int a, int b){
  return (a<b)?a:b;
}
int main(){
  int n,mm,count;
  int x[55]={},y[55]={};
  long long int m=0,h=0,u=0,s=0;
  unsigned long long int ans;
  scanf("%d%d",&n,&mm);
  for(int i=0;i<n;i++){
    scanf("%d%d",&x[i],&y[i]);
    m=max(x[i],m); h=min(x[i],h);
    u=max(y[i],u); s=min(y[i],s);
  }
  ans=(m-h)*(u-s);
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      for(int k=j;k<n;k++){
        for(int l=k;l<n;l++){
          m=max(max(x[i],x[j]),max(x[k],x[l]));
          h=min(min(x[i],x[j]),min(x[k],x[l]));
          u=max(max(y[i],y[j]),max(y[k],y[l]));
          s=min(min(y[i],y[j]),min(y[k],y[l]));
          count=0;
          for(int g=0;g<n;g++){
            if(h<=x[g] && x[g]<=m && s<=y[g] && y[g]<=u) count++;
          }
          if(count>=mm && ans>(m-h)*(u-s)){
            ans=(m-h)*(u-s);
          }
        }
      }
    }
  }
  printf("%llu",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&mm);
   ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x[i],&y[i]);
     ^