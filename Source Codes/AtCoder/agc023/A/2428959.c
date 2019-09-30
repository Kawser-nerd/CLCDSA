#include<stdio.h>
long long R=1,C=1,H[2000010],N[2000010];
//????????MIN?
int hyouka(int a,int b){
  if(C<b)return 1;
  if(C<a||b==0)return 0;
  return N[H[a]]<N[H[b]]?1:0;
}
//????
void hin(long long a){
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
  long long n,i,d[200010];
  long long s=0,a,b=-1,c=1,e;
  scanf("%lld",&n);
  for(i=0;i<n;i++)scanf("%lld",&d[i]);
  for(i=0;i<n;i++){
    d[i+1]+=d[i];
    hin(d[i]);
  }
  for(i=0;i<n;i++){
    a=N[hout()];//printf("%lld\n",a);
    if(b==a){
      c++;
    }
    else{
      if(b==0)c++;//printf("C%lld\n",c);
      s+=c*(c-1)/2;
      c=1;
    }
    b=a;
  }//printf("%lld %lld\n",s,c);
  if(b==0)c++;
  s+=c*(c-1)/2;
  printf("%lld\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^
./Main.c:26:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%lld",&d[i]);
                   ^