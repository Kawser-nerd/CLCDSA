#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<vector>
#include<cassert>

using namespace std;

void out_bin(long int v)
{
  if(v != 0){
    out_bin(v>>1);
    cout<<(v & 1);
  }
}

void do_case(void)
{
  long int qbits[20];
  int nq = 0;

  char s[61];
  cin>>s;

  int i;
  for(i=0;s[i] != '\0';++i){
    if(s[i] == '?') {
      qbits[nq++] = i;
      s[i] = '0';
    }
  }
  for(int j=0;j<nq;++j){
    qbits[j] = 1UL<<i - qbits[j] - 1;
  }

  long int v = strtol(s, NULL, 2);

  for(long int j=0;j<(1L<<nq);++j){
    long int test = v;
    for(int k=0;k<nq;++k){
      if(j & (1<<k)) {
        test += qbits[k];
      }
    }
    long int x = sqrt((double)test) - 1;
    assert(x*x <= test);
    while(x*x < test) ++x;
    if(x*x == test) {
      out_bin(test);
      cout<<endl;
      return;
    }
  }
}

int main()
{
  freopen("input.data", "r", stdin);
  //freopen("output.data", "r", stdout);

  int cases;
  cin>>cases;
  int i = 1;
  do{
    printf("Case #%d: ", i);
    do_case();
  }while(++i <= cases);

  return 0;
}
