#include<stdio.h>
int R=1,C=1,H[500010],N[500010],A[500010],B[500010];
//????????MAX?
int hyouka(int a,int b){
  if(C<b)return 1;
  if(C<a||b==0)return 0;
  return N[H[a]]>N[H[b]]||N[H[a]]==N[H[b]]&&A[H[a]]==-1?1:0;
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
int c,a,b,ans[500010],d[500010],p[500010],co[500010]={0};
int main(){
  int n,m,i,q,h,r;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)co[i+1]=1;
  for(i=0;i<m;i++){
    scanf("%d %d %d",&A[R],&B[R],&c);
    hin(c);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d %d",&B[R],&c);
    A[R]=-1;
    hin(c);
  }
  for(i=0;i<m+q;i++){
    h=hout();
    a=A[h];
    b=B[h];
    //printf("%d %2d %2d %d\n",h,a,b,N[h]);
    if(a+1){
      for(r=  a;p[r];r=p[r]);
      for(;n=p[a];a=n)p[a]=r;
      for(r=  b;p[r];r=p[r]);
      for(;n=p[b];b=n)p[b]=r;
      if(a-b){//printf("\n");
	d[a]<d[b]?(p[a]=b):(p[b]=a);
	if(d[a]==d[b])d[a]++;
	co[a]=co[b]=co[a]+co[b];
      }
    }
    else {//printf("\n");
      for(r=  b;p[r];r=p[r]);
      ans[h-m-1]=co[r];
    }
    //for(c=1;c<6;c++)printf("%d ",co[c]);printf("\n");
  }
  for(i=0;i<q;i++)printf("%d\n",ans[i]);    
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&A[R],&B[R],&c);
     ^
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:33:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&B[R],&c);
     ^