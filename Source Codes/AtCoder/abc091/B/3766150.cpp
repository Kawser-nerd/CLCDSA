#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

int main() {

    int N,M;
    cin>>N;
    vector<string> s(N);
    map<string, int> S,T;
    FOR(i,0,N){
        string u;
        cin>>u;
        s[i]=u;
        S[u]++;
    }
    cin>>M;
    FOR(i,0,M){
        string t;
        cin>>t;
        T[t]++;
    }
    int  ans=0;
    FOR(i,0,N){
        ans=max(ans,S[s[i]]-T[s[i]]);
    }
    cout <<ans <<"\n";
}