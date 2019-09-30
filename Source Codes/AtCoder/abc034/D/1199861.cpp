#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;
#define DEBUG(X) cout<<__LINE__<<" "<<#X<<": "<<X<<endl;
#define sci(x) int x;scanf("%d",&x);
#define scii(x, y) int x,y;scanf("%d%d",&x,&y);
#define REP(i, y) for(int i=0;i<y;i++)
const int MAX_N=1001;
// ABC034 D ???
int K,N;
int w[MAX_N];
int p[MAX_N];
bool C(double x){
  double t[N];
  REP(i,N) t[i]=(p[i]-x)*w[i];
  sort(t,t+N);
  double sum=0;
  REP(j,K) sum+=t[N-j-1];
  return sum>=0;
}

int main() {
  scanf("%d%d",&N,&K);
  REP(i,N){
    scanf("%d%d",&w[i],&p[i]);
  }
  double lb=0, ub=100;
  for(int i=0;i<100;i++){
    double mid=(lb+ub)/2;
    if(C(mid)) lb=mid;
    else ub = mid;
  }
  printf("%.9f\n",ub);
}