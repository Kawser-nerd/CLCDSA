#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <map>
#include <iomanip>
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
int vx [4]= {1,0,-1,0};
int vy [4]= {0,1,0,-1};
using namespace std;
int m [11][11];
int dp [11][11];
double L,X,Y,S,D;
void init(){


}
void solve(){
  cin >> L >> X >> Y >>S >> D;
  double t1,t2,t3,t4,res;
  if(S>D){
    //??
     t1= (D+L-S)/(X+Y);
    if(Y-X!=0){
    t2 = (S-D)/(Y-X);
  }else t2= -1;
    //???
    if(t2 <0)res = t1;
    else res = min (t1,t2);
  }else if(S<=D){
    t3 = (D-S)/(X+Y);
    if(X!=Y)t4 = (L-D+S)/(Y-X);
    else t4 = -1;
    if(t4 < 0) res = t3;
    else res = min(t3,t4);
  }
  cout << setprecision(8)
   << res <<endl;

}
int main(){
  solve();
}