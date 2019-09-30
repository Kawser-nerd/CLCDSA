#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)


int main(){

    int n;
    cin>>n;
    if(n%2==0){
        cout<<"NO"<<endl;
        return 0;
    }

    int k=sqrt(n);
    for(int i=3;i<=k;i+=2){
        if(n%i==0){
        cout<<"NO"<<endl;
        return 0;
        }
    }

    cout<<"YES"<<endl;
    return 0;
}