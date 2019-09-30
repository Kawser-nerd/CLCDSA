#include<iostream>
using namespace std;

struct Pair
{
  int a;
  int b;
};

int counter =0;

Pair fib(int k)
{
  if(k==1){return Pair{1,1};}
  if(k==2){return Pair{1,2};}
  int a=1, b=1;
  int c;
  for(int i=0;i<k-1;++i)
  {
    c=a+b;
    a=b;
    b=c;
  }
  Pair res;
  res.a=a;
  res.b=b;
  return res;
}

int gcd(int a, int b)
{
  if(b==0){return 0;}
  counter++;
  return gcd(b,a%b);
}
int main()
{
  int a,b,k;
  //cin >> a>> b;
  cin >> k;
  Pair out = fib(k);
  cout << out.a << " " << out.b << endl;
  //gcd(out.a,out.b);
  //cout << counter << endl;
  return 0;
}