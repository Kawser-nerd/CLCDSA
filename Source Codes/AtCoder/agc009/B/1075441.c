#include<stdio.h>
int R=1,C=1,H[2000010],N[2000010];
//????????MAX?
int hyouka(int a,int b){
  if(C<b)return 1;
  if(C<a||b==0)return 0;
  return N[H[a]]<N[H[b]]?1:0;
}
//????
void hin(int a){
  int i=C++;
  for(N[H[0]=R]=a;hyouka(0,i/2);i/=2)H[i]=H[i/2];
  H[i]=R++;
}
//??????
int hout(){
  int rt=H[1],i,j=2,k=H[--C];
  for(i=1;hyouka(i,C);i=j)H[i]=H[j=i*2+1-hyouka(i*2,i*2+1)];
  H[j/2]=k;
  return rt;
}
int ta[100010],to[100010],co[100010],nt[100010],s[100010];
int MAX(int a,int b){return a>b?a:b;}
int f(int n){//printf("in%d\n",n);
  int i,j;
  for(i=ta[n];i+1;i=nt[i])co[to[i]]=f(to[i]);
  R=C=1;
  for(i=ta[n];i+1;i=nt[i])hin(co[to[i]]);//printf("%d %d\n",n,C);
  if(C==1)return 0;
  for(i=0;C-1;i++)s[i]=N[hout()];
  //for(j=0;j<i;j++)printf("%d,",s[j]);printf("\n");
  for(j=1;j<i;j++)s[j]=MAX(s[j-1]+1,s[j]);
  return s[i-1]+1;
}
int main(){
  int n,a,i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++)ta[i+1]=-1;
  for(i=1;i<n;i++){
    scanf("%d",&a);
    to[i]=i+1;
    nt[i]=ta[a];
    ta[a]=i;
  }
  printf("%d\n",f(1));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:40:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^