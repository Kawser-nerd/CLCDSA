#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>

using namespace std;

unsigned long b[1000];
unsigned long e[1000];
unsigned long w[1000];

unsigned long wlen[101];

void do_case(void)
{
  unsigned long X, S, R, t, N;
  cin>>X>>S>>R>>t>>N;

  for(int i=0;i<N;++i){
    cin>>b[i]>>e[i]>>w[i];
  }
  for(int i=0;i<=100;++i) wlen[i] = 0;

  unsigned long tot = 0;
  for(int i=0;i<N;++i){
    tot += e[i] - b[i];
    wlen[w[i]] += e[i] - b[i];
  }
  wlen[0] = X - tot;

  double ans = 0.0;
  double time = (double)t;
  bool walk = false;
  for(int i=0;i<=100;++i){
    if(walk){
      ans += (double)wlen[i]/(double)(i+S);
      continue;
    }
    double runtime = (double)wlen[i]/(double)(i+R);
    if(runtime < time){
      ans += runtime;
      time -= runtime;
    }else{
      double len = time*(double)(i+R);
      ans += time;
      time = 0.0;
      ans += ((double)wlen[i] - len)/(i+S);
      walk = true;
    }
  }
  printf("%17.10e\n", ans);
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
