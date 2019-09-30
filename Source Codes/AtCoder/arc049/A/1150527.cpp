#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

const int MAX_N = 1000000;

int main() {
    string S;
    int A[4];
    cin >> S;
    cin >> A[0] >> A[1] >> A[2] >> A[3];

    rep(i, S.length()+1){
        if(i == A[0]) cout << '"';
        if(i == A[1]) cout << '"';
        if(i == A[2]) cout << '"';
        if(i == A[3]) cout << '"';
        if(i < S.length()) cout << S[i];
    }
    cout << endl;
}