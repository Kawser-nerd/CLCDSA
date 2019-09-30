#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include<queue>
#include <sstream>
#include <set>
const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};
const int INF = 1e9;
#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define SORT(a) sort(a.begin(),a.end())
using namespace std;
int main(){
    string S;
    cin >> S;
    S+="X";
    int size = S.size();

    for(int i=0;i<size;i++){
        char x = S[i];
        if(x =='X') break;
        int cnt = 1;
        for(int j= i+1;j<size+1;j++){
            if(S[j]==x) cnt ++;
            else{
                i=j-1;
                cout << x << cnt;
                break;
            }
        }
    }

    cout << endl;
}