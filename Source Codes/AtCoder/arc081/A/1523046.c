#include<stdio.h>
int R=1,C=1,H[2000010],N[2000010];
//????????MIN?
int hyouka(int a,int b){
  if(C<b)return 1;
  if(C<a||b==0)return 0;
  return N[H[a]]>N[H[b]]?1:0;
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
  int n,i,a,b=-1;
  long long s=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    hin(a);
  }
  for(i=0;i<n;i++){
    a=N[hout()];
    if(a==b){
      if(s){
	printf("%lld\n",s*a);
	return 0;
      }
      else s=a;
      b=-1;
    }
    else b=a;
  }
  printf("0\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^