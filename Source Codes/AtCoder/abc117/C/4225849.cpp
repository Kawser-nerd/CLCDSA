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
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) > (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr int inf= numeric_limits<int>::max()-5;
constexpr long long int mod = 1000000007;

int main(){
    int n,m;
    cin >> n >> m;
    if(n>=m){
        cout << 0 << endl;
        return 0;
    }else{
        vector<int> v(m);
        REP(i,m){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        vector<int> distances(m - 1);
        REP(i, m-1){
            distances[i] = v[i + 1] - v[i];
        }
        sort(distances.begin(), distances.end(),greater<int>());
        int result = v[m-1]-v[0];
        REP(i,n-1){
            result -= distances[i];
        }
        cout << result << endl;
    }

    return 0;
}