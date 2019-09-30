#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)


int main(){

    int r,c,d;
    cin>>r>>c>>d;
    bool check_flag=!(d%2);
    int tmp,result=-1;
    REP(i,r){
        REP(j,c){
            cin>>tmp;
            if(check_flag && (i+j)<=d){
                result=max(result,tmp);
            }


            check_flag = !check_flag;
        }
        check_flag=(i%2)*(!(d%2))+(!(i%2))*(d%2);
    }

    cout<<result<<endl;

    return 0;
}