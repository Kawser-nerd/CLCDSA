#include<stdio.h>
int main(){
  long long int n,a,b,i,j,s=51,t=0;
  long long int v[50],temp,sum=0,cnt=1;
  scanf("%lld %lld %lld",&n,&a,&b);
  for(i=0;i<n;i++)
    scanf("%lld",&v[i]);
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(v[i]<v[j]){
        temp=v[i];
        v[i]=v[j];
        v[j]=temp;
      }
    }
  }
  for(i=0;i<a;i++)
    sum+=v[i];
  printf("%lf\n",(double)sum/(double)a);
  for(i=0;i<n;i++){
    if(s==51&&v[i]==v[a-1])
      s=i;
    if(v[i]==v[a-1])
      t=i;
  }
  sum=0;
  if(t==a-1)
    printf("1\n");
  else if(v[0]==v[a-1]){
    for(i=a;i<=b;i++){
      if(i<=t+1){
        cnt=1;
        for(j=0;j<i;j++){
          cnt*=(t+1-j);
          cnt/=j+1;
        }
        sum+=cnt;
      }
    }
    printf("%lld\n",sum);
  }
  else{
    for(j=s;j<a;j++){
      cnt*=(t+1-j);
      cnt/=(j-s+1);
    }
    sum+=cnt;
    printf("%lld\n",sum);
  }
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld",&n,&a,&b);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&v[i]);
     ^