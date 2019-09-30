#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<vector>
#include<cassert>

using namespace std;

const unsigned int MAX=10000000;
bool prime[MAX+1];
vector<unsigned long> p;

void find_prime(void)
{
  prime[0] = false;
  prime[1] = false;
  for(int i=2;i<=MAX;++i){
    prime[i] = true;
  }
  for(int i=2;i<=sqrt(MAX);++i){
    if(!prime[i]) continue;
    for(int j=i*i;j<=MAX;j+=i) prime[j] = false;
  }
  for(unsigned int i=2;i<=MAX;++i){
    if(prime[i]) p.push_back(i);
  }
  //  cout<<p.size()<<'\n';
}

int intlog(unsigned long p, unsigned long n)
{
  assert(p != 0);
  int i=0;
  while(n >= p){
    n /= p;
    ++i;
  }
  return i;
}

void do_case(void)
{
  unsigned long N;
  cin>>N;
  if(N == 1) {
    cout<<"0\n";
    return;
  }

  unsigned int i=0;
  unsigned long tmax = 1;
  unsigned long tmin = 0;
  while(p[i]*p[i] <= N){
    ++tmin;
    tmax += intlog(p[i], N);
    ++i;
  }
  cout<<tmax - tmin<<endl;
}

int main()
{
  freopen("input.data", "r", stdin);
  //freopen("output.data", "r", stdout);

  find_prime();

  int cases;
  cin>>cases;
  int i = 1;
  do{
    printf("Case #%d: ", i);
    do_case();
  }while(++i <= cases);

  return 0;
}
