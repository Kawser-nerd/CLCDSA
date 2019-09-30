#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <set>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)


int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    REP(i,n){cin >> v[i];}
    
    int l=0, r=0,result=1;
    set<int> s;

    while(r<n){
    
        while(s.find(v[r])!=s.end()){
            s.erase(v[l]);
            l++;
        }
            
        s.insert(v[r]);
        result = max(result, r - l + 1);
        r++;
        
    }

    cout << result << endl;
    return 0;
}