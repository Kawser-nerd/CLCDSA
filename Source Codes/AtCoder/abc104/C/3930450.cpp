#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int d, g, ret=1000000;
  cin >> d >> g;
  g/=100;
  vector<int>p(d), cp(d);
  for(int i=0; i<d; i++){
    int c;
    cin >> p[i] >> c;
    cp[i] = (i+1)*p[i]+c/100;
  }
  for(int i=0; i<(1<<d); i++){
    int cnt=0, ps=0, mi=0;
    for(int j=0; j<d; j++){
      if(i&(1<<j)){
        cnt+=p[j];
        ps+=cp[j];
      }
      else mi=j;
    }
    if(ps>=g)ret=min(ret, cnt);
    else {
      int inc = (g-ps)%(mi+1)==0 ? (g-ps)/(mi+1): (g-ps)/(mi+1)+1;
      if(inc<p[mi])ret=min(ret, cnt+inc);
    }
  }
  cout << ret;
  return 0;
}