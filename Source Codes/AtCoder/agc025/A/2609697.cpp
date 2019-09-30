#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

int main(){

    int n,result=0;
    cin >> n;

    if(n==10||n==100||n==1000||n==10000||n==100000){
        cout << 10 << endl;
        return 0;
    }
    while(n%10!=n){
        result += n % 10;
        n /= 10;
    }
    result += n;
    cout << result << endl;
    

    return 0;
}