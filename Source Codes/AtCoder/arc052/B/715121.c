#include <stdio.h>
#include<math.h>
#define MAX_N 100
#define MAX_Q 10000
#define pi 3.14159265359
int main(){
  int n,q;
  int i,j;
  int x[MAX_N],r[MAX_N],h[MAX_N];
  int a,b;
  double v=0;
  double ans=0;
  double ratio=0;
  double t=0;
  double X,R,H;
  scanf("%d %d",&n,&q);
  for(i=0;i<n;i++)scanf("%d %d %d",&x[i],&r[i],&h[i]);
  for(i=0;i<q;i++){
    scanf("%d %d",&a,&b);
    ans=0;
    for(j=0;j<n;j++){
      X=x[j];R=r[j];H=h[j];
      if(X>=b)v=0;
       else if(X<a){
	 if(X+H<=a)v=0;
	 else if(X+H<=b) v=R*R*H*pow(X+H-a,3)/pow(H,3);
	 else if(X+H>b)  v=R*R*H*((pow(X+H-a,3)-pow(X+H-b,3))/pow(H,3));
	   }
       
       else {
	 if(x[j]+h[j]>b) v=R*R*H*((pow(H,3)-pow(X+H-b,3))/pow(H,3));
	 else v=R*R*H;
       }
      
      ans+=v;
	//printf("%f %f %f\n",ans,v,ratio);
    }
    ans*=pi/3;
    printf("%f\n",ans);
  }
  /*
    if(b<=x[j] || x[j]+h[j]<=a)          {ratio=0;printf("0 ");} //ok
    else if(a<=x[j] && x[j]+h[j]<=b)   {ratio=1.0;printf("1 ");} //ok
    else if(x[j]<=a && b<=x[j]+h[j])   {ratio=(t-pow(x[j]+h[j]-b,3))/t;printf("2 ");} //ok
    else if(x[j]<=a && x[j]+h[j] <= b) {ratio=pow(x[j]+h[j]-a,3)/t;printf("3 ");}
    else if(a<x[j] && b<=x[j]+h[j])   {ratio=(t-pow(x[j]+h[j]-b,3))/t;printf("4 ");}
  */
  
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&q);
   ^
./Main.c:17:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d %d %d",&x[i],&r[i],&h[i]);
                   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^