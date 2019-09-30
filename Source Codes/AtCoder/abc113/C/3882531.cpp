#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <map>
#include <ios>
#include <iomanip>
#include <set>
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
    scanf("%d %d\n",&n,&m);
    array<int,100001> ids,idt;
    vector<int> grid[100001];
    
    REP(i,m){
        scanf("%d %d\n",&ids[i],&idt[i]);
 
        grid[ids[i]].push_back(idt[i]);
    }
    
 
    REP(i,n){
        sort(grid[i + 1].begin(), grid[i + 1].end());
    }
 
    
    REP(i,m){
        
        printf("%06d%06d\n", ids[i], (int)(lower_bound(grid[ids[i]].begin(),grid[ids[i]].end(), idt[i])-grid[ids[i]].begin()) + 1);
    }
 
    return 0;
}