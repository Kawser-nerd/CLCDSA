#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <cmath>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)


int main(){

    int n;
    cin >> n;
    vector<int> meats(n);
    REP(i,n){cin >> meats[i];}

    int result=accumulate(meats.begin(),meats.end(),0),
    acc_half=(result-1)/2,
    end_num = (int)pow(2, n),result_candidate=0,bit_tmp,pow_tmp;
    
    for (int i = 1; i <= end_num; i++){
        REP(j,n){
            pow_tmp = (int)pow(2, j);
            bit_tmp = i & pow_tmp;
            //cout << i << " " << j <<" "<<bit_tmp << endl;
            if(bit_tmp==pow_tmp){
                result_candidate += meats[j];

                
            }
            //cout << result_candidate << endl;
        }

        if(result_candidate>acc_half){
            result = min(result, result_candidate);
        }
        result_candidate = 0;
    }

    cout << result << endl;



    return 0;
}