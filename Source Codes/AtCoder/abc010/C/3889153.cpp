#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <iomanip>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) > (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)


int main(){
  cout << fixed << setprecision(12);
    int bx, by, ex, ey, t, v;
    scanf("%d %d %d %d %d %d", &bx, &by, &ex, &ey, &t, &v);
    double move;
    int n,tmpx,tmpy;
    scanf("%d", &n);
    
    REP(i,n){
        scanf("%d %d", &tmpx, &tmpy);
        move = sqrt( ((tmpx - bx) * (tmpx - bx) + (tmpy - by) * (tmpy - by))) + sqrt( ((tmpx - ex) * (tmpx - ex) + (tmpy - ey) * (tmpy - ey)));
        if(v*t>=move){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}