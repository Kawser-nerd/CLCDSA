#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)


int main(){

    int n;
    cin>>n;
    vector<int> top;
    n--;
    int tmp;
    cin>>tmp;
    top.push_back(tmp);
    int min_where,min_weight=111000111;
    while(n--){
        cin >> tmp;
        REP(i,top.size()){
            if(tmp<=top[i]&&top[i]<min_weight){
                min_where = i;
                min_weight = top[i];
            }
        }
        if(min_weight==111000111){
            top.push_back(tmp);
        }else{
            top[min_where] = tmp;
            min_weight = 111000111;
        }
    }
    cout << top.size() << endl;
    return 0;
}