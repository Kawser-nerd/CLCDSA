#include<iostream>
using namespace std;

long mod = 1e9+7,r,c,x,y,d,l;
long pow(long a,long b){return b?pow(a*a%mod,b/2)*(b%2 ? a:1)%mod:1;}
long C(long a,long b)
{
  long ans=1;
  for (long i=1; i<=b; i++) ans=ans*(a-i+1)%mod*pow(i,mod-2)%mod;
  return ans;
}
long f(long a,long b)
{
  if (a<=0 || b<=0 || a*b<d+l) return 0;
  return C(a*b,d+l)*C(d+l,d)%mod;
}
int main()
{
  cin >> r >> c >> x >> y >> d >> l;
  long one=(f(x,y)-(f(x-1,y)*2+f(x,y-1)*2)+(f(x-2,y)+
        f(x,y-2)+f(x-1,y-1)*4)-(f(x-2,y-1)*2+f(x-1,y-2)*2)+f(x-2,y-2))%mod;
  if (one<0) one += mod;
  long ans=0;
  for (int i=x; i<=r; i++) for(int j=y; j<=c; j++) ans=(ans+one)%mod;
  cout << ans << endl;
  return 0;
}