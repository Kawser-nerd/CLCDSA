#include<stdio.h>
#include<stdlib.h>
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
  int h,w,x,a,p,d[100010],i,j;
  long long s=0;
  scanf("%d %d %d %d %d",&h,&w,&x,&a,&p);
  if(a%p==0){
    if(x<p)printf("0\n");
    else printf("%d\n",h*2-2);
    return 0;
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      hin(x);
      x=(x+a)%p;
    }
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++)d[j]=0;
    for(j=0;j<w;j++){
      a=hout()-1;//printf("%d\n",a);
      s+=abs(a/w-i);
      d[a%w]++;
    }
    for(j=x=0;j<w;j++){//printf("%d\n",d[j]-1);
      x+=d[j]-1;
      s+=abs(x);
    }
  }
  printf("%lld\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d %d",&h,&w,&x,&a,&p);
   ^