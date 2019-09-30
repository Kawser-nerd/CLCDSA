#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include<queue>
#include <set>
const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};
const int INF = 1e9;
#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define SORT(a) sort(a.begin(),a.end())
using namespace std;
int main(){
    int N;
    cin >> N;
    
    map <int , int> m;

    REP(i,N){
        int a;
        cin >> a;
        m[a] ++;
    }
    int sum =0;
    

    for(auto x:m){
        sum += x.second -1;
    }
    

    cout << sum << endl;

}