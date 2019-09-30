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

bool depth_search(vector<vector<int>> &g, int num,int depth){
    if(depth==g.size()){
        return num == 0;
    }else{

        REP(i,g[depth].size()){
            if(depth_search(g,num^g[depth][i],depth+1)){
                return true;
            }

        }
        return false;
    }
};

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    vector<vector<int>> grid(n, vector<int>(k));
    REP(i,n){REP(j,k){
            scanf("%d", &grid[i][j]);
    }}
    if(depth_search(grid, 0, 0)){
        printf("Found\n");
    }else{
        printf("Nothing\n");
    }
    return 0;
}