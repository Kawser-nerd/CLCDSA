#include<stdio.h>
int w,h;
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
int f(int a,int b){return (a==0||a==w||b==0||b==h)?1:0;}
int main(){
  int n,i,j,p[100010][4],r,d[200010],e[100010];
  scanf("%d %d %d",&w,&h,&n);
  for(i=0;i<n;i++){
    scanf("%d %d %d %d",&p[i][0],&p[i][1],&p[i][2],&p[i][3]);
    //printf("%d %d\n",f(p[i][0],p[i][1]),f(p[i][2],p[i][3]));
  }
  for(j=r=0;j<4;j++){
    for(i=0;i<n;i++){
      if(f(p[i][0],p[i][1])*f(p[i][2],p[i][3])==0)continue;
      if(j==0&&p[i][0]==0&&p[i][1]!=0)e[R]=i,hin(  p[i][1]);
      if(j==0&&p[i][2]==0&&p[i][3]!=0)e[R]=i,hin(  p[i][3]);
      if(j==1&&p[i][1]==h&&p[i][0]!=0)e[R]=i,hin(  p[i][0]);
      if(j==1&&p[i][3]==h&&p[i][2]!=0)e[R]=i,hin(  p[i][2]);
      if(j==2&&p[i][0]==w&&p[i][1]!=h)e[R]=i,hin(h-p[i][1]);
      if(j==2&&p[i][2]==w&&p[i][3]!=h)e[R]=i,hin(h-p[i][3]);
      if(j==3&&p[i][1]==0&&p[i][0]!=w)e[R]=i,hin(w-p[i][0]);
      if(j==3&&p[i][3]==0&&p[i][2]!=w)e[R]=i,hin(w-p[i][2]);
    }
    while(C-1){
      d[r++]=e[hout()];//printf("%d\n",d[r-1]);
      if(r>1&&d[r-1]==d[r-2])r-=2;
    }
    R=C=1;
  }
  printf("%s\n",r?"NO":"YES");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&w,&h,&n);
   ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d",&p[i][0],&p[i][1],&p[i][2],&p[i][3]);
     ^