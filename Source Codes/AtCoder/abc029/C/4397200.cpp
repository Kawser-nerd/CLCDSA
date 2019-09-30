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

void bf(int n,vector<char> s){

    REP(i, n) { cout << s[i]; }
    cout<<endl;
    s[n-1]++;
    DEFOR(i,n,0){
        if(s[i]=='d'){
            if(i!=0){
                s[i] = 'a';
                s[i - 1]++;
                
            }else{
                return;
            }
        }
        
    }
    bf(n, s);
}



int main(){

    int n;
    cin>>n;

    vector<char> s(n);
    REP(i,n){s[i]='a';}

    bf(n,s);

    return 0;
}