#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define MAX_N 1000
#define INF 10000000000

int N;
int coordinate[MAX_N][3];

bool C(double t){
  double ux=INF, lx=-INF, uy=INF, ly=-INF;
  rep(i, N){
    ux = min(ux, coordinate[i][0]+t/coordinate[i][2]);
    lx = max(lx, coordinate[i][0]-t/coordinate[i][2]);
    uy = min(uy, coordinate[i][1]+t/coordinate[i][2]);
    ly = max(ly, coordinate[i][1]-t/coordinate[i][2]);
  }
  if(ux>=lx && uy>=ly)return true;
  else return false;
}

double solve(double u, double l){
  if(abs(u-l) < pow(10.0, -5.0)) return (u+l)/2;
  if(C((u+l)/2))return solve((u+l)/2, l);
  else return solve(u, (u+l)/2);
}

int main(){
  scanf("%d", &N);
  double x=0, y=0, c=0;
  double min_x = INF, max_x = -INF, min_y = INF, max_y = -INF;
  rep(i, N){
    scanf("%d %d %d", &coordinate[i][0], &coordinate[i][1], &coordinate[i][2]);
  }

  printf("%.5lf\n", solve(INF, 0));
  return 0;
}