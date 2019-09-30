#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<iostream>
#include<cassert>

using namespace std;

unsigned long gcd(unsigned long a, unsigned long b)
{
  if(a < b) return gcd(b, a);
  if(b == 0) return a;
  return gcd(b, a%b);
}

unsigned int a[101];

void do_case(void)
{
  unsigned long N,PD,PG;

  cin>>N>>PD>>PG;

  if(PD > 0 && PG == 0) {
    cout<<"Broken\n";
    return;
  }
  if(PD < 100 && PG == 100) {
    cout<<"Broken\n";
    return;
  }

  if(N < a[PD]) {
    cout<<"Broken\n";
    return;
  }else{
    cout<<"Possible\n";
    return;
  }
}

int main()
{
  freopen("input.data", "r", stdin);
  //freopen("output.data", "r", stdout);

  for(int i=1;i<=100;++i){
    assert(100%gcd(100, i) == 0);
    a[i] = 100/gcd(100, i);
  }

  int cases;
  scanf("%d\n", &cases);
  int i = 1;
  do{
    printf("Case #%d: ", i);
    do_case();
  }while(++i <= cases);

  return 0;
}
