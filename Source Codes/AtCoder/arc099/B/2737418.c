#include<stdio.h>

long long int s(long long int n){
  if(n==0)
    return 0;
  return n%10+s(n/10);
}

long long int f(long long int n){
  long long int box[136],i,num,ans;
  double mina;
  num=s(n);
  ans=n;
  mina=(double)n/num;
  num=n;
  if(num%10<9)
    num+=1;
  else if(num%100<99)
    num+=10;
  else if(num%1000<999)
    num+=100;
  else if(num%10000<9999)
    num+=1000;
  else if(num%100000<99999)
    num+=10000;
  else if(num%1000000<999999)
    num+=100000;
  else if(num%10000000<9999999)
    num+=1000000;
  else if(num%100000000<99999999)
    num+=10000000;
  else if(num%1000000000<999999999)
    num+=100000000;
  else if(num%10000000000<9999999999)
    num+=1000000000;
  else if(num%100000000000<99999999999)
    num+=10000000000;
  else if(num%1000000000000<999999999999)
    num+=100000000000;
  else if(num%10000000000000<9999999999999)
    num+=1000000000000;
  else if(num%100000000000000<99999999999999)
    num+=10000000000000;
  else if(num%1000000000000000<999999999999999)
    num+=100000000000000;
  for(i=s(n)+1;i<=135;i++){
    if((double)num/i<mina){
      mina=(double)num/i;
      ans=num;
    }
    if(num%10<9)
    num+=1;
  else if(num%100<99)
    num+=10;
  else if(num%1000<999)
    num+=100;
  else if(num%10000<9999)
    num+=1000;
  else if(num%100000<99999)
    num+=10000;
  else if(num%1000000<999999)
    num+=100000;
  else if(num%10000000<9999999)
    num+=1000000;
  else if(num%100000000<99999999)
    num+=10000000;
  else if(num%1000000000<999999999)
    num+=100000000;
  else if(num%10000000000<9999999999)
    num+=1000000000;
  else if(num%100000000000<99999999999)
    num+=10000000000;
  else if(num%1000000000000<999999999999)
    num+=100000000000;
  else if(num%10000000000000<9999999999999)
    num+=1000000000000;
  else if(num%100000000000000<99999999999999)
    num+=10000000000000;
  else if(num%1000000000000000<999999999999999)
    num+=100000000000000;
  }
  return ans;
}

int main(){
  long long int k,ans,i;
  scanf("%lld",&k);
  ans=1;
  for(i=0;i<k;i++){
    printf("%lld\n",ans);
    ans=f(ans+1);
  }
} ./Main.c: In function ‘main’:
./Main.c:87:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&k);
   ^