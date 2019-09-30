#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <memory>
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

    long long int n,k;
    cin >> n>>k;
    vector<long long int> v(n);
    REP(i, n) { scanf("%lld", &v[i]); }

    long long int tmp = 1;
    long long int result = 0;
    long long int l=0,r=0;
    while(r!=n){
        if(v[r]==0){
            result = n;
            break;
        }else{ 
            tmp *= v[r];
            while(tmp>k&&l<=r){
                tmp /= v[l];
                l++;
            }   
            if(tmp<=k){
                result = max(result,1+ (r - l));
            }
            r++;
        }

    }
    cout << result << endl;


    return 0;
}