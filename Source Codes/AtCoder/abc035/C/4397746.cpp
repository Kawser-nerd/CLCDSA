#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
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
    int n, q;
    cin >> n >> q;

    vector<int> v(n+1,0);
    int tmpa, tmpb;
    REP(i,q){
        scanf("%d %d", &tmpa, &tmpb);
        v[tmpa - 1]++;
        v[tmpb]--;
    }
    REP(i,n){
        v[i + 1] += v[i];
    }
 
    REP(i,n){
        if(v[i]&1){
            cout << 1;
        }else{
            cout << 0;
        }
    }

    cout << endl;

    return 0;
}