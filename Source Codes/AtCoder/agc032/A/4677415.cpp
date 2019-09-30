#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <memory>
#include <list>
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
    int n;
    cin>>n;
    int tmp;
    list<int> ls;
    REP(i,n){
        cin>>tmp;
        if(tmp>i+1){
            cout << -1 << endl;
            return 0;
        }else{
            ls.push_front(tmp);
        }
    }

    auto itr = ls.begin();
    list<int> result;

    DEFOR(i,n,0){
        tmp = i+1;
        for (itr = ls.begin(); itr != ls.end();itr++){
           
            if(*itr==tmp){
                result.push_front(*itr);
                ls.erase(itr);
                break;
            }
            tmp--;
        }
    }

    for(auto x:result){
        cout << x << endl;
    }

    return 0;
}