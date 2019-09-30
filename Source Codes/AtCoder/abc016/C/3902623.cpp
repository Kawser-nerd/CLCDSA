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

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr int inf= numeric_limits<int>::max()-5;
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<bool>> grid(n, vector<bool>(n,0));
    int tmpx, tmpy;
    REP(i,m){
        scanf("%d%d", &tmpx, &tmpy);
        grid[tmpx - 1][tmpy - 1] = true;
        grid[tmpy - 1][tmpx - 1] = true;
    }


    vector<bool> v(n, 0);
    REP(i,n){
        REP(j,n){
            REP(k,n){
                if(i!=j&&j!=k&&k!=i){
                    if(grid[i][j]&&grid[j][k]&&!grid[k][i]){
                        v[k] = true;
                    }
                }
            }
        }
        printf("%d\n",(int)accumulate(v.begin(),v.end(),0));
        v = vector<bool>(n, 0);
    }


    return 0;
}