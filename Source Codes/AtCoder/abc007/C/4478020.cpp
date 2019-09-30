#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <memory>
#include <queue>
#include <tuple>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin)-1; (LoopVariable) >= (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr int inf= numeric_limits<int>::max()-5;
constexpr long long int mod = 1000000007;

int main(){

    int r,c,sy,sx,gy,gx;
    cin >> r >> c >> sy >> sx >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;
    vector<vector<int>> grid(r, vector<int>(c));
    char tmp;
    REP(i,r){REP(j,c){

        cin >> tmp;
        if (tmp == '.'){
                grid[i][j] = -1;
        }else{
            grid[i][j] = -2;
        }

    }}


    queue <tuple<int, int, int>> q;
    q.push(make_tuple(sy, sx, 0));
    grid[sy][sx] = 0;
    while(!q.empty()){
        if(get<0>(q.front())==gy&&get<1>(q.front())==gx){
            cout << get<2>(q.front()) << endl;
            break;
        }else{
  
            if(grid[get<0>(q.front())-1][get<1>(q.front())]==-1){
                grid[get<0>(q.front()) - 1][get<1>(q.front())] = get<2>(q.front()) + 1;
                q.push(make_tuple(get<0>(q.front()) - 1, get<1>(q.front()), get<2>(q.front()) + 1));
            }

            if(grid[get<0>(q.front())+1][get<1>(q.front())]==-1){
                grid[get<0>(q.front()) + 1][get<1>(q.front()) ] = get<2>(q.front()) + 1;
                q.push(make_tuple(get<0>(q.front()) + 1, get<1>(q.front()), get<2>(q.front()) + 1));
            }
        
            if(grid[get<0>(q.front())][get<1>(q.front())-1]==-1){
                grid[get<0>(q.front()) ][get<1>(q.front()) - 1] = get<2>(q.front()) + 1;
                q.push(make_tuple(get<0>(q.front()) , get<1>(q.front()) - 1, get<2>(q.front()) + 1));
            }

            if(grid[get<0>(q.front())][get<1>(q.front())+1]==-1){
                grid[get<0>(q.front()) ][get<1>(q.front()) + 1] = get<2>(q.front()) + 1;
                q.push(make_tuple(get<0>(q.front()) , get<1>(q.front()) + 1, get<2>(q.front()) + 1));
            }

            q.pop();

        }
    }



    return 0;
}