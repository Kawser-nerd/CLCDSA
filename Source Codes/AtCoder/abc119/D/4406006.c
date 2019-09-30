#include <stdio.h>
int main(void){
  int A,B,Q,i,j;
  long s[100000],t[100000],x[100000];
  long a1,a2,b1,b2,ans,ans2,p;
  scanf("%d %d %d",&A,&B,&Q);
  for(i=0;i<A;i++)scanf("%ld",&s[i]);
  for(i=0;i<B;i++)scanf("%ld",&t[i]);
  for(i=0;i<Q;i++)scanf("%ld",&x[i]);

  for(i=0;i<Q;i++){
    a1=20000000000;
    a2=20000000000;
    b1=20000000000;
    b2=20000000000;
    ans=20000000000;

    for(j=0;j<A;j++){
      if(x[i]<s[j]){
        if(j!=0)a1=x[i]-s[j-1];
        a2=s[j]-x[i];
        break;
      }
      else
      {
        if(j+3000<A)
        {
          if(x[i]>s[j+3000])
          {
            j+=2999;
          }
        }
      }
    }
    if(a2==20000000000)a1=x[i]-s[A-1];

    for(j=0;j<B;j++)
    {
      if(x[i]<t[j]){
        if(j!=0)b1=x[i]-t[j-1];
        b2=t[j]-x[i];
        break;
      }
      else
      {
        if(j+3000<B)
        {
          if(x[i]>t[j+3000])
          {
            j+=2999;
          }
        }
      }
    }
    if(b2==20000000000)b1=x[i]-t[B-1];

//    printf("%ld %ld %ld %ld\n",a1,a2,b1,b2);

    if(a1<b1)ans=b1;
    else{ans=a1;}

    if(a1<b2)ans2=2*a1+b2;
    else{ans2=a1+2*b2;}
    if(ans>ans2)ans=ans2;

    if(a2<b1)ans2=2*a2+b1;
    else{ans2=a2+2*b1;}
    if(ans>ans2)ans=ans2;

    if(a2>b2)ans2=a2;
    else{ans2=b2;}
    if(ans>ans2)ans=ans2;

    printf("%ld\n",ans);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&A,&B,&Q);
   ^
./Main.c:7:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<A;i++)scanf("%ld",&s[i]);
                   ^
./Main.c:8:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<B;i++)scanf("%ld",&t[i]);
                   ^
./Main.c:9:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<Q;i++)scanf("%ld",&x[i]);
                   ^