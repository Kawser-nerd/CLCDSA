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

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(){

    int n, x;
    scanf("%d %d", &n, &x);
    vector<int> v(n);
    
    REP(i,n){
        scanf("%d", &v[i]);
        v[i] -= x;
    }
    

   
    int result = gcd(v[0],v[1]);
    FOR(i,2,n){
        result = gcd(result, v[i]);
    }
    cout << abs(result) << endl;

    return 0;
}