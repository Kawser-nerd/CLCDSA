#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <set>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl
 
//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) > (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)
 
constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr int inf= numeric_limits<int>::max()-5;
 
int main(){
    int n;
    scanf("%d",&n);
    set<int> s;
    int tmp;
    REP(i,n){
        scanf("%d",&tmp);
        while((tmp%2==0)){
            tmp/=2;
        }
        s.insert(tmp);
    }
 
    printf("%lu\n", s.size());
    return 0;
}