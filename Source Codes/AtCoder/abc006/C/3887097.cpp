#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) > (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)


int main(){

    int n,m;
    scanf("%d %d",&n,&m);
    if(m<2*n||4*n<m){
        printf("-1 -1 -1\n");
    }else{
        int a, b, c;
        if(3*n<m){
            a = 0;
            c = m - 3 * n;
            b = n - c;
        }else if(3*n>m){
            c = 0;
            a =  3 * n-m;
            b = n-a;
        }else {
            b = m / 3;
            a = c = 0;
        }
        printf("%d %d %d\n", a, b, c);
    }
    
    return 0;
}