#include <iostream>
#include <vector>
#include <string>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

int main(){
    long long int n;
    cin >> n;

    if((n%((n/1000000000)+((n/100000000)%10)+((n/10000000)%10)+
    ((n/1000000)%10)+((n/100000)%10)+((n/10000)%10)+
    ((n/1000)%10)+((n/100)%10)+((n/10)%10)+n%10))==0){
        cout << "Yes" << endl;

    }else{
        cout << "No" << endl;
    }

    return 0;
}