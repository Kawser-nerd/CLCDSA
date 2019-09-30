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
 double  P;
 cin >> P;
 double L, a ,b,c,d;
  L = pow(2,-2.0/3.0);
  a = -log(-P*log(L))/log(L);
  if(a<0)a =0;
 d = a + P*(pow(L,a));
 //a = (log(-1.0/(P*log(pow(2.0,-2.0/3.0)))))/log(c);

 cout <<fixed <<setprecision(11)<<d<<endl;

}
int main(){
  solve();
}