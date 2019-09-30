#include<stdio.h>
int ta[1010],to[1000010],nt[1000010],co[1000010],F[1010];
int MIN(int a,int b){return a<b?a:b;}
int MF(int s,int t,int e,int min){
  if(s==t||min==0)return min;
  int i,r;
  F[s]=1;
  for(i=ta[s];i+1;i=nt[i]){
    if(F[to[i]])continue;
    r=MF(to[i],t,e,MIN(min,co[i]));
    co[i]-=r;
    co[(i+e)%(2*e)]+=r;
    if(r)return r;
  }
  return 0;
}
//?????
//s??t??????????????v???e?a??b????c????????
int maxf(int s,int t,int v,int e,int *a,int *b,int *c){
  int i,f,r;
  for(i=0;i<v;i++)ta[i]=-1;
  for(i=0;i<e;i++){
    nt[i  ]=ta[to[i+e]=a[i]];
    nt[i+e]=ta[to[i  ]=b[i]];
    co[ta[a[i]]=i  ]=c[i];
    co[ta[b[i]]=i+e]=0;
  }
  for(f=0;r=MF(s,t,e,1000000000);f+=r){
    for(i=0;i<v;i++)F[i]=0;
  }
  return f;
}
int main(){
  int n,a[100010],b[100010],c[100010],r=0,i,j,x[1010],y[1010];
  scanf("%d",&n);
  for(i=0;i<2*n;i++)scanf("%d %d",&x[i],&y[i]);
  for(i=0;i<n;i++){
    a[r]=2*n;
    b[r]=i;
    c[r++]=1;
    a[r]=i+n;
    b[r]=2*n+1;
    c[r++]=1;
  }
  for(i=0;i<n;i++){
    for(j=n;j<2*n;j++){
      if(x[i]<x[j]&&y[i]<y[j]){
	a[r]=i;
	b[r]=j;
	c[r++]=1;
      }
    }
  }
  printf("%d\n",maxf(2*n,2*n+1,2*n+2,r,a,b,c));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:36:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<2*n;i++)scanf("%d %d",&x[i],&y[i]);
                     ^