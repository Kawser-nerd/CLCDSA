#include<stdio.h>
int R=1,C=1,H[2000010],N[2000010];
//????????MIN?
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
int main(){
  int n,m,i;
  long long s=0,a,b=-1,c=1;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++){
    scanf("%lld",&a);
    s=(s+a)%m;//printf("%lld\n",s);
    hin(s);
  }
  hin(1e9+10);
  b=N[hout()];
  c=1;//printf("\n%lld\n",b);
  //for(i=0;i<m;i++)printf("%lld\n",b[i]);
  for(i=s=0;i<n;i++){
    a=N[hout()];//printf("%lld\n",a);
    if(a==b)c++;
    else{//printf("%lld %lld\n",b,c);
      s+=(c*(c+1)/2);
      if(b)s-=c;
      b=a;
      c=1;
    }
  }
  printf("%lld\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&a);
     ^