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

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    vector<bool> v(301,false);
    v[a+b+c]=true;
    v[a+b+d]=true;
    v[a+b+e]=true;
    v[a+c+d]=true;
    v[a+c+e]=true;
    v[a+d+e]=true;
    v[b+c+d]=true;
    v[b+c+e]=true;
    v[b+d+e]=true;
    v[c+d+e]=true;
    int count = 0;
    DEFOR(i,301,0){
        if(v[i]){
            count++;
        }
        if(count==3){
            cout << i << endl;
            break;
        }
    }


    return 0;
}