#include<stdio.h>
int p[100010]={0};
int d[100010]={0};
int S[100010];//?????? ???
//for(i=0;i<100010;i++)S[i]=1;
int Find(int a,int b){
  int r,n;
  for(r=++a;p[r];r=p[r]);
  for(;n=p[a];a=n)p[a]=r;
  for(r=++b;p[r];r=p[r]);
  for(;n=p[b];b=n)p[b]=r;
  return a-b?1:0;
}
void Union(int a,int b){
  if(Find(a,b)){
    for(++a;p[a];a=p[a]);
    for(++b;p[b];b=p[b]);
    d[a]<d[b]?(p[a]=b):(p[b]=a);
    if(d[a]==d[b])d[a]++;
    S[a]=S[b]=S[a]+S[b];
  }
}
int main(){
  int n,m,a,b,i;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)scanf("%d",&d[i]);
  for(i=0;i<m;i++){
    scanf("%d %d",&a,&b);
    Union(a,b);
  }
  for(i=a=0;i<n;i++)a+=Find(i+1,d[i]);
  printf("%d\n",n-a);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:26:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&d[i]);
                   ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^