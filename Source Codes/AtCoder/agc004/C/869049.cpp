#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
#include <cassert>

#define REP(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef unsigned long ul;
typedef pair<ul, ul> P;

int main() {
    char a[500][501];
    int h, w;
    cin >> h >> w;

    REP(i,h) scanf("%s", a[i]);
    REP(i,h){
        REP(j,w){
            cout << (j==0 || (j != w-1 && i%2==0) ? '#' : a[i][j]);
        }
        cout << endl;
    }
    cout << endl;
    REP(i,h){
        REP(j,w){
            cout << (j==w-1 || (j != 0 && i%2==1) ? '#' : a[i][j]);
        }
        cout << endl;
    }
}