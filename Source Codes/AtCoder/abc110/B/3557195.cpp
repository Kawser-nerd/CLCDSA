#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl
 
//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)
 
int main(){
 
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> xs(n), ys(m);
 
    REP(i,n){
        cin >> xs[i];
        if(xs[i]>=y){
            cout << "War" << endl;
            return 0;
        }
    }
    int x_border = max(x, *max_element(xs.begin(), xs.end()));
 
    REP(i,m){
        cin >> ys[i];
        if(ys[i]<=x_border){
            cout << "War" << endl;
            return 0;
        }
    }
 
    cout << "No War" << endl;
 
 
    return 0;
}