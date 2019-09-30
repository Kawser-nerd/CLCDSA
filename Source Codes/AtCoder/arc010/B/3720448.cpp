#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <array>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)


int main(){

    int n;
    cin >> n;
    vector<int> add_pub_h(n);
    array<int, 12> day_num_of_month{0,31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

    {
        pair<int, int> tmp;
        REP(i,n){
            scanf("%d/%d", &tmp.first,&tmp.second);
            add_pub_h[i] = day_num_of_month[tmp.first-1] + tmp.second-1;
        }
    }

    sort(add_pub_h.begin(), add_pub_h.end());//?????

    array<bool, 366> days{1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0,0,0,0,0,1,
                          1,0};
    REP(i,n){
        while(days[add_pub_h[i]]&&add_pub_h[i]!=365){
            add_pub_h[i]++;
        }
        days[add_pub_h[i]] = true;
    }

    int result = 0, con_h = 0;
    REP(i,366){
        if(days[i]){
            con_h++;
            result = max(result, con_h);
        }else{
            con_h = 0;
        }
    }
    cout << result << endl;
    return 0;
}