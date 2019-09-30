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

    string s;
    cin>>s;
    vector<int> v(4);
    REP(i,4){
        v[i]=(int)(s[i]-'0');
    }
    int tmp;
    for (int bit = 7; bit >= 0;bit--){
        tmp = v[0];
        REP(i,3){
            if(bit&(int)pow(2,i)){
                tmp += v[i + 1];
            }else{
                tmp -= v[i + 1];
            }
        }
        if(tmp==7){
            cout << v[0];
            REP(i,3){
                if(bit&(int)pow(2,i)){
                    cout << "+";
                }else{
                    cout<<"-";
                }
                cout << v[i + 1];
            }
            cout<<"=7" << endl;
            return 0;
        }
    }

        return 0;
}