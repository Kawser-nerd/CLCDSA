#include<stdio.h>
#include<stdlib.h>
int MAX(int a,int b){return a<b?b:a;}
double f(int a,int b,int c,int d){//printf("%d %d %d %d\n",a,b,c,d);
  int i=abs(c-d);
  double s=(c+d)*i/2.0,m=b;
  a-=i;
  c=MAX(c,d);//printf("%f %d\n",s,c);
  if(c+a/2.0<m)m=c+a/2.0;//printf("%f\n",m);
  m-=c;//printf("%f\n",m);
  s+=m*m+c*(2*m);//printf("s%f\n",s);
  s+=b*(a-m*2);//printf("s%f\n",s);
  return s;
}    
int MIN(int a,int b){return a<b?a:b;}
int main(){
  int n,a[110],b[110],c[110],i,s=0;
  double ans=0;
  scanf("%d",&n);
  a[0]=b[0]=a[n+1]=b[n+1]=0;
  for(i=0;i<n;i++){
    scanf("%d",&a[i+1]);
    s+=a[i+1];
  }
  for(i=0;i<n;i++)scanf("%d",&b[i+1]);
  c[0]=0;
  for(i=1;i<=n;i++)c[i]=MIN(c[i-1]+a[i],MIN(b[i],b[i+1]));
  c[n]=0;
  for(i=n;i--;i)c[i]=MIN(c[i+1]+a[i+1],MIN(b[i],c[i]));
  //for(i=0;i<n;i++)printf("%d %d %d\n",a[i+1],b[i+1],c[i+1]);
  for(i=0;i<n;i++)ans+=f(a[i+1],b[i+1],c[i],c[i+1]);
  printf("%lf\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i+1]);
     ^
./Main.c:25:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&b[i+1]);
                   ^