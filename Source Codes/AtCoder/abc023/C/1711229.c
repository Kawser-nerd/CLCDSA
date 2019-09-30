#include<stdio.h>
int main(){
  int h,w,n,m,i,a[100010],b[100010],y[100010],x[100010];
  long long s=0,yc[100010],xc[100010];
  for(i=0;i<100005;i++)yc[i]=xc[i]=y[i]=x[i]=0;
  scanf("%d %d %d %d",&h,&w,&m,&n);
  for(i=0;i<n;i++){
    scanf("%d %d",&a[i],&b[i]);
    y[a[i]]++;
    x[b[i]]++;
  }//printf("a\n");
  for(i=0;i<h;i++)yc[y[i+1]]++;
  for(i=0;i<w;i++)xc[x[i+1]]++;
  //for(i=0;i<6;i++)printf("%d %lld %lld\n",i,yc[i],xc[i]);
  for(i=0;i<=m;i++)s+=yc[i]*xc[m-i];//printf("%lld\n",s);
  for(i=0;i<n;i++){
    if(y[a[i]]+x[b[i]]==m+1)s++;
    if(y[a[i]]+x[b[i]]==m)s--;
  }//printf("b\n");
  printf("%lld\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d",&h,&w,&m,&n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a[i],&b[i]);
     ^