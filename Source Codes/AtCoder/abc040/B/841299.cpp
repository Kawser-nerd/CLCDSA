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
    int n;
    cin >> n;

    int res=1e9;

    if (n==1){
        res = 0;
    } else {
        for (int a=n; a>0; a--){
            int c;
            for (int b=1; b<n; b++){
                if (n < a*b) break;
                c = (n-a*b)+abs(a-b);
                res = min(res, c);
            }
        }
    }

    cout << res << endl;
}