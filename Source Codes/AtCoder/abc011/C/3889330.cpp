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

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if(n==a||n==b||n==c){
        cout << "NO" << endl;
        return 0;
    }
    vector<bool> v(n + 1,0);
    v[n] = true;
    REP(i,100){
        REP(j,n+1-i){
            FOR(k,1,4){
                
                if(j-k>=0){
                    if(j-k!=a&&j-k!=b&&j-k!=c&&v[j]&&!v[j-k]){
                        v[j - k] = true;

                    }
                }
            }
        }
    }

    if(v[0]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}