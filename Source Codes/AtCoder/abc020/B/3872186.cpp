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
    int a,b;
    cin >> a>> b;

    string S;
    S += to_string(a)+to_string(b);

    int ans = stoi(S);

    cout << ans*2<<endl;


}