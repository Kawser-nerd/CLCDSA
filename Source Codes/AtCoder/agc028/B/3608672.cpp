#include<cstdio>
using namespace std;

long gyaku(long n){
  long p[31],ans=1;
  p[0]=n;
  ans=n;
  for(int i=1;i<31;i++){
    p[i]=p[i-1]*p[i-1]%1000000007;
    if(i==2||i==9||i==11||i==14||i==15||i==17||i==19||i==20||i==23||i==24||i==25||i==27||i==28||i==29)
      ans=ans*p[i]%1000000007;
  }
  return ans;
}

int main(){
  long n,a[100010],ans=0,sum[100000]={};
  scanf("%ld",&n);
  for(long i=0;i<n;i++)
    scanf("%ld",&a[i]);
  sum[0]=1;
  for(int i=1;i<n;i++)
    sum[i]=(sum[i-1]+gyaku(i+1))%1000000007;
  for(int i=0;i<n;i++){
    ans+=a[i]*(sum[i-0]+sum[n-1-i]-1)%1000000007;
    ans%=1000000007;
  }
  for(int i=1;i<=n;i++){
    ans*=i;
    ans%=1000000007;
  }
  printf("%ld\n",ans);
}