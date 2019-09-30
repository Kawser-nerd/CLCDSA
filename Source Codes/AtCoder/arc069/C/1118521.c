#include<stdio.h>
int R=1,C=1,H[2000010],N[2000010];
//????????MIN?
int hyouka(int a,int b){
  if(C<b)return 1;
  if(C<a||b==0)return 0;
  return N[H[a]]>N[H[b]]||(N[H[a]]==N[H[b]]&&H[a]<H[b])?1:0;
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
  int n,a,i,min=1e9;
  long long s=0,d[1000010]={};
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    hin(a);
  }
  hin(0);//printf("%d\n",C);
  while(C>2){
    a=hout();//printf("%d %d %d\n",N[a],a,C);
    for(s++;N[a]==N[H[1]];s++)hout();
    if(a<min)min=a;
    d[min]+=s*(N[a]-N[H[1]]);
  }
  for(i=0;i<n;i++)printf("%lld\n",d[i+1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^